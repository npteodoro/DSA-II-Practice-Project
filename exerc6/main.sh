#!/bin/bash

# Compile the program
gcc -Wall -o main main.c hanoi.c heap.c quick.c test.c -I. 

# Run the program with all arguments passed to the script
./main "$@"
