//! # Extracting syntax information of program
//!
//! Implementation of the query supports languages: Cpp, Elixir, Elm, Haskell, JavaScript, Php, Ruby, Rust, TypeScript
//!
//! # Example
//!
//! ```
//! # fn main() -> anyhow::Result<()> {
//! use curs::query::{Language,Extractor};
//! use tree_sitter::Parser;
//!
//! let lang = Language::Elm;
//! let query = lang
//!     .parse_query("(import_clause (upper_case_qid)@import)")
//!     .unwrap();
//! let extractor = Extractor::new(lang, query);
//!         let extracted = extractor
//!        .extract_from_text(None, b"import Html.Styled", &mut Parser::new())
//!        // From Result<Option<ExtractedFile>>
//!        .unwrap()
//!        // From Option<ExtractedFile>
//!        .unwrap();
//!
//! assert_eq!(extracted.matches.len(), 1);
//! assert_eq!(extracted.matches[0].name, "import");
//! assert_eq!(extracted.matches[0].text, "Html.Styled");
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
