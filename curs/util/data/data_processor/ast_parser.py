from pathlib import Path
from os import path
import glob, os
from tree_sitter import Language, Parser
from tqdm import tqdm
import urllib.request
from urllib3.exceptions import InsecureRequestWarning

import zipfile
import shutil

import ssl
ssl._create_default_https_context = ssl._create_unverified_context

class DownloadProgressBar(tqdm):
    def update_to(self, b=1, bsize=1, tsize=None):
        if tsize is not None:
            self.total = tsize
        self.update(b * bsize - self.n)


def download_url(url, output_path):
    with DownloadProgressBar(unit='B', unit_scale=True,
                             miniters=1, desc=url.split('/')[-1]) as t:
        if (not os.environ.get('PYTHONHTTPSVERIFY', '') and getattr(ssl, '_create_unverified_context', None)):
           ssl._create_default_https_context = ssl._create_unverified_context
        urllib.request.urlretrieve(url, filename=output_path, reporthook=t.update_to)

class ASTParser():
    import logging
    LOGGER = logging.getLogger('ASTParser')
    
    def __init__(self, language='rust'):
         # ------------ To initialize for the treesitter parser ------------
        home = str(Path.home())
        cd = os.getcwd()
        
        p = path.join(home, ".tree-sitter")
        
        if not path.exists(p):
            os.makedirs(p, exist_ok=True)
            zip_url = "https://github.com/yijunyu/tree-sitter-parsers/archive/refs/heads/main.zip"
            parsers_target = os.path.join(p, "main.zip")
            download_url(zip_url, parsers_target)
            with zipfile.ZipFile(parsers_target, 'r') as zip_ref:
          	        zip_ref.extractall(p)
          	        shutil.move(path.join(p, "tree-sitter-parsers-main"), path.join(p, "bin"))
          	        os.remove(parsers_target)
        
        p = path.join(p, "bin")
        os.chdir(p)   
        
        langs = []
        for file in glob.glob("tree-sitter-*"):        
            lang = file.split("-")[2]
            if not "." in file.split("-")[3]: # c-sharp => c_sharp.so
                lang = lang + "_" + file.split("-")[3]
            langs.append(file)
            Language.build_library(
                # Store the library in the `build` directory
                lang + '.so',
                # Include one or more languages
                langs
            )
            
        self.Languages = {}   
        
        for file in glob.glob("*.so"):
          try:
            lang = os.path.splitext(file)[0]
            self.Languages[lang] = Language(path.join(p, file), lang)
          except:
            print("An exception occurred to {}".format(lang))
            
        os.chdir(cd)   
        
        self.parser = Parser()
        
        self.language = language
        
        lang = self.Languages.get(self.language)
        
        self.parser.set_language(lang)
        
    def parse(self, code_snippet):
        return self.parser.parse(code_snippet)    