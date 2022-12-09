from pathlib import Path
import numpy as np
import torch
import subprocess
import argparse
import sys
import collections
import os

from torch import Tensor
# https://github.com/guillaume-be/rust-bert/issues/219
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--source_file",
                        default="codeBERT_pl.bin",
                        help="Path to the Pytorch weights file to convert")
    parser.add_argument("--target_file",
                        default="rust_model",
                        help="Path to the Pytorch weights file to store")
    parser.add_argument("--skip_embeddings",
                        action="store_true",
                        help="Skip shared embeddings / language model head")
    parser.add_argument("--key",
                        default="codeBert",
                        help="replace name of parameters")
    parser.add_argument("--prefix",
                        default="roberta",
                        help="replace prefix of parameters")
    args = parser.parse_args()

    source_file = Path(args.source_file)
    target_folder = source_file.parent
    model = torch.load(str(source_file), map_location='cpu')
    # torch.save(model.state_dict(), target_folder + args.target_file + ".bin")
    # model = torch.load(target_folder + args.target_file + ".bin",
    #                    map_location='cpu')

# for name, parameters in model.items():
#     print(name, ':', parameters.size())
nps = {}
for name, parameters in model.items():
    # print(name, ':', parameters.size())
    name = name.replace("gamma", "weight").replace("beta", "bias")
    if args.skip_embeddings:
        if name in {
                "lm_head.weight", "model.encoder.embed_tokens.weight",
                "model.decoder.embed_tokens.weight"
        }:
            continue
    if isinstance(parameters, Tensor):
        if args.key in name:
            name = name.replace(args.key, args.prefix)
            nps[name] = np.ascontiguousarray(parameters.cpu().numpy().astype(
                np.float32))
        if "module." in name:
            name = name.replace("module.", "")
            nps[name] = np.ascontiguousarray(parameters.cpu().numpy().astype(
                np.float32))
        if "fc" in name:
            name = name.replace("fc", "classifier.dense")
            nps[name] = np.ascontiguousarray(parameters.cpu().numpy().astype(
                np.float32))
        elif "classifier" in name:
            name = name.replace("classifier", "classifier.out_proj")
            nps[name] = np.ascontiguousarray(parameters.cpu().numpy().astype(
                np.float32))
        else:
            nps[name] = np.ascontiguousarray(parameters.cpu().numpy().astype(
                np.float32))
        print(f'converted {name} - {parameters.size()} bytes')
    else:
        print(f'skipped non-tensor object: {name}')
np.savez(target_folder / 'model.npz', **nps)

source = str(target_folder / 'model.npz')
target = str(target_folder / 'rust_model.ot')

toml_location = (Path(__file__).resolve() / '..' / '..' /
                 'Cargo.toml').resolve()
subprocess.run([
    'cargo', 'run', '--bin=convert-tensor',
    '--manifest-path=%s' % toml_location, '--', source, target
], )
