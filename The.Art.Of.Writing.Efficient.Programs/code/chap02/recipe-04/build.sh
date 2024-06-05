#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic compare.C example.C -o example && ./example
