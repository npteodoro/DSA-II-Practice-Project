#!/bin/bash

while read -r line; do
    echo "Running: ./main $line"
    eval "./main $line"
done < input.txt