#!/bin/bash
echo "Preparing test data for curs"
rm -rf data && rm -rf .cache/data
mkdir data
mkdir -p .cache/data && cd .cache/data

git clone https://github.com/sfackler/rust-openssl.git
cd rust-openssl && git checkout 5b1813fb15e4ceb77fbeb991143f302d242d32d5 && cd ..
git clone https://github.com/tokio-rs/tokio.git
cd tokio && git checkout 580dc9594c8e42b7d2dec60447f35238b8dfcf35 && cd ..
git clone https://github.com/dtolnay/anyhow.git
cd anyhow && git checkout b73a04a68dc3ab9c06f86a67cb63e835bebe1f4e && cd ..
git clone https://github.com/hyperium/hyper.git
cd hyper && git checkout c734b7904d615b8eaa5a5c1a8aa55d4e9ae56a6c && cd ..
git clone https://github.com/rust-random/rand.git
cd rand && git checkout 8792268dfe57e49bb4518190bf4fe66176759a44 && cd ..
git clone https://github.com/rust-lang/regex.git
cd regex && git checkout 9f9f693768c584971a4d53bc3c586c33ed3a6831 && cd ..
git clone https://github.com/rayon-rs/rayon.git
cd rayon && git checkout 93d909195b2166890c898a0f08fadda0b3b0bfc5 && cd ..

cp rust-openssl/openssl-sys/src/ssl.rs ../../data/
cp rust-openssl/openssl-errors/src/lib.rs ../../data/
cp rust-openssl/openssl/src/sign.rs ../../data/
cp rust-openssl/openssl/src/symm.rs ../../data/
cp rust-openssl/openssl/src/ocsp.rs ../../data/
cp rust-openssl/openssl/src/ssl/bio.rs ../../data/
cp rust-openssl/openssl/src/ssl/callbacks.rs ../../data/
cp rust-openssl/openssl/src/ssl/test/mod.rs ../../data/
cp rust-openssl/openssl/src/ssl/mod.rs ../../data/mod1.rs
cp rust-openssl/openssl/src/stack.rs ../../data/
cp rust-openssl/openssl/src/hash.rs ../../data/
cp rust-openssl/openssl/src/rsa.rs ../../data/


cp tokio/tokio/tests/io_buf_reader.rs ../../data/
cp tokio/tokio/src/io/read_buf.rs ../../data/
cp tokio/tokio/src/io/async_write.rs ../../data/
cp tokio/tokio/src/io/stdio_common.rs ../../data/
cp tokio/tokio/src/runtime/task/harness.rs ../../data/
cp tokio/tokio/src/runtime/task/state.rs ../../data/
cp tokio/tokio/src/runtime/task/core.rs ../../data/
cp tokio/tokio/src/runtime/task/raw.rs ../../data/
cp tokio/tokio/src/runtime/queue.rs ../../data/
cp tokio/tokio/src/runtime/thread_pool/worker.rs ../../data/
cp tokio/tokio/src/time/driver/entry.rs ../../data/
cp tokio/tokio/src/util/linked_list.rs ../../data/
cp tokio/tokio/src/util/slab.rs ../../data/
cp tokio/tokio/src/park/thread.rs ../../data/
cp tokio/tokio/src/signal/unix.rs ../../data/
cp tokio/tokio/src/sync/batch_semaphore.rs ../../data/
cp tokio/tokio/src/sync/mutex.rs ../../data/
cp tokio/tokio/src/sync/mpsc/bounded.rs ../../data/
cp tokio/tokio-util/src/sync/cancellation_token.rs ../../data/


cp anyhow/src/ptr.rs ../../data/
cp anyhow/src/error.rs ../../data/


cp hyper/tests/server.rs ../../data/
cp hyper/src/client/connect/http.rs ../../data/
cp hyper/src/proto/h1/io.rs ../../data/
cp hyper/src/proto/h1/conn.rs ../../data/
cp hyper/src/upgrade.rs ../../data/


cp rand/rand_core/src/lib.rs ../../data/lib1.rs
cp rand/rand_core/src/block.rs ../../data/
cp rand/rand_chacha/src/guts.rs ../../data/


cp regex/regex-syntax/src/hir/literal/mod.rs ../../data/mod2.rs
cp regex/bench/src/ffi/tcl.rs ../../data/
cp regex/src/dfa.rs ../../data/
cp regex/src/compile.rs ../../data/


cp rayon/rayon-core/src/latch.rs ../../data/
cp rayon/rayon-core/src/registry.rs ../../data/
cp rayon/src/slice/mergesort.rs ../../data/
cp rayon/rayon-core/src/join/test.rs ../../data/
cp rayon/rayon-core/src/job.rs ../../data/

echo "Preparing test data for curs done!"