
#!/bin/bash

# Script to compile and run the modified binary search program

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "Error: gcc compiler not found. Please install gcc."
    exit 1
fi

# Compile the program
echo "Compiling the program..."
gcc -Wall exerc2.c main.c -o exerc2

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful."

# Run the program with the provided arguments or default tests
if [ $# -eq 0 ]; then
    echo "Running with default tests..."
    ./exerc2
else
    echo "Running with provided arguments..."
    ./exerc2 "$@"
fi