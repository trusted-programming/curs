# Additional toolings for rust

rust_hero is a rust assistant that utilizes NLP to enhance the quality of rust code. It supports `unsafe` and `lifetime` (todo) prediction.

```toml
[dependencies]
rust_hero = "0.5"
```

# Classify unsafe Rust code

For each function in Rust, the `unsafe` keyword utilizes the unsafe superpowers. However, the `unsafe` keyword is not necessary if it can be taken out while the program is compiled successfully.

`rust_hero` infers the necessity of `unsafe` keywords without the need of recompiling. `rust_hero` trains a [microsoft/codebert](https://github.com/microsoft/CodeBERT) based model and take advantage of bert's strong reasoning capability to inference the necessity of `unsafe`.

### Declaration

Implementation of the language query in this project is based on [BrianHicks/tree-grepper](https://github.com/BrianHicks/tree-grepper).

## Performance

It costs 2.06s and 2.90s on average for `rust_hero` inferencing one rust file on Intel I7-12700K CPU and NVIDIA 3080 12GB GPU, seperately.

`rust_hero` written in Rust achieves up to 6.58X and 13.04X performance speedup over `rust_hero` written in Python language for GPU and CPU, seperately.
![Inference speedup](./Img/speedup.png)
<center>Inference speedup of rust_hero in Rust over rust_hero in Python</center>

## Installation
### Runtime dependencies for rust_hero
```bash
sudo apt install build-essential cmake pkg-config libssl-dev wget zip git
```
Download the `tree-grepper` vendor (`cargo build` also download the vendor automatically):
```bash
bash ./scripts/runtime.sh
```
It uses `libtorch-1.12.0` （See [rust-bert](https://github.com/guillaume-be/rust-bert)） to inference rust_hero. Download the libtorch with CPU or CUDA from following links:
```bash
CPU: https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.12.0%2Bcpu.zip
CUDA: https://download.pytorch.org/libtorch/cu116/libtorch-cxx11-abi-shared-with-deps-1.12.0%2Bcu116.zip
```
Unzip the file and set the environment path in .bashrc:

```bash
export LIBTORCH=$libtorchDir$/libtorch
export LD_LIBRARY_PATH=${LIBTORCH}/lib:$LD_LIBRARY_PATH
source .bashrc
```
or in 'envConfig' of work directory:
```bash
export LIBTORCH=$libtorchDir$/libtorch
export LD_LIBRARY_PATH=${LIBTORCH}/lib:$LD_LIBRARY_PATH
source envConfig
```
## Prepare rust data for rust_hero test (optional):
50 rust files for testing is elaboratly selected from open-source rust project including on `rust-openssl`, `tokio`, `anyhow`, `hyper`, `rand`, `regex` and `rayon`:
```bash
bash ./scripts/prepare_data.sh
```
## Example usage for rust_hero:

```bash
cargo run data/error.rs
```
`rust_hero` also supports classifling all rust files of one directory:
```bash
cargo run data/
```