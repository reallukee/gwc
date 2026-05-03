:: :.:.:.:.:.:.
:: pack_all.cmd
:: :.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\pack.cmd

SET /P VERSION=<VERSION

IF NOT EXIST "dist\latest" (
    MKDIR "dist\latest"
)

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Debug\*' -DestinationPath 'dist\latest\gwc-d-x86-latest.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Debug\*' -DestinationPath 'dist\latest\gwc-d-x64-latest.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Debug\*' -DestinationPath 'dist\latest\gwc-d-ARM64-latest.zip'"

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Release\*' -DestinationPath 'dist\latest\gwc-x86-latest.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Release\*' -DestinationPath 'dist\latest\gwc-x64-latest.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Release\*' -DestinationPath 'dist\latest\gwc-ARM64-latest.zip'"

POWERSHELL -Command "Get-ChildItem 'gwc.native' -File | Where-Object { (Get-Content 'config\include.txt') -Contains $_.Name } | Compress-Archive -Force -DestinationPath 'dist\latest\gwc-include.zip'"

POPD

EXIT /B 0
