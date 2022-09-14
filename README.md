# Classify unsafe Rust code

For each function in Rust, the `unsafe` keyword utilizes the unsafe superpowers. However, the `unsafe` keyword is not necessary if it can be taken out while the program is compiled successfully.

`curs` infers the necessity of `unsafe` keywords without the need of recompiling. `curs` trains a [microsoft/codebert](https://github.com/microsoft/CodeBERT) based model and take advantage of bert's strong reasoning capability to inference the necessity of `unsafe`.

## Performance

It costs 2.06s and 2.90s on average for `curs` inferencing one rust file on Intel I7-12700K CPU and NVIDIA 3080 12GB GPU, seperately.

`curs` written in Rust achieves up to 6.58X and 13.04X performance speedup over `curs` written in Python language for GPU and CPU, seperately.
![Inference speedup](./Img/speedup.png)
<center>Inference speedup of Rust curs over Python curs</center>

## Installation
### Runtime dependencies for curs
```bash
sudo apt install build-essential cmake pkg-config libssl-dev wget zip git
```
Download the `tree-grepper` vendor:
```bash
bash ./scripts/runtime.sh
```
It uses `libtorch-1.12.0` to inference curs. Download the libtorch with CPU or CUDA from following links:
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
## Prepare rust data for curs test:
50 rust files for testing is elaboratly selected from open-source rust project including on `rust-openssl`, `tokio`, `anyhow`, `hyper`, `rand`, `regex` and `rayon`:
```bash
bash ./scripts/prepare_data.sh
```
## Example usage for curs:

```bash
cargo run data/error.rs
```
`curs` also supports classifling all rust files of one directory:
```bash
cargo run data/
```