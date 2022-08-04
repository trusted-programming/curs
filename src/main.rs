mod cli;
mod extractor;
mod extractor_chooser;
mod language;
use anyhow::{bail, Context, Result};
use cli::{Invocation, QueryFormat, QueryOpts};
use crossbeam::channel;
use language::Language;
use rayon::iter::{IntoParallelRefIterator, ParallelIterator};
use rust_bert::bert::BertConfig;
use rust_bert::pipelines::common::ConfigOption;
use rust_bert::pipelines::common::ModelType;
use rust_bert::resources::{RemoteResource, Resource};
use rust_bert::roberta::RobertaForSequenceClassification;
use rust_bert::Config;
use rust_tokenizers::tokenizer::{MultiThreadedTokenizer, RobertaTokenizer, TruncationStrategy};
use std::env;
use std::io::{self, BufWriter, Write};
use std::path::PathBuf;
use tch::kind::Kind::Int64;
use tch::{nn, no_grad, Device, Tensor};
use tree_sitter::Parser;

#[global_allocator]
static ALLOCATOR: bump_alloc::BumpAlloc = bump_alloc::BumpAlloc::new();
// cargo run --package curs --bin curs -q rust "(_)" error.rs
// cargo test --package curs --bin curs -- tests
//  upda
// bin: ./curs -q rust '(_)' ../../error.rs
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
    config_path: &PathBuf,
    extracted_file: &extractor::ExtractedFile,
    model: &RobertaForSequenceClassification,
    tokenizer: &RobertaTokenizer,
) -> Result<()> {
    //    Define input
    for extraction in &extracted_file.matches {
        let input_string = format!("{}", extraction.text);
        let is_unsafe = input_string.contains("unsafe fn ");
        if is_unsafe {
            print!(
                "{}:{}:{}:{}:{}:",
                extracted_file
                    .file
                    .as_ref()
                    .map(|f| f.to_str().unwrap_or("NON-UTF8 FILENAME"))
                    .unwrap_or("NO FILE"),
                extraction.start.row + 1,
                extraction.start.column + 1,
                extraction.name,
                "Unsafe"
            );
        } else {
            print!(
                "{}:{}:{}:{}:{}:",
                extracted_file
                    .file
                    .as_ref()
                    .map(|f| f.to_str().unwrap_or("NON-UTF8 FILENAME"))
                    .unwrap_or("NO FILE"),
                extraction.start.row + 1,
                extraction.start.column + 1,
                extraction.name,
                "Safe"
            );
        }
        let input = [input_string.replace("unsafe ", " ")];
        let tokenized_input = MultiThreadedTokenizer::encode_list(
            tokenizer,
            &input,
            512,
            &TruncationStrategy::LongestFirst,
            0,
        );
        let max_len = tokenized_input
            .iter()
            .map(|input| input.token_ids.len())
            .max()
            .unwrap();
        // println!("max len = {} > input length = {}", max_len, input[0].len());
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

        let device = Device::Cpu;
        let input_tensor = Tensor::stack(tokenized_inputs.as_slice(), 0).to(device);
        let (batch_size, sequence_length) = (1, max_len as i64);

        //    Forward pass
        let mask = Tensor::stack(tokenized_masks.as_slice(), 0).to(device);
        let token_type_ids = Tensor::zeros(&[batch_size, sequence_length], (Int64, device));
        let output = no_grad(|| {
            model
                .forward_t(
                    Some(&input_tensor),
                    Some(&mask),
                    Some(&token_type_ids),
                    None,
                    None,
                    false,
                )
                .logits
        });
        println!("\nsigmoid = {:?}", output.sigmoid());
        let model_config = ConfigOption::from_file(ModelType::Roberta, config_path);
        let label_mapping = model_config.get_label_mapping().clone();
        let label_indices = output.argmax(-1, true).squeeze_dim(1);
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
            println!("{}: {}", &label_string, scores[sentence_idx]);
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
    let config_resource = Resource::Remote(RemoteResource {
        url: "https://bertrust.s3.amazonaws.com/config.json".into(),
        // url: "config.json".into(),
        cache_subdir: "codebert-base/config".into(),
    });
    let vocab_resource = Resource::Remote(RemoteResource {
        url: "https://huggingface.co/microsoft/codebert-base/resolve/main/vocab.json".into(),
        cache_subdir: "codebert-base/vocab".into(),
    });
    let merges_resource = Resource::Remote(RemoteResource {
        url: "https://huggingface.co/microsoft/codebert-base/resolve/main/merges.txt".into(),
        cache_subdir: "codebert-base/merges".into(),
    });
    let weights_resource = Resource::Remote(RemoteResource {
        url: "https://bertrust.s3.amazonaws.com/rust_model.ot".into(),
        cache_subdir: "codebert-base/model".into(),
    });

    let config_path = &config_resource.get_local_path()?;
    let vocab_path = vocab_resource.get_local_path()?;
    let merges_path = merges_resource.get_local_path()?;
    let weights_path = weights_resource.get_local_path()?;

    let tokenizer = RobertaTokenizer::from_file(
        vocab_path.to_str().unwrap(),
        merges_path.to_str().unwrap(),
        false,
        false,
    )?;

    let mut vs = nn::VarStore::new(Device::cuda_if_available());
    let config = BertConfig::from_file(config_path);
    vs.load(weights_path).ok();
    let model = RobertaForSequenceClassification::new(&vs.root(), &config);

    match opts.format {
        QueryFormat::Classes => {
            for extracted_file in extracted_files {
                classify(config_path, &extracted_file, &model, &tokenizer).ok();
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
            "vendor/tree-sitter-rust/examples",
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
}
