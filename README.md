# Classify unsafe Rust code

For each function in Rust, ```curs``` infers whether it is unsafe or not.

## Installation:

```bash
pip install http://bertrust.s3.amazonaws.com/curs-0.0.1-py3-none-any.whl
```

## Example usage:

```bash
curs ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.58/src/error.rs
# default, using a pretrained CodeBERT model
curs --model=codeBERT ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.58/src/error.rs
# alternative using a pretrained TBCNN model
curs --model=tbcnn ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.58/src/error.rs
```

## Runtime dependencies

It uses `tree-grepper` to parse Rust functions.
```bash
mkdir vendor & cd vendor
git clone https://github.com/tree-sitter/tree-sitter-cpp.git
git clone https://github.com/elixir-lang/tree-sitter-elixir.git
git clone https://github.com/elm-tooling/tree-sitter-elm.git
git clone https://github.com/tree-sitter/tree-sitter-haskell.git
git clone https://github.com/tree-sitter/tree-sitter-ruby.git
git clone https://github.com/tree-sitter/tree-sitter-rust.git
git clone https://github.com/tree-sitter/tree-sitter-javascript.git
git clone https://github.com/tree-sitter/tree-sitter-php.git
git clone https://github.com/tree-sitter/tree-sitter-typescript.git
cargo install --git https://github.com/BrianHicks/tree-grepper
```
It uses `libtorch-1.10.2` to inference bert. Download the libtorch with CPU or CUDA from following links:
```bash
CPU: https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.10.2%2Bcpu.zip
CUDA: https://download.pytorch.org/libtorch/cu113/libtorch-cxx11-abi-shared-with-deps-1.10.2%2Bcu113.zip
```
Unzip the file and set the environment path in .bashrc:

```bash
export LIBTORCH=$libtorchDir$/libtorch
export LD_LIBRARY_PATH=${LIBTORCH}/lib:$LD_LIBRARY_PATH
```
## Build dependencies

Download the pretrained code model before building the package:
```bash
wget http://bertrust.s3.amazonaws.com/codeBERT_pl.bin
mkdir -p curs/codeBERT
mv codeBERT_pl.bin curs/codeBERT/
wget http://bertrust.s3.amazonaws.com/tbcnn.zip
unzip tbcnn.zip
```

## Datasets
* curs-0.0.1-py3-none-any.whl   # package distribution
* uniq-unsafe-safe-asm.tar.bz2  # Assembler of Rust functions classified into safe and unsafe folders
  - codeBERT_pl.bin             # pretrained codeBERT model for classifying unsafe Rust code
  - tbcnn.zip                   # pretrained TBCNN model for classifying unsafe Rust code
* unique-safe-unsafe-fn.tar.bz2 # Rust functions classified into safe and unsafe folders

```bash
files=$(s3cmd ls s3://bertrust | awk '{system("basename " $4)}')
# download files
for file in $files; do
	wget http://bertrust.s3.amazonaws.com/$file
done
# upload files
for file in $files; do
	s3cmd put $file s3://bertrust
done
# recursively set acl of the files in the bucket to public accessible
s3cmd setacl -Pr s3://bertrust
```
