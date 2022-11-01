# Rust Hero extension for Visual Studio Code

This extension is a rust assistant that utilizes NLP to enhance the quality of rust code. It supports `unsafe` and `lifetime` (todo) prediction.

## Author
`Vincent-Xiao, Yijun Yu`
## Features
* Predict the `unsafe` and `lifetime` of rust source file.
    * You can predict current file in open window
    * You can predict all rust files in open workspace

## Development and Debug
1. Install rust_hero crate from local repository 
```bash
cargo install --path .
```
or cartes.io
```bash
cargo install rust_hero
```
2. Install `Node.js` and dependence:
```bash
npm install -g yo generator-code
npm run compile
```
and compile project
```bash
npm run compile
```
1. Open project in Vscode and press `F5`. This will compile and run the extension in a new Extension Development Host window.
4. Run `Rust Hero: Workspace` or `Rust Hero: Current File` from the Command Palette (Ctrl+Shift+P). This prediction result will be shown in terminal.
5. Package rust-hero to rust-hero-*.vsix
```bash
npm install -g vsce
vsce package
```
## Installation and Usage
1. Install rust_hero crate from local repository or cartes.io

2. Install rust-hero-*.vsix from vscode extension market.
3. Run `Rust Hero: Workspace` or `Rust Hero: Current File` from the Command Palette (Ctrl+Shift+P). This prediction result will be shown in terminal.

## Release Notes
### v0.1.0

* Initial release