import os

import glob, os
from tqdm import tqdm
from os.path import exists
import time

# ----- collect absolute paths for safe files(functions)
safe_parent_dir = "/Users/lichunmiao/Desktop/Postdoc/new-syntax_rmNoOpcodeLines_rmFrontSpace_uniq-unsafe-safe-asm/safe"
os.chdir(safe_parent_dir)
safe_files_paths = []

for file in glob.glob("*.asm"):
    safe_files_paths.append(safe_parent_dir + "/" + file)
        
# ----- collect absolute paths for unsafe files(functions)
# unsafe_parent_dir = "/Users/lichunmiao/Desktop/Postdoc/new-syntax_rmNoOpcodeLines_rmFrontSpace_uniq-unsafe-safe-asm/unsafe"
# os.chdir(unsafe_parent_dir)
# unsafe_files_paths = []

# for file in glob.glob("*.asm"):
#     unsafe_files_paths.append(unsafe_parent_dir + "/" + file)

os.chdir("/Users/lichunmiao/Desktop/Postdoc/tree-sitter-toy")

start = time.time()
for i in tqdm(range(0,len(safe_files_paths))):
    f_path = safe_files_paths[i]
    os.system("tree-sitter parse " + f_path + " --quiet --stat")
end = time.time()

print("time passed:  " + str(end-start) + "   seconds")


# One command is enough
# tree-sitter parse "/Users/lichunmiao/Desktop/Postdoc/rmexcp-com_uniq-unsafe-safe-asm/safe/*.asm" --quiet --stat

#--------------- Below are useless codes-------------------------------------------
# from fileinput import close
# import glob, os
# from tqdm import tqdm
# import sys
# import csv
# from os.path import exists

# # ----- collect absolute paths for safe files(functions) (removed exceptions and comments)
# safe_parent_dir = "/Users/lichunmiao/Desktop/Postdoc/rmexcp-com_uniq-unsafe-safe-asm/safe"
# os.chdir(safe_parent_dir)
# safe_files_paths = []

# for file in glob.glob("*.asm"):
#     safe_files_paths.append(safe_parent_dir + "/" + file)
    
# for i in tqdm(range(0, len(safe_files_paths))):
#     fPath = safe_files_paths[i]
#     test_fo = open(fPath, "r")
#     content = test_fo.read()
    
#     if not content[-1] == "\n":
#         print(fPath)
        
#     test_fo.close()
    
    