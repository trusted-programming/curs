# Classify unsafe Rust code

For each function in Rust, ```curious``` infers whether it is unsafe or not.

Example usage:

```bash
python3 -m curious ~/.cargo/registry/src/github.com-1ecc6299db9ec823/anyhow-1.0.26/src/error.rs
```

## Dependencies

It uses `tree-grepper` to parse Rust functions.
```bash
cargo install --git https://github.com/BrianHicks/tree-grepper
```
