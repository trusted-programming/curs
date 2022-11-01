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
    // vendor download
    if !Path::new("vendor/tree-sitter-rust/src").exists() {
        clone(
            "https://github.com/tree-sitter/tree-sitter-rust.git",
            "vendor/tree-sitter-rust",
        )
        .ok();
    }

    println!("cargo:rerun-if-changed=build.rs");
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
}
