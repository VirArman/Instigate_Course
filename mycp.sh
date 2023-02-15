#!/bin/bash
cp () {
    local interactive=0

    # Handle the optional -i flag
    case "$1" in
        -i) interactive=1
            shift ;;
    esac

    # All command line arguments (not -i)
    local -a argv=( "$@" )

    # The target is at the end of argv, pull it off from there
    local target="${argv[-1]}"
    unset argv[-1]

    # Get the source file names
    local -a sources=( "${argv[@]}" )

    for source in "${sources[@]}"; do
        # Skip source files that do not exist
        if [ ! -f "$source" ]; then
            printf '"%s": no such file\n' "$source" >&2
            continue
        fi

        local _target="$target"

        if [ -d "$_target" ]; then
            # Target is a directory, put file inside
            _target="$_target/$source"
        elif (( ${#sources[@]} > 1 )); then
            # More than one source, target needs to be a directory
            printf '"%s": not a directory\n' "$target" >&2
            return 1
        fi

        if [ -d "$_target" ]; then
            # Target can not be overwritten, is directory
            printf '"%s": is a directory\n' "$_target" >&2
            continue
        fi

        if [ "$source" -ef "$_target" ]; then
            printf '"%s" and "%s" are the same file\n' "$source" "$_target" >&2
            continue
        fi

        if [ -e "$_target" ] && (( interactive )); then
            # Prompt user for overwriting target file
            printf '"%s" exists, overwrite (y/n): ' "$_target" >&2
            read
            case "$REPLY" in
                n*|N*) continue ;;
            esac
        fi

        cat -- "$source" >"$_target"
    done
}
cp $1 $2
