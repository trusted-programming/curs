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
cargo install --git https://github.com/BrianHicks/tree-grepper
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
