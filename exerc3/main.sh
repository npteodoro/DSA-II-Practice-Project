#!/bin/bash

# Compile the program
gcc -Wall -o main main.c student.c probing.c table.c hash.c transform.c \
digit.c prime.c file.c commands.c test.c -I. 

# Run the program with all arguments passed to the script
./main "$@"