#!/bin/bash
echo "Downloading vendor for tree-grepper"
mkdir vendor && cd vendor
git clone https://github.com/tree-sitter/tree-sitter-cpp.git
git clone https://github.com/elixir-lang/tree-sitter-elixir.git
git clone https://github.com/elm-tooling/tree-sitter-elm.git
git clone https://github.com/tree-sitter/tree-sitter-haskell.git
git clone https://github.com/tree-sitter/tree-sitter-ruby.git
git clone https://github.com/tree-sitter/tree-sitter-rust.git
git clone https://github.com/tree-sitter/tree-sitter-javascript.git
git clone https://github.com/tree-sitter/tree-sitter-php.git
git clone https://github.com/tree-sitter/tree-sitter-typescript.git
git clone https://github.com/ikatyang/tree-sitter-markdown.git
git clone https://github.com/cstrahan/tree-sitter-nix.git
cd ..
echo "Download vendor Done!"
echo "Installing tree-grepper"
git clone https://github.com/BrianHicks/tree-grepper.git
cp -r vendor/ tree-grepper/
cd tree-grepper
cargo install --path .
cd ..
echo "tree-grepper vendor installed!"
