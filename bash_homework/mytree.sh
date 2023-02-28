!/bin/bash
root_dir=.
tree(){
  local dir=${1:-.} whitespacePrefix=$2 file
  for file in "$dir"/*; do
    [ -e "$file" ] || [ -L "$file" ] || continue
    if [ -d "$file" ]; then
      printf '%sDirectory %q\n' "$whitespacePrefix" "${file##*/}"
      tree "$file" "${whitespacePrefix}    "
    else
      printf '%sFile %q\n' "$whitespacePrefix" "${file##*/}"
    fi
  done

}
tree $root_dir '    '
