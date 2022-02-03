from setuptools import setup, find_packages

install_requires=[
    "torch==1.10.1+cu113",
    "torchaudio==0.10.1+cu113",
    "torchvision==0.11.2+cu113",
    "tqdm==4.62.3",
    "sklearn==0.0",
    "transformers==4.15.0",
    "bidict==0.21.4",
    "tree-sitter-parsers==0.0.7",
    "tensorflow==2.7.0",
    "keras-radam==0.15.0",
    "pickle5==0.0.11",
]

setup(
  name = 'curious',
  version = "0.0.1",
  py_modules = ['curious'],
  description = 'classify unsafe Rust code',
  author = 'Yijun Yu and Dimitris Gkoumas and Nghi D. Q. Bui',
  author_email = 'yijun.yu@huawei.com',
  license="MIT",
  url = 'https://github.com/yijunyu/curious',
  classifiers = [
    'Development Status :: 3 - Alpha',
    'License :: OSI Approved :: MIT License',
    'Operating System :: OS Independent',
    'Programming Language :: Python :: 3',
    'Intended Audience :: Developers',
  ],
  package_dir={"curious": "curious"},
  packages=find_packages("."),
  package_data={'curious': ['*.txt', 'tbcnn/*']},
  scripts=['./scripts/curious'],
  install_requires=install_requires,
  include_package_data=True,
)
