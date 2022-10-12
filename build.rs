use git2::Repository;
use std::path::{Path, PathBuf};

// https://doc.rust-lang.org/cargo/reference/build-scripts.html

fn clone<P: AsRef<Path>>(url: &str, path: P) -> std::io::Result<()> {
    match Repository::clone(url, path) {
        Ok(repo) => repo,
        Err(e) => panic!("failed to clone: {}", e),
    };
    Ok(())
}
fn main() {
    println!("cargo:rerun-if-changed=build.rs");

    // vendor download
    if !Path::new("vendor").exists() {
        clone(
            "https://github.com/tree-sitter/tree-sitter-cpp.git",
            "vendor/tree-sitter-cpp",
        )
        .ok();
        clone(
            "https://github.com/elixir-lang/tree-sitter-elixir.git",
            "vendor/tree-sitter-elixir",
        )
        .ok();
        clone(
            "https://github.com/elm-tooling/tree-sitter-elm.git",
            "vendor/tree-sitter-elm",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-haskell.git",
            "vendor/tree-sitter-haskell",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-ruby.git",
            "vendor/tree-sitter-ruby",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-rust.git",
            "vendor/tree-sitter-rust",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-javascript.git",
            "vendor/tree-sitter-javascript",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-php.git",
            "vendor/tree-sitter-php",
        )
        .ok();
        clone(
            "https://github.com/tree-sitter/tree-sitter-typescript.git",
            "vendor/tree-sitter-typescript",
        )
        .ok();
        clone(
            "https://github.com/ikatyang/tree-sitter-markdown.git",
            "vendor/tree-sitter-markdown",
        )
        .ok();
        clone(
            "https://github.com/cstrahan/tree-sitter-nix.git",
            "vendor/tree-sitter-nix",
        )
        .ok();
    }
    // cpp
    let cpp_dir: PathBuf = ["vendor", "tree-sitter-cpp", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-cpp/src/parser.c");
    cc::Build::new()
        .include(&cpp_dir)
        .warnings(false)
        .file(cpp_dir.join("parser.c"))
        .compile("tree-sitter-cpp");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-cpp/src/scanner.cc");
    cc::Build::new()
        .include(&cpp_dir)
        .cpp(true)
        .warnings(false)
        .file(cpp_dir.join("scanner.cc"))
        .compile("tree_sitter_cpp_scanner");

    // elixir
    let elixir_dir: PathBuf = ["vendor", "tree-sitter-elixir", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-elixir/src/parser.c");
    cc::Build::new()
        .include(&elixir_dir)
        .warnings(false)
        .file(elixir_dir.join("parser.c"))
        .compile("tree-sitter-elixir");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-elixir/src/scanner.cc");
    cc::Build::new()
        .include(&elixir_dir)
        .warnings(false)
        .cpp(true)
        .file(elixir_dir.join("scanner.cc"))
        .compile("tree_sitter_elixir_scanner");

    // elm
    let elm_dir: PathBuf = ["vendor", "tree-sitter-elm", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-elm/src/parser.c");
    cc::Build::new()
        .include(&elm_dir)
        .warnings(false)
        .file(elm_dir.join("parser.c"))
        .compile("tree-sitter-elm");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-elm/src/scanner.cc");
    cc::Build::new()
        .include(&elm_dir)
        .cpp(true)
        .warnings(false)
        .file(elm_dir.join("scanner.cc"))
        .compile("tree_sitter_elm_scanner");

    // haskell
    let haskell_dir: PathBuf = ["vendor", "tree-sitter-haskell", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-haskell/src/parser.c");
    cc::Build::new()
        .include(&haskell_dir)
        .warnings(false)
        .file(haskell_dir.join("parser.c"))
        .compile("tree-sitter-haskell");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-haskell/src/scanner.cc");
    cc::Build::new()
        .include(&haskell_dir)
        .warnings(false)
        .file(haskell_dir.join("scanner.c"))
        .compile("tree_sitter_haskell_scanner");

    // javascript
    let javascript_dir: PathBuf = ["vendor", "tree-sitter-javascript", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-javascript/src/parser.c");
    cc::Build::new()
        .include(&javascript_dir)
        .warnings(false)
        .file(javascript_dir.join("parser.c"))
        .compile("tree-sitter-javascript");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-javascript/src/scanner.c");
    cc::Build::new()
        .include(&javascript_dir)
        .warnings(false)
        .file(javascript_dir.join("scanner.c"))
        .compile("tree_sitter_javascript_scanner");

    // php
    let php_dir: PathBuf = ["vendor", "tree-sitter-php", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-php/src/parser.c");
    cc::Build::new()
        .include(&php_dir)
        .warnings(false)
        .file(php_dir.join("parser.c"))
        .compile("tree-sitter-php");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-php/src/scanner.cc");
    cc::Build::new()
        .include(&php_dir)
        .cpp(true)
        .warnings(false)
        .file(php_dir.join("scanner.cc"))
        .compile("tree_sitter_php_scanner");

    // ruby
    let ruby_dir: PathBuf = ["vendor", "tree-sitter-ruby", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-ruby/src/parser.c");
    cc::Build::new()
        .include(&ruby_dir)
        .warnings(false)
        .file(ruby_dir.join("parser.c"))
        .compile("tree-sitter-ruby");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-ruby/src/scanner.cc");
    cc::Build::new()
        .include(&ruby_dir)
        .cpp(true)
        .warnings(false)
        .file(ruby_dir.join("scanner.cc"))
        .compile("tree_sitter_ruby_scanner");

    // rust
    let rust_dir: PathBuf = ["vendor", "tree-sitter-rust", "src"].iter().collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-rust/src/parser.c");
    cc::Build::new()
        .include(&rust_dir)
        .warnings(false)
        .file(rust_dir.join("parser.c"))
        .compile("tree-sitter-rust");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-rust/src/scanner.c");
    cc::Build::new()
        .include(&rust_dir)
        .warnings(false)
        .file(rust_dir.join("scanner.c"))
        .compile("tree_sitter_rust_scanner");

    // typescript
    let typescript_dir: PathBuf = ["vendor", "tree-sitter-typescript", "typescript", "src"]
        .iter()
        .collect();

    println!("cargo:rerun-if-changed=vendor/tree-sitter-typescript/typescript/src/parser.c");
    cc::Build::new()
        .include(&typescript_dir)
        .warnings(false)
        .file(typescript_dir.join("parser.c"))
        .compile("tree-sitter-typescript");

    println!("cargo:rerun-if-changed=vendor/tree-sitter-typescript/typescript/src/scanner.c");
    cc::Build::new()
        .include(&typescript_dir)
        .warnings(false)
        .file(typescript_dir.join("scanner.c"))
        .compile("tree_sitter_typescript_scanner");
}
