//! # Classify unsafe Rust code
//!
//! For each function in Rust, the `unsafe` keyword utilizes the unsafe superpowers. However, the `unsafe` keyword is not necessary if it can be taken out while the program is compiled successfully.
//!
//! `curs` infers the necessity of `unsafe` keywords without the need of recompiling. `curs` trains a [microsoft/codebert](https://github.com/microsoft/CodeBERT) based model and take advantage of bert's strong reasoning capability to inference the necessity of `unsafe`.
//!
//! # Example
//!
//! ```no_run
//!
//! use anyhow::{Context, Result};
//! use curs::query::{Invocation, QueryFormat};
//! use curs::safe::{show_languages, SafeLanguageModel};
//! use std::env;
//! use std::io::{self, BufWriter, Write};
//!
//! pub fn main() {
//!     let mut buffer = BufWriter::new(io::stdout());
//!
//!     if let Err(error) = try_main(env::args().collect(), &mut buffer) {
//!         if let Some(err) = error.downcast_ref::<io::Error>() {
//!             // a broken pipe is totally normal and fine. It's what we get when
//!             // we pipe to something like `head` that only takes a certain number
//!             // of lines.
//!             if err.kind() == io::ErrorKind::BrokenPipe {
//!                 std::process::exit(0);
//!             }
//!         }
//!
//!         if let Some(clap_error) = error.downcast_ref::<clap::Error>() {
//!             // Clap errors (--help or misuse) are already well-formatted,
//!             // so we don't have to do any additional work.
//!             eprint!("{}", clap_error);
//!         } else {
//!             eprintln!("{:?}", error);
//!         }
//!
//!         std::process::exit(1);
//!     }
//!
//!     buffer.flush().expect("failed to flush buffer!");
//! }
//!
//! pub fn try_main(args: Vec<String>, out: impl Write) -> Result<()> {
//!     let invocation = Invocation::from_args(args)
//!         .context("couldn't get a valid configuration from the command-line options")?;
//!     match invocation {
//!         Invocation::DoQuery(query_opts) => {
//!             let safe_model = SafeLanguageModel::new(query_opts)?;
//!             match safe_model.get_opt().format {
//!                 QueryFormat::Classes => {
//!                     let output = safe_model
//!                         .predict()
//!                         .context("couldn't perform the prediction")?;
//!                     for label in output {
//!                         println!("{:?}", label);
//!                     }
//!                     Ok(())
//!                 }
//!                 _ => safe_model.do_query(out),
//!             }
//!         }
//!         Invocation::ShowLanguages => {
//!             show_languages(out).context("couldn't show the list of languages")
//!         }
//!     }
//! }
//! ```
//!
pub mod query;
pub mod safe;
