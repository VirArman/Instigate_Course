#!/bin/bash
root_dir=$(pwd)
target=$1
find(){
    for file in $1/*; do
        if [[ -d "$file" ]]     
        then
            find "$file" $2
        elif [[ -f $file  ]] 
        then
            if [[ $file == $1/$2 ]]
            then
                # you found your file
                echo "$file"
            fi
        fi
    done
}
find $root_dir $target
