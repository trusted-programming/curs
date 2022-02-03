import sys
import argparse
import random
import pickle
import os
import re
import copy
import time
import copy
import numpy as np
import tensorflow.compat.v1 as tf
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import warnings
warnings.filterwarnings("ignore")
import logging
logging.getLogger('tensorflow').disabled = True
tf.compat.v1.logging.set_verbosity(tf.compat.v1.logging.ERROR)
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score, f1_score, precision_score, recall_score
from datetime import datetime
from keras_radam.training import RAdamOptimizer
np.set_printoptions(threshold=sys.maxsize)
tf.compat.v1.disable_eager_execution()
tf.disable_v2_behavior()

from .treesitter_rust_data_processor import TreeSitterRustDataProcessor
from .base_data_loader import BaseDataLoader
from .util.threaded_iterator import ThreadedIterator
from .util.network.tbcnn import TBCNN
from .util import util_functions

import curious

def parse_arguments(): 
    parser = argparse.ArgumentParser()
    parser.add_argument('--worker', type=int,
                        help='number of data loading workers', default=1)
    parser.add_argument('--batch_size', type=int,
                        default=1, help='input batch size')
    parser.add_argument('--label_size', type=int, default=2,
                    help='number of labels')
    parser.add_argument('--node_type_dim', type=int, default=100,
                        help='node type dimension size')
    parser.add_argument('--node_token_dim', type=int,
                        default=100, help='node token dimension size')
    parser.add_argument('--conv_output_dim', type=int,
                        default=100, help='size of convolutional output')
    parser.add_argument('--hidden_layer_size', type=int,
                        default=100, help='size of hidden layer')
    parser.add_argument('--num_hidden_layer', type=int,
                        default=1, help='number of hidden layer')
    parser.add_argument('--epochs', type=int, default=20,
                        help='number of epochs to train for')
    parser.add_argument('--lr', type=float, default=0.001, help='learning rate')
    parser.add_argument('--cuda', default="1", type=str, help='enables cuda')
    parser.add_argument('--verbal', type=bool, default=True,
                        help='print training info or not')
    parser.add_argument('--model_path', default=os.path.join(os.path.dirname(os.path.abspath(curious.__file__)), 'tbcnn'),
                        help='path to save the model')
    parser.add_argument('--n_hidden', type=int, default=50,
                        help='number of hidden layers')
    parser.add_argument('--log_path', default="logs/",
                        help='log path for tensorboard')
    parser.add_argument('--checkpoint_every', type=int,
                        default=50, help='check point to save model')
    parser.add_argument('--validating', type=int,
                        default=1, help='validating or not')
    parser.add_argument('--tree_size_threshold_upper', type=int,
                        default=100 , help='tree size threshold')
    parser.add_argument('--tree_size_threshold_lower', type=int,
                        default=0, help='tree size threshold')                   
    parser.add_argument('--sampling_size', type=int,
                        default=60, help='sampling size for each epoch')
    parser.add_argument('--best_f1', type=float,
                        default=0.0, help='best f1 to save model')
    parser.add_argument('--test_path', default="/tmp/treesitter_rust-buckets.pkl",
                        help='path of testing data')
    parser.add_argument('--node_type_vocabulary_path', default=os.path.join(os.path.dirname(os.path.abspath(curious.__file__)), 'vocab', 'type.txt'),
                        help='the path to node type vocab')
    parser.add_argument('--token_vocabulary_path', default=os.path.join(os.path.dirname(os.path.abspath(curious.__file__)), 'vocab', 'token.txt'),
                        help='the path to node token vocab')
    parser.add_argument('--task', type=int, default=0,
                        choices=range(0, 2), help='0 for training, 1 for testing')
    parser.add_argument('--num_files_threshold', type=int, default=20000)
    parser.add_argument('--num_conv', type=int, default=2)
    parser.add_argument('--node_init', type=int,
                        default=2, help='including token for initializing or not, 1 for including only token, 0 for including only type, 2 for both')
    parser.add_argument('--static_caps_num_caps', type=int, default=50)
    parser.add_argument('--static_caps_output_dimension', type=int, default=8)
    parser.add_argument('--code_caps_output_dimension', type=int, default=8)
    parser.add_argument('--top_a', type=int, default=10)
    parser.add_argument('files', nargs='+', help='file to infer', type=open)
    opt = parser.parse_args()
    return opt

if __name__ == "__main__":
    opt = parse_arguments()
    processor = TreeSitterRustDataProcessor(opt.node_type_vocabulary_path, opt.token_vocabulary_path, opt.files, opt.test_path)
    os.environ['CUDA_VISIBLE_DEVICES'] = "0"
    checkfile = os.path.join(opt.model_path, 'cnn_tree.ckpt')
    ckpt = tf.train.get_checkpoint_state(opt.model_path)
    if not (ckpt and ckpt.model_checkpoint_path):
        print('Failed to upload the pretrained model')   
    tbcnn_model = TBCNN(opt)
    tbcnn_model.feed_forward()
    test_data_loader = BaseDataLoader(1, opt.tree_size_threshold_upper, opt.tree_size_threshold_lower, opt.test_path, False)

    saver = tf.train.Saver(save_relative_paths=True, max_to_keep=5)  
    init = tf.global_variables_initializer()
    with tf.Session() as sess:
        sess.run(init)
        if ckpt and ckpt.model_checkpoint_path:
            # print("Checkpoint path : " + str(ckpt.model_checkpoint_path))
            saver.restore(sess, ckpt.model_checkpoint_path)
        test_batch_iterator = ThreadedIterator(test_data_loader.make_minibatch_iterator(), max_queue_size=opt.worker)
        for test_step, test_batch_data in enumerate(test_batch_iterator):
            scores = sess.run(
                    [tbcnn_model.softmax],
                    feed_dict={
                        tbcnn_model.placeholders["node_type"]: test_batch_data["batch_node_type_id"],
                        tbcnn_model.placeholders["node_token"]:  test_batch_data["batch_node_sub_tokens_id"],
                        tbcnn_model.placeholders["children_index"]:  test_batch_data["batch_children_index"],
                        tbcnn_model.placeholders["children_node_type"]: test_batch_data["batch_children_node_type_id"],
                        tbcnn_model.placeholders["children_node_token"]: test_batch_data["batch_children_node_sub_tokens_id"],
                        tbcnn_model.placeholders["dropout_rate"]: 0.0
                    }
                )

            files = test_batch_data['batch_files']
            batch_predictions = list(np.argmax(scores[0],axis=1))
            confidence = np.amax(scores[0],axis=1)[0]
            if batch_predictions[0]==0:
                   print('%s: Safe (%.3f).'%(files[0],confidence))
            elif batch_predictions[0]==1:
                   print('%s: Unsafe (%.3f).'%(files[0],confidence))
            else:
                   print('Uknown category')
