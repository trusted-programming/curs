//! # Extracting syntax information of program
//!
//! Implementation of the query supports Rust
//!
//! # Declaration
//!
//! Implementation of the language query in this project is based on [BrianHicks/tree-grepper](https://github.com/BrianHicks/tree-grepper).
//! We add classify option for `Invocation` and append cargo docs for source files.
//!
//! # Example
//!
//! ```
//! # fn main() -> anyhow::Result<()> {
//! use rust_hero::query::{Language,Extractor};
//! use tree_sitter::Parser;
//!
//! let lang = Language::Rust;
//! let query = lang
//!     .parse_query("(function_item (identifier) @id) @function")
//!     .unwrap();
//! let extractor = Extractor::new(lang, query);
//!         let extracted = extractor
//!        .extract_from_text(None, b"fn main(){println!(\"hello rust_hero\");}", &mut Parser::new())
//!        // From Result<Option<ExtractedFile>>
//!        .unwrap()
//!        // From Option<ExtractedFile>
//!        .unwrap();
//!
//! println!("{:?},{:?}，{:?}",extracted.matches.len(),extracted.matches[0].name,extracted.matches[0].text);
//! assert_eq!(extracted.matches.len(), 2);
//! assert_eq!(extracted.matches[0].name, "function");
//! assert_eq!(extracted.matches[0].text, "fn main(){println!(\"hello rust_hero\");}");
//! # Ok(())
//! # }
//! ```
mod cli;
mod extractor;
mod extractor_chooser;
mod files;
mod language;

pub use cli::{Invocation, QueryFormat, QueryOpts};
pub use extractor::{ExtractedFile, ExtractedMatch, Extractor};
pub use extractor_chooser::ExtractorChooser;
pub use files::Files;
pub use language::Language;
