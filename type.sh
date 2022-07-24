grep "type" vendor/tree-sitter-asm/src/node-types.json | awk '{split($2, a, "\""); print a[2];}' > ~/Documents/github.com/gkoumasd/Rust_CORDER/vocab/treesitter_asm/node_type/type2.txt
