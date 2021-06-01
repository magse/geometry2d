#!/bin/sh

echo "This bootstrap script directs the install of geometry2d to your .local directory in your home directory"

cmake -S . -B build -DCMAKE_INSTALL_PREFIX=${HOME}/.local 

echo "Continue build process from the created build directory"

