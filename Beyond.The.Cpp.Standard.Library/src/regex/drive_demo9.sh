#!/usr/bin/env bash

echo "right regex input!"
./demo9 <<EOF
\d{5}
12345
EOF

echo "=================================="
echo "error regex input!"

./demo9 <<EOF
(\w*))
EOF
