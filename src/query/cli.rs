use crate::query::Extractor;
use crate::query::ExtractorChooser;
use crate::query::Language;
use anyhow::{bail, Context, Error, Result};
use clap::{crate_authors, crate_version, value_parser, Arg, ArgMatches, Command};
use itertools::Itertools;
use std::collections::HashMap;
use std::path::PathBuf;
use std::str::FromStr;

/// Invocation for arguments parser
pub enum Invocation {
    /// Configuration for language query
    DoQuery(QueryOpts),
    ShowLanguages,
}

/// Configuration for language query
#[derive(Debug)]
pub struct QueryOpts {
    pub position: Vec<usize>,
    /// Extractor for extracting syntax information of program
    pub extractors: Vec<Extractor>,
    /// Directory of query files
    pub paths: Vec<PathBuf>,
    /// Whether ignore .gitignore file or not
    pub git_ignore: bool,
    /// Information format of extrated syntax
    pub format: QueryFormat,
    /// Whether sort extrated information or not
    pub sort: bool,
}

impl QueryOpts {
    /// Build a filetype matcher using provided extractors
    pub fn extractor_chooser(&self) -> Result<ExtractorChooser> {
        ExtractorChooser::from_extractors(&self.extractors)
    }
}

impl Invocation {
    /// Build Invocation from input arguments
    /// # Example
    ///
    /// ```no_run
    /// # fn main() -> anyhow::Result<()> {
    /// use rust_hero::query::Invocation;
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
    /// # Ok(())
    /// # }
    /// ```
    pub fn from_args(args: Vec<String>) -> Result<Self> {
        // I'm not super happy with this! I would love for LANGUAGE and QUERY to
        // be taken positionally when there is just one so we don't always have
        // to specify `-q`. However, I also want to get working on the rest of
        // the program so I'm dropping the requirement for now by making `-q`
        // required. I think that's an OK tradeoff until I can figure something
        // else better because it'll be backwards compatible with the scheme
        // I outlined above.
        //
        // Check
        // https://users.rust-lang.org/t/grep-like-argument-parsing-with-clap/63392
        // for where I asked about this in public.
        let matches = Command::new("rust_hero")
            .version(crate_version!())
            .author(crate_authors!())
            .arg(
                Arg::new("additional-query")
                    .short('q')
                    .long("query")
                    .help("a language and query to perform")
                    .long_help(
                        "a language and query to perform (at least one is required.) See https://tree-sitter.github.io for information on writing queries. Run tree-grepper --languages for a list of languages.",
                    )
                    .number_of_values(2)
                    .value_names(&["LANGUAGE", "QUERY"])
                    // .required_unless_present("languages")
                    // .multiple_values(true)
                    .default_values(&["rust", "(function_item (identifier) @id) @function"])
            )
            .arg(
                Arg::new("no-gitignore")
                    .long("no-gitignore")
                    .help("don't use git's ignore and exclude files to filter files")
            )
            .arg(
                Arg::new("PATHS")
                    .required_unless_present("PATHS")
                    .default_value(".")
                    .help("places to search for matches")
            )
            .arg(
                Arg::new("FORMAT")
                .long("format")
                .short('f')
                .possible_values(&["classes", "lines", "json", "json-lines", "pretty-json"])
                .default_value("classes")
                .help("what format should we output lines in?")
            )
            .arg(
                Arg::new("SORT")
                .long("sort")
                .help("sort matches stably")
                .long_help("sort matches stably. If this is not specified, output ordering will vary because due to parallelism. Caution: this adds a worst-case `O(n * log(n))` overhead, where `n` is the number of files matched. Avoid it if possible if you care about performance.")
            )
            .arg(
                Arg::new("LANGUAGE")
                .long("language")
                .short('l')
                .help("print the language names tree-grepper knows about")
            )
            .arg(
                Arg::new("POSITION")
                .long("position")
                .short('p')
                .value_parser(value_parser!(usize))
                .number_of_values(2)
                .value_names(&["LINE", "COLUMN"])
                .default_values(&["1", "1"])
                .help("select the function/block that encloses the position")
            )
            .try_get_matches_from(args)
            .context("could not parse args")?;
        let sort = matches.is_present("SORT");
        let extractors = Self::extractors(&matches)?;
        let paths = Self::paths(&matches)?;
        let git_ignore = !matches.is_present("no-gitignore");
        let format =
            QueryFormat::from_str(matches.value_of("FORMAT").context("format not provided")?)
                .context("could not set format")?;
        let position = if let Some(mut values) = matches.values_of("POSITION") {
            vec![
                usize::from_str(&values.next().unwrap()).unwrap(),
                usize::from_str(&values.next().unwrap()).unwrap(),
            ]
        } else {
            vec![0, 0]
        };

        if matches.is_present("LANGUAGE") {
            Ok(Self::ShowLanguages)
        } else {
            Ok(Self::DoQuery(QueryOpts {
                extractors,
                position,
                paths,
                git_ignore,
                format,
                sort,
            }))
        }
    }

    fn extractors(matches: &ArgMatches) -> Result<Vec<Extractor>> {
        let values = match matches.values_of("additional-query") {
            Some(values) => values,
            None => bail!("queries were required but not provided. This indicates an internal error and you should report it!"),
        };

        // the most common case is going to be one query, so let's allocate
        // that immediately...
        let mut query_strings: HashMap<Language, String> = HashMap::with_capacity(1);

        // If you have two tree-sitter queries `(one)` and `(two)`, you can
        // join them together in a single string like `(one)(two)`. In that
        // case, the resulting query will act like an OR and match any of the
        // queries inside. Doing this automatically gives us an advantage:
        // for however many queries we get on the command line, we will only
        // ever have to run one per file, since we can combine them and you
        // can't specify queries across multiple languages! Nobody should ever
        // notice, except that they won't see as much of a slowdown for adding
        // new queries to an invocation as they might expect. (Well, hopefully!)
        for (raw_lang, raw_query) in values.tuples() {
            let lang = Language::from_str(raw_lang).context("could not parse language")?;

            let mut query_out = String::from(raw_query);

            let temp_query = lang
                .parse_query(raw_query)
                .context("could not parse query")?;

            if temp_query.capture_names().is_empty() {
                query_out.push_str("@query");
            }

            if let Some(existing) = query_strings.get_mut(&lang) {
                existing.push_str(&query_out);
            } else {
                query_strings.insert(lang, query_out);
            }
        }

        let mut out = Vec::with_capacity(query_strings.len());
        for (lang, raw_query) in query_strings {
            let query = lang
                .parse_query(&raw_query)
                .context("could not parse combined query")?;

            out.push(Extractor::new(lang, query))
        }

        Ok(out)
    }

    fn paths(matches: &ArgMatches) -> Result<Vec<PathBuf>> {
        match matches.values_of("PATHS") {
            Some(values) =>
                values
                    .map(|raw_path| PathBuf::from_str(raw_path).with_context(|| format!("could not parse a path from {}", raw_path)))
                    .collect(),

            None => bail!("at least one path was required but not provided. This indicates an internal errors and you should report it!"),
        }
    }
}

/// Information format of extrated syntax
#[derive(Debug)]
pub enum QueryFormat {
    /// Classify extracted information
    Classes,
    /// Display extracted information in Lines
    Lines,
    /// Display extracted information in Json
    Json,
    /// Display extracted information in JsonLines
    JsonLines,
    /// Display extracted information in PrettyJson
    PrettyJson,
}

impl FromStr for QueryFormat {
    type Err = Error;

    fn from_str(s: &str) -> Result<Self> {
        match s {
            "classes" => Ok(QueryFormat::Classes),
            "lines" => Ok(QueryFormat::Lines),
            "json" => Ok(QueryFormat::Json),
            "json-lines" => Ok(QueryFormat::JsonLines),
            "pretty-json" => Ok(QueryFormat::PrettyJson),
            _ => bail!("unknown format. See --help for valid formats."),
        }
    }
}
