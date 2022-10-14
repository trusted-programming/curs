#!/bin/bash
echo "Adding submodules to vendor"
git submodule add https://github.com/tree-sitter/tree-sitter-cpp.git vendor/tree-sitter-cpp
git submodule add https://github.com/elixir-lang/tree-sitter-elixir.git vendor/tree-sitter-elixir
git submodule add https://github.com/elm-tooling/tree-sitter-elm.git vendor/tree-sitter-elm
git submodule add https://github.com/tree-sitter/tree-sitter-haskell.git vendor/tree-sitter-haskell
git submodule add https://github.com/tree-sitter/tree-sitter-ruby.git vendor/tree-sitter-ruby
git submodule add https://github.com/tree-sitter/tree-sitter-rust.git vendor/tree-sitter-rust
git submodule add https://github.com/tree-sitter/tree-sitter-javascript.git vendor/tree-sitter-javascript
git submodule add https://github.com/tree-sitter/tree-sitter-php.git vendor/tree-sitter-php
git submodule add https://github.com/tree-sitter/tree-sitter-typescript.git vendor/tree-sitter-typescript
git submodule add https://github.com/ikatyang/tree-sitter-markdown.git vendor/tree-sitter-markdown
git submodule add https://github.com/cstrahan/tree-sitter-nix.git vendor/tree-sitter-nix
echo "Add submodules Done!"
