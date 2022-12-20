use crate::query::{ExtractedFile, Language, QueryFormat, QueryOpts};
use anyhow;
use anyhow::{bail, Context, Result};
use crossbeam::channel;
use rayon::iter::{IntoParallelRefIterator, ParallelIterator};
use rust_bert::pipelines::common::{ConfigOption, ModelType, TokenizerOption};
use rust_bert::pipelines::sequence_classification::SequenceClassificationOption;
use rust_bert::resources::{RemoteResource, ResourceProvider};
use rust_tokenizers::tokenizer::TruncationStrategy;
use std::io::Write;
use tch::kind::Kind::Int64;
use tch::{nn, no_grad, Device, Kind, Tensor};
use tree_sitter::Parser;

#[global_allocator]
static ALLOCATOR: bump_alloc::BumpAlloc = bump_alloc::BumpAlloc::new();

/// Display the extracted syntax information of source file
pub fn show_languages(mut out: impl Write) -> Result<()> {
    for language in Language::all() {
        writeln!(out, "{}", language.to_string()).context("couldn't print a language")?;
    }

    Ok(())
}
/// SafeLanguageModel for classifying safe and unsafe keywords
pub struct SafeLanguageModel {
    /// TokenizerOption for safe model
    tokenizer: TokenizerOption,
    /// Configuration for language query
    opts: QueryOpts,
    /// Configuration for safe model
    config: ConfigOption,
    /// safe model
    model: SequenceClassificationOption,
}
impl SafeLanguageModel {
    /// Build a new `SafeLanguageModel`
    ///
    /// # Arguments
    ///
    /// * `opts` - `QueryOpts` object containing the detected language and file information
    ///
    /// # Returns
    ///
    /// * `SafeLanguageModel` object
    ///
    /// # Example
    ///
    /// ```no_run
    /// # fn main() -> anyhow::Result<()> {
    /// use rust_hero::query::Invocation;
    /// use rust_hero::safe::SafeLanguageModel;
    ///
    /// let args=[
    ///        "rust_hero",
    ///        "-q",
    ///        "rust",
    ///        "(function_item (identifier) @id) @function",
    ///        "--format=classes",
    ///        "--sort",
    ///        "--no-gitignore",
    ///        "data/error.rs",
    ///    ]
    /// .iter()
    /// .map(|s| s.to_string())
    /// .collect();
    /// let invocation = Invocation::from_args(args)?;
    /// match invocation {
    ///    Invocation::DoQuery(query_opts) => {
    ///         let safe_model = SafeLanguageModel::new(query_opts)?;
    ///    }
    ///     _ => (),
    /// }
    /// # Ok(())
    /// # }
    /// ```
    /// # Tips
    /// If runtime accident occurs:"Downloading <https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/rust_model.ot> [477.81MiB].......memory allocation of 32768 bytes failed memory allocation of Aborted"
    /// you may set the network proxy for beteer downloading models from huggingface.co
    pub fn new(opts: QueryOpts) -> Result<SafeLanguageModel> {
        // load model from huggingface.co
        let config_resource = RemoteResource::from_pretrained((
            "codebert-curs/config",
            "https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/config.json",
        ));
        let vocab_resource = RemoteResource::from_pretrained((
            "codebert-curs/vocab",
            "https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/vocab.json",
        ));
        let merges_resource = RemoteResource::from_pretrained((
            "codebert-curs/merges",
            "https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/merges.txt",
        ));
        let mut weights_resource = RemoteResource::from_pretrained((
            "codebert-curs/model",
            "https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/rust_model_0.6.ot",
        ));
        if std::path::Path::new("rust_model_0.6.ot").exists() {
            weights_resource = RemoteResource::from_pretrained((
                "codebert-curs/model",
                "rust_model_0.6.ot",
            ));
        }
        // you can also load model from local dir
        // use std::path::PathBuf;
        //use rust_bert::resources::LocalResource;
        //
        // let weights_resource = LocalResource {
        //     local_path: PathBuf::from(
        //         PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        //             .into_os_string()
        //             .into_string()
        //             .unwrap()
        //             + "/.cache/model/rust_model_0.6.ot",
        //     ),
        // };
        let config_path = config_resource.get_local_path()?;
        let vocab_path = vocab_resource.get_local_path()?;
        let merges_path = Some(merges_resource.get_local_path()?);
        /* if runtime accident occurs:"Downloading https://huggingface.co/Vincent-Xiao/codebert-curs/resolve/main/rust_model.ot [477.81MiB]
            .......memory allocation of 32768 bytes failed
            memory allocation of Aborted"
            you may set the network proxy for beteer downloading models from huggingface.co
        */

        let weights_path = weights_resource.get_local_path()?;
        let device = Device::cuda_if_available();
        // let device = Device::Cpu;
        // if device == Device::Cpu {
        //     println!("inference device: cpu");
        // } else {
        //     println!("inference device: cuda");
        // }
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
        Ok(SafeLanguageModel {
            tokenizer,
            opts,
            config,
            model,
        })
    }

    /// Get the private `QueryOpts` of`SafeLanguageModel`
    pub fn get_opt(&self) -> &QueryOpts {
        &self.opts
    }

    /// Find the language (such as Rust) source file if you give a directory arg instead of one specific source file
    pub fn search_files(&self) -> Result<Vec<ignore::DirEntry>> {
        let opts = &self.opts;
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

    /// Predict whether the fragment program containing unsafe keyword is `safe` or `unsafe`
    /// `safe` indicates that he unsafe keyword could be removed;
    ///  `unsafe` represents that he unsafe keyword should be reserved;
    pub fn classify(&self, extracted_file: &ExtractedFile) -> Result<Vec<String>> {
        let mut result: Vec<String> = vec![];
        // Define the cordinate if extraction "id"
        for extraction in &extracted_file.matches {
            let input_string = format!("{}", extraction.text);
            if extraction.name == "id" {
                continue;
            }
            let safety;
            if input_string.split('\n').collect::<Vec<&str>>()[0].contains("unsafe") {
                safety = "Unsafe";
            } else {
                safety = "Safe";
            } 
            // extract the coordonate of 'id'
            let r1 = extraction.start.row + 1;
            let c1 = extraction.start.column + 1;
            let r2 = extraction.end.row + 1;
            let c2 = extraction.end.column + 1;
            let input = [input_string.replace("unsafe ", " ")];
            //tokenizer
            let tokenized_input =
                self.tokenizer
                    .encode_list(&input, 512, &TruncationStrategy::LongestFirst, 0);
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
                let output = self.model.forward_t(
                    Some(&input_tensor),
                    Some(&mask),
                    Some(&token_type_ids),
                    None,
                    None,
                    false,
                );
                output.softmax(-1, Kind::Float).detach().to(device)
            });
            let label_mapping = self.config.get_label_mapping().clone();
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
                let out = format!(
                    "{},{},{},{},{},{}(prob={:.2}),{}",
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
                    scores[sentence_idx],
                    safety == label_string,
                );
                result.push(out);
                // println!(
                //     "{},{},{},{},{},{}(prob={:.2})",
                //     extracted_file
                //         .file
                //         .as_ref()
                //         .map(|f| f.to_str().unwrap_or("NON-UTF8 FILENAME"))
                //         .unwrap_or("NO FILE"),
                //     r1,
                //     c1,
                //     r2,
                //     c2,
                //     &label_string,
                //     scores[sentence_idx]
                // );
            }
        }
        Ok(result)
    }

    /// Parser source files and call classify function to predict unsafe.
    ///
    /// # Returns
    ///
    /// * Classily result in forms of "source file name--cordinate of function containg unsafe keyword-- safe/unsafe--probability"
    ///
    /// # Example
    ///
    /// ```no_run
    /// # fn main() -> anyhow::Result<()> {
    /// use rust_hero::query::{Invocation, QueryFormat};
    /// use rust_hero::safe::SafeLanguageModel;
    /// use anyhow::Context;
    ///
    ///
    /// let args=[
    ///        "rust_hero",
    ///        "-q",
    ///        "rust",
    ///        "(function_item (identifier) @id) @function",
    ///        "--format=classes",
    ///        "--sort",
    ///        "--no-gitignore",
    ///        "data/error.rs",
    ///    ]
    /// .iter()
    /// .map(|s| s.to_string())
    /// .collect();
    /// let invocation = Invocation::from_args(args)?;
    /// match invocation {
    ///    Invocation::DoQuery(query_opts) => {
    ///         let safe_model = SafeLanguageModel::new(query_opts)?;
    ///         match safe_model.get_opt().format {
    ///             QueryFormat::Classes => {
    ///                 let output = safe_model
    ///                     .predict()
    ///                     .context("couldn't perform the prediction")?;
    ///                 for label in output {
    ///                     println!("{:?}", label);
    ///                 }
    ///             ()
    ///           }
    ///        _ => (),
    ///     }
    ///   }
    ///     _ => (),
    /// }
    /// # Ok(())
    /// # }
    /// ```
    pub fn predict(&self) -> Result<Vec<String>> {
        // You might think "why not use ParallelBridge here?" Well, the quick answer
        // is that I benchmarked it and having things separated here and handling
        // their own errors actually speeds up this part of the code by like 20%!
        let items: Vec<ignore::DirEntry> = self
            .search_files()
            .context("had a problem while walking the filesystem")?;

        let chooser = self
            .opts
            .extractor_chooser()
            .context("couldn't construct a filetype matcher")?;
        let mut extracted_files = items
            .par_iter()
            .filter_map({
                let chooser = &chooser;
                |entry| {
                    chooser
                        .extractor_for(entry)
                        .map(|extractor| (entry, extractor))
                }
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
            .collect::<Result<Vec<ExtractedFile>>>()
            .context("couldn't extract matches from files")?;

        if self.opts.sort {
            extracted_files.sort()
        }
        let mut result: Vec<String> = vec![];

        match self.opts.format {
            QueryFormat::Classes => {
                for extracted_file in extracted_files {
                    let out = self.classify(&extracted_file)?;
                    for label in out {
                        result.push(label);
                    }
                }
            }
            _ => bail!("You should call do_query function!"),
        }

        Ok(result)
    }

    /// Parser source files.
    ///
    /// # Returns
    ///
    /// * Concrete syntax tree for source files
    ///
    /// # Example
    ///
    /// ```no_run
    /// # fn main() -> anyhow::Result<()> {
    /// use rust_hero::query::{Invocation, QueryFormat};
    /// use rust_hero::safe::SafeLanguageModel;
    /// use std::io::{self, BufWriter, Write};
    ///
    ///
    /// let args=[
    ///        "rust_hero",
    ///        "-q",
    ///        "rust",
    ///        "(function_item (identifier) @id) @function",
    ///        "--format=pretty-json",
    ///        "--sort",
    ///        "--no-gitignore",
    ///        "data/error.rs",
    ///    ]
    /// .iter()
    /// .map(|s| s.to_string())
    /// .collect();
    /// let invocation = Invocation::from_args(args)?;
    /// let mut buffer = BufWriter::new(io::stdout());
    ///
    /// match invocation {
    ///    Invocation::DoQuery(query_opts) => {
    ///         let safe_model = SafeLanguageModel::new(query_opts)?;
    ///         match safe_model.get_opt().format {
    ///             QueryFormat::Json => safe_model.do_query(&mut buffer)?,
    ///             _ => (),
    ///         };
    ///   }
    ///    _ => (),
    /// }
    /// # Ok(())
    /// # }
    /// ```
    pub fn do_query(&self, mut out: impl Write) -> Result<()> {
        let items: Vec<ignore::DirEntry> = self
            .search_files()
            .context("had a problem while walking the filesystem")?;

        let chooser = self
            .opts
            .extractor_chooser()
            .context("couldn't construct a filetype matcher")?;
        let mut extracted_files = items
            .par_iter()
            .filter_map({
                let chooser = &chooser;
                |entry| {
                    chooser
                        .extractor_for(entry)
                        .map(|extractor| (entry, extractor))
                }
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
            .collect::<Result<Vec<ExtractedFile>>>()
            .context("couldn't extract matches from files")?;

        if self.opts.sort {
            extracted_files.sort()
        }

        match self.opts.format {
            QueryFormat::Classes => bail!("You should call predict function!"),

            QueryFormat::Lines => {
                for extracted_file in extracted_files {
                    write!(out, "{}", extracted_file).context("could not write lines")?;
                }
            }

            QueryFormat::Json => {
                serde_json::to_writer(out, &extracted_files)
                    .context("could not write JSON output")?;
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
}
