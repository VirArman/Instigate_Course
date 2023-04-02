#!/bin/bash

# Check if two file names were provided
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <file1> <file2>"
  exit 1
fi

# Check if both files exist
if [ ! -f "$1" ] || [ ! -f "$2" ]; then
  echo "Error: Both files must exist"
  exit 1
fi
g++ main.cpp
./a.out -t "$1" "$2"

if cmp -s $2 golden.txt; then
  echo "All tests passed"
else
  diff golden.txt $2 
fi