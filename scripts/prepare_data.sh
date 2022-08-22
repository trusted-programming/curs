#!/bin/bash
echo "Preparing test data for curs"
rm -rf data && rm -rf .cache/data
mkdir data
mkdir -p .cache/data && cd .cache/data

git clone https://github.com/sfackler/rust-openssl.git
cd rust-openssl && git checkout 5b1813fb15e4ceb77fbeb991143f302d242d32d5 && cd ..
mv rust-openssl/openssl-sys/src/ssl.rs ../../data/
mv rust-openssl/openssl-errors/src/lib.rs ../../data/
mv rust-openssl/openssl/src/sign.rs ../../data/
mv rust-openssl/openssl/src/symm.rs ../../data/
mv rust-openssl/openssl/src/ocsp.rs ../../data/
mv rust-openssl/openssl/src/ssl/bio.rs ../../data/
mv rust-openssl/openssl/src/ssl/callbacks.rs ../../data/
mv rust-openssl/openssl/src/ssl/test/mod.rs ../../data/
mv rust-openssl/openssl/src/ssl/mod.rs ../../data/mod1.rs
mv rust-openssl/openssl/src/stack.rs ../../data/
mv rust-openssl/openssl/src/hash.rs ../../data/
mv rust-openssl/openssl/src/rsa.rs ../../data/

git clone https://github.com/tokio-rs/tokio.git
cd tokio && git checkout 580dc9594c8e42b7d2dec60447f35238b8dfcf35 && cd ..
mv tokio/tokio/tests/io_buf_reader.rs ../../data/
mv tokio/tokio/src/io/read_buf.rs ../../data/
mv tokio/tokio/src/io/async_write.rs ../../data/
mv tokio/tokio/src/io/stdio_common.rs ../../data/
mv tokio/tokio/src/runtime/task/harness.rs ../../data/
mv tokio/tokio/src/runtime/task/state.rs ../../data/
mv tokio/tokio/src/runtime/task/core.rs ../../data/
mv tokio/tokio/src/runtime/task/raw.rs ../../data/
mv tokio/tokio/src/runtime/queue.rs ../../data/
mv tokio/tokio/src/runtime/thread_pool/worker.rs ../../data/
mv tokio/tokio/src/time/driver/entry.rs ../../data/
mv tokio/tokio/src/util/linked_list.rs ../../data/
mv tokio/tokio/src/util/slab.rs ../../data/
mv tokio/tokio/src/park/thread.rs ../../data/
mv tokio/tokio/src/signal/unix.rs ../../data/
mv tokio/tokio/src/sync/batch_semaphore.rs ../../data/
mv tokio/tokio/src/sync/mutex.rs ../../data/
mv tokio/tokio/src/sync/mpsc/bounded.rs ../../data/
mv tokio/tokio-util/src/sync/cancellation_token.rs ../../data/

git clone https://github.com/dtolnay/anyhow.git
cd anyhow && git checkout b73a04a68dc3ab9c06f86a67cb63e835bebe1f4e && cd ..
mv anyhow/src/ptr.rs ../../data/
mv anyhow/src/error.rs ../../data/

git clone https://github.com/hyperium/hyper.git
cd hyper && git checkout c734b7904d615b8eaa5a5c1a8aa55d4e9ae56a6c && cd ..
mv hyper/tests/server.rs ../../data/
mv hyper/src/client/connect/http.rs ../../data/
mv hyper/src/proto/h1/io.rs ../../data/
mv hyper/src/proto/h1/conn.rs ../../data/
mv hyper/src/upgrade.rs ../../data/

git clone https://github.com/rust-random/rand.git
cd rand && git checkout 8792268dfe57e49bb4518190bf4fe66176759a44 && cd ..
mv rand/rand_core/src/lib.rs ../../data/lib1.rs
mv rand/rand_core/src/block.rs ../../data/
mv rand/rand_chacha/src/guts.rs ../../data/

git clone https://github.com/rust-lang/regex.git
cd regex && git checkout 9f9f693768c584971a4d53bc3c586c33ed3a6831 && cd ..
mv regex/regex-syntax/src/hir/literal/mod.rs ../../data/mod2.rs
mv regex/bench/src/ffi/tcl.rs ../../data/
mv regex/src/dfa.rs ../../data/
mv regex/src/compile.rs ../../data/

git clone https://github.com/rayon-rs/rayon.git
cd rayon && git checkout 93d909195b2166890c898a0f08fadda0b3b0bfc5 && cd ..
mv rayon/rayon-core/src/latch.rs ../../data/
mv rayon/rayon-core/src/registry.rs ../../data/
mv rayon/src/slice/mergesort.rs ../../data/
mv rayon/rayon-core/src/join/test.rs ../../data/
mv rayon/rayon-core/src/job.rs ../../data/

echo "Preparing test data for curs done!"