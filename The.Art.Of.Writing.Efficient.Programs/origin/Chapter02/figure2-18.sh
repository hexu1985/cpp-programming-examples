#!/bin/bash

set -x

pprof --pdf ./example prof.data > prof.pdf
