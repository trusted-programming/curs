mod cli;
mod extractor;
mod extractor_chooser;
mod language;
use anyhow::{bail, Context, Result};
use cli::{Invocation, QueryFormat, QueryOpts};
use crossbeam::channel;
use language::Language;
use rayon::iter::{IntoParallelRefIterator, ParallelIterator};
use rust_bert::pipelines::common::{ConfigOption, ModelType, TokenizerOption};
use rust_bert::pipelines::sequence_classification::SequenceClassificationOption;
use rust_bert::resources::{LocalResource, ResourceProvider};
use rust_tokenizers::tokenizer::TruncationStrategy;
use std::env;
use std::io::{self, BufWriter, Write};
use std::path::PathBuf;
use tch::kind::Kind::Int64;
use tch::{nn, no_grad, Device, Kind, Tensor};
use tree_sitter::Parser;

#[global_allocator]
static ALLOCATOR: bump_alloc::BumpAlloc = bump_alloc::BumpAlloc::new();
fn main() {
    let mut buffer = BufWriter::new(io::stdout());

    if let Err(error) = try_main(env::args().collect(), &mut buffer) {
        if let Some(err) = error.downcast_ref::<io::Error>() {
            // a broken pipe is totally normal and fine. It's what we get when
            // we pipe to something like `head` that only takes a certain number
            // of lines.
            if err.kind() == io::ErrorKind::BrokenPipe {
                std::process::exit(0);
            }
        }

        if let Some(clap_error) = error.downcast_ref::<clap::Error>() {
            // Clap errors (--help or misuse) are already well-formatted,
            // so we don't have to do any additional work.
            eprint!("{}", clap_error);
        } else {
            eprintln!("{:?}", error);
        }

        std::process::exit(1);
    }

    buffer.flush().expect("failed to flush buffer!");
}

fn try_main(args: Vec<String>, out: impl Write) -> Result<()> {
    let invocation = Invocation::from_args(args)
        .context("couldn't get a valid configuration from the command-line options")?;
    match invocation {
        Invocation::DoQuery(query_opts) => {
            do_query(query_opts, out).context("couldn't perform the query")
        }
        Invocation::ShowLanguages => {
            show_languages(out).context("couldn't show the list of languages")
        }
    }
}

fn show_languages(mut out: impl Write) -> Result<()> {
    for language in Language::all() {
        writeln!(out, "{}", language.to_string()).context("couldn't print a language")?;
    }

    Ok(())
}

fn classify(
    config: &ConfigOption,
    extracted_file: &extractor::ExtractedFile,
    model: &SequenceClassificationOption,
    tokenizer: &TokenizerOption,
) -> Result<()> {
    //  Define input
    // Define the cordinate if extraction "id"
    let [mut r1, mut c1, mut r2, mut c2] = [0, 0, 0, 0];
    for extraction in &extracted_file.matches {
        let input_string = format!("{}", extraction.text);
        // extract the coordonate of 'id'
        if extraction.name == "id" {
            r1 = extraction.start.row;
            c1 = extraction.start.column;
            r2 = extraction.end.row;
            c2 = extraction.end.column;
            continue;
        }
        let input = [input_string.replace("unsafe ", " ")];
        //tokenizer
        let tokenized_input =
            tokenizer.encode_list(&input, 512, &TruncationStrategy::LongestFirst, 0);
        let max_len = tokenized_input
            .iter()
            .map(|input| input.token_ids.len())
            .max()
            .unwrap();
        let tokenized_inputs = tokenized_input
            .iter()
            .map(|input| input.token_ids.clone())
            .map(|mut input| {
                input.extend(vec![0; max_len - input.len()]);
                input
            })
            .map(|input| Tensor::of_slice(&(input)))
            .collect::<Vec<_>>();
        let tokenized_masks = tokenized_input
            .iter()
            .map(|input| vec![1; input.token_ids.len()])
            .map(|mut input: Vec<i64>| {
                input.extend(vec![0; max_len - input.len()]);
                input
            })
            .map(|input| Tensor::of_slice(&(input)))
            .collect::<Vec<_>>();

        let device = Device::cuda_if_available();
        // let device = Device::Cpu;
        let input_tensor = Tensor::stack(tokenized_inputs.as_slice(), 0).to(device);
        let (batch_size, sequence_length) = (1, max_len as i64);

        let mask = Tensor::stack(tokenized_masks.as_slice(), 0).to(device);
        let token_type_ids = Tensor::zeros(&[batch_size, sequence_length], (Int64, device));

        let output = no_grad(|| {
            let output = model.forward_t(
                Some(&input_tensor),
                Some(&mask),
                Some(&token_type_ids),
                None,
                None,
                false,
            );
            output.softmax(-1, Kind::Float).detach().to(device)
        });

        // print!("output is ");
        // output.print();
        // println!("\nsigmoid = {:?}", output.sigmoid());
        let label_mapping = config.get_label_mapping().clone();
        let label_indices = output.as_ref().argmax(-1, true).squeeze_dim(1);
        let scores = output
            .gather(1, &label_indices.unsqueeze(-1), false)
            .squeeze_dim(1);
        let label_indices = label_indices.iter::<i64>().unwrap().collect::<Vec<i64>>();
        let scores = scores.iter::<f64>().unwrap().collect::<Vec<f64>>();
        for sentence_idx in 0..label_indices.len() {
            let label_string = label_mapping
                .get(&label_indices[sentence_idx])
                .unwrap()
                .clone();
            println!(
                "{},{},{},{},{},{}(prob={:.2})",
                extracted_file
                    .file
                    .as_ref()
                    .map(|f| f.to_str().unwrap_or("NON-UTF8 FILENAME"))
                    .unwrap_or("NO FILE"),
                r1,
                c1,
                r2,
                c2,
                &label_string,
                scores[sentence_idx]
            );
        }
    }
    Ok(())
}

fn do_query(opts: QueryOpts, mut out: impl Write) -> Result<()> {
    // You might think "why not use ParallelBridge here?" Well, the quick answer
    // is that I benchmarked it and having things separated here and handling
    // their own errors actually speeds up this part of the code by like 20%!
    let items: Vec<ignore::DirEntry> =
        find_files(&opts).context("had a problem while walking the filesystem")?;

    let chooser = opts
        .extractor_chooser()
        .context("couldn't construct a filetype matcher")?;

    let mut extracted_files = items
        .par_iter()
        .filter_map(|entry| {
            chooser
                .extractor_for(entry)
                .map(|extractor| (entry, extractor))
        })
        .map_init(Parser::new, |parser, (entry, extractor)| {
            extractor
                .extract_from_file(entry.path(), parser)
                .with_context(|| {
                    format!("could not extract matches from {}", entry.path().display())
                })
        })
        .filter_map(|result_containing_option| match result_containing_option {
            Ok(None) => None,
            Ok(Some(extraction)) => Some(Ok(extraction)),
            Err(err) => Some(Err(err)),
        })
        .collect::<Result<Vec<extractor::ExtractedFile>>>()
        .context("couldn't extract matches from files")?;

    if opts.sort {
        extracted_files.sort()
    }

    // codebert for rust safe and unsafe
    let config_resource = LocalResource {
        local_path: PathBuf::from(
            PathBuf::from(env!("CARGO_MANIFEST_DIR"))
                .into_os_string()
                .into_string()
                .unwrap()
                + "/.cache/codebert/config.json",
        ),
    };
    let vocab_resource = LocalResource {
        local_path: PathBuf::from(
            PathBuf::from(env!("CARGO_MANIFEST_DIR"))
                .into_os_string()
                .into_string()
                .unwrap()
                + "/.cache/codebert/vocab.json",
        ),
    };
    let merges_resource = LocalResource {
        local_path: PathBuf::from(
            PathBuf::from(env!("CARGO_MANIFEST_DIR"))
                .into_os_string()
                .into_string()
                .unwrap()
                + "/.cache/codebert/merges.txt",
        ),
    };
    let weights_resource = LocalResource {
        local_path: PathBuf::from(
            PathBuf::from(env!("CARGO_MANIFEST_DIR"))
                .into_os_string()
                .into_string()
                .unwrap()
                + "/.cache//codebert/rust_model.ot",
        ),
    };

    let config_path = config_resource.get_local_path()?;
    let vocab_path = vocab_resource.get_local_path()?;
    let merges_path = Some(merges_resource.get_local_path()?);
    let weights_path = weights_resource.get_local_path()?;
    let device = Device::cuda_if_available();
    // let device = Device::Cpu;
    if device == Device::Cpu {
        println!("inference device: cpu");
    } else {
        println!("inference device: cuda");
    }
    let tokenizer = TokenizerOption::from_file(
        ModelType::Roberta,
        vocab_path.to_str().unwrap(),
        merges_path.as_deref().map(|path| path.to_str().unwrap()),
        false,
        None,
        false,
    )?;

    let mut vs = nn::VarStore::new(device);
    let config = ConfigOption::from_file(ModelType::Bert, config_path);
    let model = SequenceClassificationOption::new(ModelType::Roberta, &vs.root(), &config)?;
    // use "?" to load model correctly instead of ".ok()"
    vs.load(weights_path)?;
    match opts.format {
        QueryFormat::Classes => {
            for extracted_file in extracted_files {
                classify(&config, &extracted_file, &model, &tokenizer).ok();
            }
        }

        QueryFormat::Lines => {
            for extracted_file in extracted_files {
                write!(out, "{}", extracted_file).context("could not write lines")?;
            }
        }

        QueryFormat::Json => {
            serde_json::to_writer(out, &extracted_files).context("could not write JSON output")?;
        }
        QueryFormat::JsonLines => {
            for extracted_file in extracted_files {
                writeln!(
                    out,
                    "{}",
                    serde_json::to_string(&extracted_file)
                        .context("could not write JSON output")?
                )
                .context("could not write line")?;
            }
        }

        QueryFormat::PrettyJson => {
            serde_json::to_writer_pretty(out, &extracted_files)
                .context("could not write JSON output")?;
        }
    }

    Ok(())
}

fn find_files(opts: &QueryOpts) -> Result<Vec<ignore::DirEntry>> {
    let mut builder = match opts.paths.split_first() {
        Some((first, rest)) => {
            let mut builder = ignore::WalkBuilder::new(first);
            for path in rest {
                builder.add(path);
            }

            builder
        }
        None => bail!("I need at least one file or directory to walk!"),
    };

    let (root_sender, receiver) = channel::unbounded();

    builder
        .git_ignore(opts.git_ignore)
        .git_exclude(opts.git_ignore)
        .git_global(opts.git_ignore)
        .build_parallel()
        .run(|| {
            let sender = root_sender.clone();
            Box::new(move |entry_result| match entry_result {
                Ok(entry) => match sender.send(entry) {
                    Ok(()) => ignore::WalkState::Continue,
                    Err(_) => ignore::WalkState::Quit,
                },
                Err(_) => ignore::WalkState::Quit,
            })
        });

    drop(root_sender);

    Ok(receiver.iter().collect())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn call(args: &[&str]) -> String {
        let mut bytes = Vec::new();
        try_main(
            args.iter().map(|s| s.to_string()).collect(),
            Box::new(&mut bytes),
        )
        .unwrap();

        String::from_utf8(bytes).unwrap()
    }

    #[test]
    fn lines_output() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "elm",
            "(import_clause)",
            "-f",
            "lines",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-elm/examples",
        ]))
    }

    #[test]
    fn json_output() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "elm",
            "(import_clause)",
            "-f",
            "json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-elm/examples",
        ]))
    }

    #[test]
    fn json_lines_output() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "javascript",
            "(identifier)",
            "-f",
            "json-lines",
            "--sort",
            "vendor/tree-sitter-javascript/examples"
        ]))
    }

    #[test]
    fn pretty_json_output() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "elm",
            "(import_clause)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-elm/examples",
        ]))
    }

    // All languages should have a test that just spits out their entire node
    // tree. We use this to know about changes in the vendored parsers!

    #[test]
    fn all_cpp() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "cpp",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-cpp/examples",
        ]))
    }

    #[test]
    fn all_elm() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "elm",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-elm/examples",
        ]))
    }

    #[test]
    fn all_haskell() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "haskell",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-haskell",
        ]))
    }

    #[test]
    fn all_javascript() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "javascript",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            // note that this doesn't include the entire vendor
            // directory. tree-sitter-javascript vendors a couple of libraries
            // to test things and it makes this test run unacceptably long. I
            // think the slowdown is due to the diffing step; the curs
            // code completes in a reasonable amount of time.
            "vendor/tree-sitter-javascript/test",
        ]))
    }

    #[test]
    fn all_php() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "php",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-php/test/highlight",
        ]))
    }

    #[test]
    fn all_ruby() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "ruby",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-ruby",
        ]))
    }

    #[test]
    fn all_rust() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "rust",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "/vendor/tree-sitter-rust/examples",
        ]))
    }

    #[test]
    fn all_typescript() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "typescript",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            // similar to JavaScript, there is one particular test file in this
            // grammar that's *huge*. It seems to be a comprehensive listing of
            // all the typescript syntax, maybe? Regardless, it makes this test
            // unacceptably slow, so we just look at one particular file. If
            // we see uncaught regressions in this function, we probably will
            // make our own test file with the things we care about.
            "vendor/tree-sitter-typescript/typescript/test.ts",
        ]))
    }

    #[test]
    fn all_elixir() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "elixir",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            "vendor/tree-sitter-elixir",
        ]))
    }
    //rust safe unsafe classify
    #[test]
    fn rust_safe() {
        insta::assert_snapshot!(call(&[
            "curs",
            "-q",
            "rust",
            "(function_item (identifier) @id) @function",
            "--format=classes",
            "--sort",
            "--no-gitignore",
            "data/error.rs",
        ]))
    }
}