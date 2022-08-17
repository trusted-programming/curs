from tqdm import *
import os
from transformers import RobertaTokenizer
import torch
from torch.utils.data import TensorDataset
import re
import subprocess
import json
import traceback


class Tokenizer():
    def __init__(self, data_path):
        self.tokenizer = RobertaTokenizer.from_pretrained(
            "microsoft/codebert-base")
        self.data_path = data_path

    def tokenize(self):
        # Tokenize all of the code snippets and map the tokens to thier tokens IDs.
        input_ids = []
        attention_masks = []
        token_type_ids = []
        lst_files = []
        count_processed_files = 0
        cmd = [
            "tree-grepper", "--query", "rust",
            "(function_item (identifier) @id) @function", "-f", "json"
        ] + [f.name for f in self.data_path]
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE)
        (out, err) = proc.communicate()
        files = json.loads(out)
        for file in files:
            try:
                count_processed_files += 1
                matches = file['matches']
                r1 = 0
                c1 = 0
                r2 = 0
                c2 = 0
                for i in trange(0, len(matches)):
                    is_unsafe = "safe"
                    code = matches[i]
                    id = code['name']
                    if id == "id":
                        r1 = code['start']['row'] - 1
                        c1 = code['start']['column'] - 1
                        r2 = code['end']['row'] - 1
                        c2 = code['end']['column'] - 1
                        continue
                    code_snippet = code['text']
                    code_snippet2 = re.sub('unsafe fn ', '', code_snippet)
                    if code_snippet2 != code_snippet:
                        is_unsafe = "unsafe"
                        code_snippet = code_snippet2
                    # remove unsafe blocks
                    code_snippet = re.sub('unsafe ', '', code_snippet)
                    code_snippet = bytes(code_snippet, 'utf-8')
                    lst_files.append("%s,%d,%d,%d,%d" %
                                     (file['file'], r1, c1, r2, c2))
                    # print("string len is ", len(code_snippet))
                    encoded_dict = self.tokenizer.encode_plus(
                        code_snippet.decode("utf-8"),  # Sentence to encode.
                        add_special_tokens=True,  # Add '[CLS]' and '[SEP]'
                        max_length=512,  # Pad & truncate all sentences.
                        pad_to_max_length=True,
                        return_attention_mask=True,  # Construct attn. masks.
                        return_token_type_ids=True,  # Construct attn. masks.
                        return_tensors='pt',  # Return pytorch tensors.
                    )
                    # Add the encoded code snippet to the list.
                    input_ids.append(encoded_dict['input_ids'])
                    # And its attention mask (simply differentiates padding from non-padding).
                    attention_masks.append(encoded_dict['attention_mask'])
                    token_type_ids.append(encoded_dict['token_type_ids'])

            except Exception as e:
                print(traceback.format_exc())
                print(e, '??')
        # Convert the lists into tensors.
        input_ids = torch.cat(input_ids, dim=0)
        attention_masks = torch.cat(attention_masks, dim=0)
        token_type_ids = torch.cat(token_type_ids, dim=0)
        # Combine the training inputs into a TensorDataset.
        dataset = TensorDataset(input_ids, attention_masks, token_type_ids)
        return (dataset, lst_files)
