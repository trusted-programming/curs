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

echo "Downloading model to ./.cache/codebert/"
mkdir -p ./.cache/codebert && cd ./.cache/codebert
wget https://link.jscdn.cn/sharepoint/aHR0cHM6Ly90Z2JuMDEtbXkuc2hhcmVwb2ludC5jb20vOnU6L2cvcGVyc29uYWwveGlhb2hhbmdfejVfdG4vRVhIY0xLVEprXzlIanlDUTJwYXFFNjhCNXUxZnJucHJwV3pEdXJJeEFwbTJhZz9lPWd6NjU2dA.json -O config.json --unlink
wget https://link.jscdn.cn/sharepoint/aHR0cHM6Ly90Z2JuMDEtbXkuc2hhcmVwb2ludC5jb20vOnU6L2cvcGVyc29uYWwveGlhb2hhbmdfejVfdG4vRVN2NVdIRGRza1pCbFBSWUxYSk52Y2dCbG0xQWUxakYyZFJHazZIbEdrS3psZz9lPTNDMFY3RQ.json -O vocab.json --unlink
wget https://link.jscdn.cn/sharepoint/aHR0cHM6Ly90Z2JuMDEtbXkuc2hhcmVwb2ludC5jb20vOnQ6L2cvcGVyc29uYWwveGlhb2hhbmdfejVfdG4vRWMwVTVxQ2ZMTE5IdkxqVXhtdUlyTDBCSDFPNkxmeXpXdFg1YVM1N2hNZmFWUT9lPWs5V05JQQ.txt -O merges.txt --unlink
wget https://link.jscdn.cn/sharepoint/aHR0cHM6Ly90Z2JuMDEtbXkuc2hhcmVwb2ludC5jb20vOnU6L2cvcGVyc29uYWwveGlhb2hhbmdfejVfdG4vRWY3WlV1dWZJTEpJcWx4b0VxemxvNDBCLTE5Ni1vbnZSSmFYOFNrWG8tS2xFZz9lPWRDQ2xQUQ.ot -O rust_model.ot --unlink
echo "Download model Done!"