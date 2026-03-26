:: :.:.:.:.:.:.
:: pack_all.cmd
:: :.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\pack.cmd

SET /P VERSION=<VERSION

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Debug\*' -DestinationPath 'bin\gwc-d-x86-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Debug\*' -DestinationPath 'bin\gwc-d-x64-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Debug\*' -DestinationPath 'bin\gwc-d-ARM64-!VERSION!.zip'"

POPD

EXIT /B 0
