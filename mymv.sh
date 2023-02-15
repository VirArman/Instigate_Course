#!/bin/bash
move_file() {
  # Check that the correct number of arguments have been provided
  if [ $# -ne 2 ]; then
    echo "Usage: move_file <source_file> <destination_file>"
    return 1
  fi

  # Check that the source file exists
  if [ ! -f "$1" ]; then
    echo "Error: $1 does not exist or is not a regular file."
    return 1
  fi

  # Check that the destination file does not already exist
  if [ -e "$2" ]; then
    echo "Error: $2 already exists."
    return 1
  fi

  # Copy the file to the new location
  cp "$1" "$2"

  # Remove the original file
  rm "$1"

  echo "Moved $1 to $2."
}
function main {
    move_file
}
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
