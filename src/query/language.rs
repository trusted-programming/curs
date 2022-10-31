use anyhow::{anyhow, bail, Error, Result};
use std::fmt::{Display, Formatter};
use std::str::FromStr;

/// Language support of query
#[derive(PartialEq, Eq, Hash, Debug)]
pub enum Language {
    Rust,
}

impl Language {
    /// A set of language supported by query
    pub fn all() -> Vec<Language> {
        vec![Language::Rust]
    }

    /// Map language to tree_sitter
    pub fn language(&self) -> tree_sitter::Language {
        unsafe {
            match self {
                Language::Rust => tree_sitter_rust(),
            }
        }
    }

    /// Use tree_sitter to extract syntax information of program
    pub fn parse_query(&self, raw: &str) -> Result<tree_sitter::Query> {
        tree_sitter::Query::new(self.language(), raw).map_err(|err| anyhow!("{}", err))
    }
    /// Get the language of source file
    pub fn name_for_types_builder(&self) -> &str {
        match self {
            Language::Rust => "rust",
        }
    }
}

impl FromStr for Language {
    type Err = Error;

    fn from_str(s: &str) -> Result<Self> {
        match s {
            "rust" => Ok(Language::Rust),
            _ => bail!(
                "unknown language {}. Try one of: {}",
                s,
                Language::all()
                    .into_iter()
                    .map(|l| l.to_string())
                    .collect::<Vec<String>>()
                    .join(", ")
            ),
        }
    }
}

impl Display for Language {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result<(), std::fmt::Error> {
        match self {
            Language::Rust => f.write_str("rust"),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn to_str_reflects_from_str() {
        // Note: this will hide results if there are multiple failures. It's
        // something that could be worked around but I don't think it is right
        // now. If it bothers you in the future, feel free to take a stab at it!
        Language::all()
            .into_iter()
            .for_each(|lang| assert_eq!(Language::from_str(&lang.to_string()).unwrap(), lang))
    }

    #[test]
    fn parse_query_smoke_test() {
        assert_eq!(true, Language::Rust.parse_query("(_)").is_ok());
    }

    #[test]
    fn parse_query_problem() {
        // tree-grepper 1.0 just printed the error struct when problems like
        // this happened. This test is just here to make sure we take a slightly
        // friendlier approach for 2.0.
        assert_eq!(
            String::from("Query error at 1:2. Invalid node type node_that_doesnt_exist"),
            Language::Rust
                .parse_query("(node_that_doesnt_exist)")
                .unwrap_err()
                .to_string(),
        )
    }
}

extern "C" {
    fn tree_sitter_rust() -> tree_sitter::Language;
}
