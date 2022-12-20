# Rust Hero extension for Visual Studio Code

This extension is an assistant to enhance the quality of Rust code. Currently it supports `unsafe` prediction.

## Author
Vincent Xiao, Dimitris Gkoumas, Yijun Yu

## Features

* Predict `unsafe` Rust functions.
    * You can predict current file in open window
    * You can predict all Rust files in open workspace

## Development and Debug

1. Install `rust_hero` crate from local repository:
```bash
cargo install --path .
```
or from [cartes.io](https://crates.io):
```bash
cargo install rust_hero
```

2. Install `Node.js` and dependencies:
```bash
cd vscode
npm install
npm install -g vsce
vsce package
```

3. Install curs-*.vsix from vscode extension market. After the installation, you can invoke "curs" by 
right click and choose "curs / Predict function safety of this file".  
