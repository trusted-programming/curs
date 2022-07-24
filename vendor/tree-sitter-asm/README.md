# tree-sitter-asm

[![Build/test](https://github.com/tree-sitter/tree-sitter-asm/actions/workflows/ci.yml/badge.svg)](https://github.com/tree-sitter/tree-sitter-asm/actions/workflows/ci.yml)

Rust grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter)

## Features

* **Speed** - When initially parsing a file, `tree-sitter-asm` takes around twice as long as Rustc's hand-coded parser.

  ```sh
  $ wc -l examples/ast.rs
    2157 examples/ast.rs

  $ tree-sitter parse examples/1.asm --quiet --time
    examples/1.asm	16 ms
  ```

  But if you *edit* the file after parsing it, this parser can generally *update* the previous existing syntax tree to reflect your edit in less than a millisecond, thanks to Tree-sitter's incremental parsing system.
