#!/bin/bash

set -x
pprof --text ./example prof.data
