#!/bin/bash

pushd "$(dirname "$0")/.." >/dev/null

bash "scripts\clear.sh"

while IFS= read -r D; do
    BIN="$D/bin"
    DIST="$D/dist"
    X86="$D/x86"
    X64="$D/x64"
    ARM32="$D/ARM32"
    ARM64="$D/ARM64"

    [ -d "$BIN" ]   && rm -rf "$BIN"   >/dev/null 2>&1
    [ -d "$DIST" ]  && rm -rf "$DIST"  >/dev/null 2>&1
    [ -d "$X86" ]   && rm -rf "$X86"   >/dev/null 2>&1
    [ -d "$X64" ]   && rm -rf "$X64"   >/dev/null 2>&1
    [ -d "$ARM32" ] && rm -rf "$ARM32" >/dev/null 2>&1
    [ -d "$ARM64" ] && rm -rf "$ARM64" >/dev/null 2>&1
done < config/projects.txt

BIN="bin"
DIST="dist"
X86="x86"
X64="x64"
ARM32="ARM32"
ARM64="ARM64"

[ -d "$BIN" ]   && rm -rf "$BIN"   >/dev/null 2>&1
[ -d "$DIST" ]  && rm -rf "$DIST"  >/dev/null 2>&1
[ -d "$X86" ]   && rm -rf "$X86"   >/dev/null 2>&1
[ -d "$X64" ]   && rm -rf "$X64"   >/dev/null 2>&1
[ -d "$ARM32" ] && rm -rf "$ARM32" >/dev/null 2>&1
[ -d "$ARM64" ] && rm -rf "$ARM64" >/dev/null 2>&1

popd >/dev/null
