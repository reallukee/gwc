#!/bin/bash

pushd "$(dirname "$0")/.." >/dev/null

while IFS= read -r D; do
    VS="$D/.vs"
    OBJ="$D/obj"

    [ -d "$VS" ]  && rm -rf "$VS"  >/dev/null 2>&1
    [ -d "$OBJ" ] && rm -rf "$OBJ" >/dev/null 2>&1
done < config/projects.txt

VS=".vs"
OBJ="obj"

[ -d "$VS" ]  && rm -rf "$VS"  >/dev/null 2>&1
[ -d "$OBJ" ] && rm -rf "$OBJ" >/dev/null 2>&1

popd >/dev/null
