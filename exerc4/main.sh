#!/bin/bash
set -e

# Compilation step
echo "Compiling..."
gcc -Wall -std=c99 -o main.out main.c list.c parser.c hash.c

# Run step, forwarding any command-line arguments to the executable
echo "Running..."
./main.out "$@"
