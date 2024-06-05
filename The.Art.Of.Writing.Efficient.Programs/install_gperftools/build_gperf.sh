#!/bin/bash

git clone https://github.com/gperftools/gperftools
cd gperftools/
./autogen.sh
./configure
make all
sudo make install
sudo ldconfig
