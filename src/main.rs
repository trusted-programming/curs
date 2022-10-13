use anyhow::{Context, Result};
use rust_hero::query::{Invocation, QueryFormat};
use rust_hero::safe::{show_languages, SafeLanguageModel};
use std::env;
use std::io::{self, BufWriter, Write};

pub fn main() {
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

pub fn try_main(args: Vec<String>, out: impl Write) -> Result<()> {
    let invocation = Invocation::from_args(args)
        .context("couldn't get a valid configuration from the command-line options")?;
    match invocation {
        Invocation::DoQuery(query_opts) => {
            let safe_model = SafeLanguageModel::new(query_opts)?;
            match safe_model.get_opt().format {
                QueryFormat::Classes => {
                    let output = safe_model
                        .predict()
                        .context("couldn't perform the prediction")?;
                    for label in output {
                        println!("{:?}", label);
                    }
                    Ok(())
                }
                _ => safe_model.do_query(out),
            }
        }
        Invocation::ShowLanguages => {
            show_languages(out).context("couldn't show the list of languages")
        }
    }
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
    #[ignore]
    fn lines_output() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn json_output() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn json_lines_output() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn pretty_json_output() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_cpp() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_elm() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_haskell() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_javascript() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
            "-q",
            "javascript",
            "(_)",
            "--format=pretty-json",
            "--sort",
            "--no-gitignore",
            // note that this doesn't include the entire vendor
            // directory. tree-sitter-javascript vendors a couple of libraries
            // to test things and it makes this test run unacceptably long. I
            // think the slowdown is due to the diffing step; the rust_hero
            // code completes in a reasonable amount of time.
            "vendor/tree-sitter-javascript/test",
        ]))
    }

    #[test]
    #[ignore]
    fn all_php() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_ruby() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_rust() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_typescript() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn all_elixir() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
    #[ignore]
    fn rust_unsafe() {
        insta::assert_snapshot!(call(&[
            "rust_hero",
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
