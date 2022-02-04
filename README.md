# Classify unsafe Rust code

For each function in Rust, ```curs``` infers whether it is unsafe or not.

## Installation:

```bash
pip install http://bertrust.s3.amazonaws.com/curs-0.0.1-py3-none-any.whl
```

## Example usage:

```bash
curs ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.26/src/error.rs
# default, using a pretrained CodeBERT model
curs --model=codeBERT ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.26/src/error.rs
# alternative using a pretrained TBCNN model
curs --model=tbcnn ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.26/src/error.rs
```

## Runtime dependencies

It uses `tree-grepper` to parse Rust functions.
```bash
cargo install --git https://github.com/BrianHicks/tree-grepper
```

## Build dependencies

Download the pretrained code model before building the package:
```bash
wget http://bertrust.s3.amazonaws.com/codeBERT_pl.bin
mkdir -p curs/codeBERT
mv codeBERT_pl.bin curs/codeBERT/
```
