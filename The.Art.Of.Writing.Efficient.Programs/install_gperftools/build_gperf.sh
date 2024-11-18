#!/bin/bash

git clone https://github.com/gperftools/gperftools
cd gperftools/
./autogen.sh
./configure --prefix=${HOME}/local/gperftools
make all
make install
#sudo ldconfig
