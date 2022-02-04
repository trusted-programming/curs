import os
from torch.utils.data import DataLoader, RandomSampler, SequentialSampler

class Load_Data():
     def __init__(self, dataset, batch_size: int):
         self.dataset = dataset
         self.batch_size = batch_size
    
     def loader(self):
         dataset = self.dataset
         return DataLoader(
                dataset, # The validation samples.
                sampler = SequentialSampler(dataset), # Pull out batches sequentially.
                batch_size = self.batch_size # Evaluate with this batch size.
         )
