#!/bin/bash

pushd "$(dirname "$0")/.." >/dev/null

bash "scripts\build.sh"

if ! command -v msbuild >/dev/null 2>&1; then
    exit 1
fi

msbuild gwc.sln /t:gwc_mono /p:Configuration=Debug /p:Platform=x86
msbuild gwc.sln /t:gwc_mono /p:Configuration=Debug /p:Platform=x64

popd >/dev/null
