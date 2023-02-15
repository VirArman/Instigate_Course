#!/bin/bash
root_dir=pwd
target=$1
find(){    
for file in "$1"/*; do
    if [ -d "$file" ]; then
         find "$file" $2
    elif [[ -f "$file" && $file==$2 ]]; then
        # you found your file
        echo "$file"
        exit 0
    fi
done
}
find root_dir target
