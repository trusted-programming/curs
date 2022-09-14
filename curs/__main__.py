import torch
from tqdm import tqdm
import argparse
import numpy as np
import os
import pickle5 as pickle
import random
import re
import shutil
import sys
import time
import tensorflow.compat.v1 as tf
import torch.nn.functional as F

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import warnings

warnings.filterwarnings("ignore")
import logging

logging.basicConfig(level=logging.ERROR)
logging.getLogger('tensorflow').disabled = True
tf.compat.v1.logging.set_verbosity(tf.compat.v1.logging.ERROR)
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score, f1_score, precision_score, recall_score
from datetime import datetime
from keras_radam.training import RAdamOptimizer

np.set_printoptions(threshold=sys.maxsize)
tf.compat.v1.disable_eager_execution()
tf.disable_v2_behavior()

from .load_data import Load_Data
from .model import RobertaClass
from .tokenizer import Tokenizer
from .treesitter_rust_data_processor import TreeSitterRustDataProcessor
from .base_data_loader import BaseDataLoader
from .util.threaded_iterator import ThreadedIterator
from .util.network.tbcnn import TBCNN
from .util import util_functions
import curs


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('--worker',
                        type=int,
                        help='number of data loading workers',
                        default=1)
    parser.add_argument('--batch_size',
                        type=int,
                        default=1,
                        help='input batch size')
    parser.add_argument('--label_size',
                        type=int,
                        default=2,
                        help='number of labels')
    parser.add_argument('--node_type_dim',
                        type=int,
                        default=100,
                        help='node type dimension size')
    parser.add_argument('--node_token_dim',
                        type=int,
                        default=100,
                        help='node token dimension size')
    parser.add_argument('--conv_output_dim',
                        type=int,
                        default=100,
                        help='size of convolutional output')
    parser.add_argument('--hidden_layer_size',
                        type=int,
                        default=100,
                        help='size of hidden layer')
    parser.add_argument('--num_hidden_layer',
                        type=int,
                        default=1,
                        help='number of hidden layer')
    parser.add_argument('--epochs',
                        type=int,
                        default=20,
                        help='number of epochs to train for')
    parser.add_argument('--lr',
                        type=float,
                        default=0.001,
                        help='learning rate')
    parser.add_argument('--cuda', default="1", type=str, help='enables cuda')
    parser.add_argument('--verbal',
                        type=bool,
                        default=True,
                        help='print training info or not')
    parser.add_argument('--model',
                        default='codeBERT',
                        help='model: tbcnn, codeBERT')
    parser.add_argument('--model_path',
                        default=os.path.join(
                            os.path.dirname(os.path.abspath(curs.__file__)),
                            'tbcnn'),
                        help='path to save the model')
    parser.add_argument('--n_hidden',
                        type=int,
                        default=50,
                        help='number of hidden layers')
    parser.add_argument('--log_path',
                        default="logs/",
                        help='log path for tensorboard')
    parser.add_argument('--checkpoint_every',
                        type=int,
                        default=50,
                        help='check point to save model')
    parser.add_argument('--validating',
                        type=int,
                        default=1,
                        help='validating or not')
    parser.add_argument('--tree_size_threshold_upper',
                        type=int,
                        default=100,
                        help='tree size threshold')
    parser.add_argument('--tree_size_threshold_lower',
                        type=int,
                        default=0,
                        help='tree size threshold')
    parser.add_argument('--sampling_size',
                        type=int,
                        default=60,
                        help='sampling size for each epoch')
    parser.add_argument('--best_f1',
                        type=float,
                        default=0.0,
                        help='best f1 to save model')
    parser.add_argument('--test_path',
                        default="/tmp/treesitter_rust-buckets.pkl",
                        help='path of testing data')
    parser.add_argument('--node_type_vocabulary_path',
                        default=os.path.join(
                            os.path.dirname(os.path.abspath(curs.__file__)),
                            'vocab', 'type.txt'),
                        help='the path to node type vocab')
    parser.add_argument('--token_vocabulary_path',
                        default=os.path.join(
                            os.path.dirname(os.path.abspath(curs.__file__)),
                            'vocab', 'token.txt'),
                        help='the path to node token vocab')
    parser.add_argument('--task',
                        type=int,
                        default=0,
                        choices=range(0, 2),
                        help='0 for training, 1 for testing')
    parser.add_argument('--num_files_threshold', type=int, default=20000)
    parser.add_argument('--num_conv', type=int, default=2)
    parser.add_argument(
        '--node_init',
        type=int,
        default=2,
        help=
        'including token for initializing or not, 1 for including only token, 0 for including only type, 2 for both'
    )
    parser.add_argument('--static_caps_num_caps', type=int, default=50)
    parser.add_argument('--static_caps_output_dimension', type=int, default=8)
    parser.add_argument('--code_caps_output_dimension', type=int, default=8)
    parser.add_argument('--top_a', type=int, default=10)
    parser.add_argument('files', nargs='+', help='file to infer', type=open)
    opt = parser.parse_args()
    return opt


def inference(model_file, datasets, files, device):
    infer_dataloader = Load_Data(datasets, 1)
    infer_data = infer_dataloader.loader()
    model = RobertaClass()
    if os.path.exists(model_file):
        model_py = os.path.join(
            os.path.dirname(os.path.abspath(curs.__file__)), 'model.py')
        shutil.copyfile(model_py, "model.py")
        model = torch.load(model_file, map_location=device)
    else:
        print(
            'Caution! The pre-trained load model does not exist, you cannot reprocude the results'
        )
    model.eval()
    #Inference
    # print(torch.cuda.device_count())
    if torch.cuda.device_count() > 1:
        print('You use %d GPUs' % torch.cuda.device_count())
        model = nn.DataParallel(model, device_ids=[0, 1, 2, 3])
        torch.cuda.set_device(int(opt.cuda))
        model.cuda(int(opt.cuda))
    for step, data in enumerate(infer_data):
        #Load data
        input_ids = data[0].to(device)
        attention_masks = data[1].to(device)
        token_type_ids = data[2].to(device)
        file = files[step]
        with torch.no_grad():
            #Calculate loss
            outputs = model(input_ids, attention_masks, token_type_ids)
            # print(outputs)
            probabilities = F.softmax(outputs, dim=-1)
            max_val, max_idx = torch.max(outputs.data, dim=1)
            if max_idx == 0:
                result = 'Safe'
            else:
                result = 'Unsafe'
            print('%s,%s(prob=%.2f)' %
                  (file, result, probabilities[0][max_idx].item()))


if __name__ == "__main__":
    opt = parse_arguments()
    if opt.model != "":
        opt.model_path = os.path.join(
            os.path.dirname(os.path.abspath(curs.__file__)), opt.model)
    if opt.model == "tbcnn":
        processor = TreeSitterRustDataProcessor(opt.node_type_vocabulary_path,
                                                opt.token_vocabulary_path,
                                                opt.files, opt.test_path)
        os.environ['CUDA_VISIBLE_DEVICES'] = "0"
        checkfile = os.path.join(opt.model_path, 'cnn_tree.ckpt')
        ckpt = tf.train.get_checkpoint_state(opt.model_path)
        if not (ckpt and ckpt.model_checkpoint_path):
            print('Failed to upload the pretrained model')
        tbcnn_model = TBCNN(opt)
        tbcnn_model.feed_forward()
        test_data_loader = BaseDataLoader(1, opt.tree_size_threshold_upper,
                                          opt.tree_size_threshold_lower,
                                          opt.test_path, False)

        saver = tf.train.Saver(save_relative_paths=True, max_to_keep=5)
        init = tf.global_variables_initializer()
        with tf.Session() as sess:
            sess.run(init)
            if ckpt and ckpt.model_checkpoint_path:
                # print("Checkpoint path : " + str(ckpt.model_checkpoint_path))
                saver.restore(sess, ckpt.model_checkpoint_path)
            test_batch_iterator = ThreadedIterator(
                test_data_loader.make_minibatch_iterator(),
                max_queue_size=opt.worker)
            for test_step, test_batch_data in enumerate(test_batch_iterator):
                scores = sess.run(
                    [tbcnn_model.softmax],
                    feed_dict={
                        tbcnn_model.placeholders["node_type"]:
                        test_batch_data["batch_node_type_id"],
                        tbcnn_model.placeholders["node_token"]:
                        test_batch_data["batch_node_sub_tokens_id"],
                        tbcnn_model.placeholders["children_index"]:
                        test_batch_data["batch_children_index"],
                        tbcnn_model.placeholders["children_node_type"]:
                        test_batch_data["batch_children_node_type_id"],
                        tbcnn_model.placeholders["children_node_token"]:
                        test_batch_data["batch_children_node_sub_tokens_id"],
                        tbcnn_model.placeholders["dropout_rate"]:
                        0.0
                    })
                files = test_batch_data['batch_files']
                batch_predictions = list(np.argmax(scores[0], axis=1))
                confidence = np.amax(scores[0], axis=1)[0]
                if batch_predictions[0] == 0:
                    print('%s,Safe(%.3f).' % (files[0], confidence))
                elif batch_predictions[0] == 1:
                    print('%s,Unsafe(%.3f).' % (files[0], confidence))
                else:
                    print('Uknown category')
    else:
        # os.environ['CUDA_VISIBLE_DEVICES'] = '-1'
        # USE_CUDA = False
        USE_CUDA = torch.cuda.is_available()
        device = torch.device("cuda" if USE_CUDA else "cpu")
        if device == torch.device("cpu"):
            print("inference device: cpu")
        else:
            print("inference device: cuda")
        seed_val = 42
        random.seed(seed_val)
        torch.manual_seed(seed_val)
        torch.cuda.manual_seed_all(seed_val)
        tokenizer = Tokenizer(opt.files)
        dataset, files = tokenizer.tokenize()
        model = os.path.join(opt.model_path, 'pytorch_model.bin')
        inference(model, dataset, files, device)
