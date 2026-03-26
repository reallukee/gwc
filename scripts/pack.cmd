:: :.:.:.:.
:: pack.cmd
:: :.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Release\*' -DestinationPath 'bin\gwc-x86-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Release\*' -DestinationPath 'bin\gwc-x64-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Release\*' -DestinationPath 'bin\gwc-ARM64-!VERSION!.zip'"

POWERSHELL -Command "Get-ChildItem 'gwc.native' -File | Where-Object { (Get-Content 'scripts\include.txt') -Contains $_.Name } | Compress-Archive -Force -DestinationPath 'bin\gwc-include-!VERSION!.zip'"

POPD

EXIT /B 0
