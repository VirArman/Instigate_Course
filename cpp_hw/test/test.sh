#!/bin/bash
./a.out -t input.txt output.txt

if cmp -s output.txt golden.txt; then
  echo "The content of output and golden is identical"
else
  diff output.txt golden.txt
fi