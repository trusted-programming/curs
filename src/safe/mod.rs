//! # Predict whether the fragment program containing unsafe keyword is `safe` or `unsafe`
//!
//! Implementation of the query currently supports Rust language
//!
//! # Example
//!
//! ```no_run
//! # fn main() -> anyhow::Result<()> {
//! use rust_hero::query::{Invocation, QueryFormat};
//! use rust_hero::safe::SafeLanguageModel;
//! use std::io::{self, BufWriter, Write};
//!
//!
//! let args=[
//!        "rust_hero",
//!        "-q",
//!        "rust",
//!        "(function_item (identifier) @id) @function",
//!        "--format=pretty-json",
//!        "--sort",
//!        "--no-gitignore",
//!        "data/error.rs",
//!    ]
//! .iter()
//! .map(|s| s.to_string())
//! .collect();
//! let invocation = Invocation::from_args(args)?;
//! let mut buffer = BufWriter::new(io::stdout());
//!
//! match invocation {
//!    Invocation::DoQuery(query_opts) => {
//!         let safe_model = SafeLanguageModel::new(query_opts)?;
//!         match safe_model.get_opt().format {
//!             QueryFormat::Json => safe_model.do_query(&mut buffer)?,
//!             _ => (),
//!         };
//!   }
//!    _ => (),
//! }
//! # Ok(())
//! # }
//! ```
mod inference;

pub use inference::{show_languages, SafeLanguageModel};
