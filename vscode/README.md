
# VSCode plugin for curs -- A tool to predict if a Rust function is safe.

## User's Guide

After the installation, you can invoke "curs" by right click and choose the "curs / Predict function safety of this file".  

Wait a minute or so, the editor will highlight all the Rust function names in yellow, and show the predicted Safe/Unsafe probability in red to the right 
of the line of the function declaration:

To check whether the configuration is OK, open a new Terminal and enter in the console the following command, e.g.,

```bash
cp ../target/release/build/torch-sys-*/out/libtorch/libtorch/lib/*.so* ~/.cargo/bin
export LD_LIBRARY_PATH=~/.cargo/bin
rust_hero error.rs
```

If it returns some CSV text to the console, then the configuration would work as expected.

## VSCode Extension Develop Environment Setup

The following instruction guide the environment configuration for the VSCode editor and all necessary components:

* Run `npm install` under the project folder to initialize the project and install necessary dependencies.

### VSCode Extension Publish Procedure

1. Install VSCE (Visual Studio Code Extensions) tool with `npm install -g vsce`.

2. Package the extension by executing `vsce package` under the extension folder. You should found a generated vsix package file under the same folder upon successful execution.

