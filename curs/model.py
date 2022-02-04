import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import RobertaConfig, RobertaModel


class RobertaClass(torch.nn.Module):
    def __init__(self):
        super(RobertaClass, self).__init__()
        self.codeBert = RobertaModel.from_pretrained("microsoft/codebert-base")
        self.fc = nn.Linear(768,768)
        self.classifier = nn.Linear(768,2)
       

    def forward(self, input_ids, attention_mask, token_type_ids):
        roberta_out = self.codeBert(input_ids = input_ids, attention_mask=attention_mask, token_type_ids=token_type_ids)
        hidden_state = roberta_out[0]
        pooler = hidden_state[:,0]
        pooler = F.relu(self.fc(pooler))
        pooler = F.dropout(pooler, 0.3)
        output = self.classifier(pooler)
        
        return output
        
