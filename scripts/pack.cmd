:: :.:.:.:.
:: pack.cmd
:: :.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

IF NOT EXIST "dist" (
    MKDIR "dist"
)

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Debug\*' -DestinationPath 'dist\gwc-d-x86-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Debug\*' -DestinationPath 'dist\gwc-d-x64-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Debug\*' -DestinationPath 'dist\gwc-d-ARM64-!VERSION!.zip'"

POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x86\Release\*' -DestinationPath 'dist\gwc-x86-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\x64\Release\*' -DestinationPath 'dist\gwc-x64-!VERSION!.zip'"
POWERSHELL -Command "Compress-Archive -Force -Path 'bin\ARM64\Release\*' -DestinationPath 'dist\gwc-ARM64-!VERSION!.zip'"

POWERSHELL -Command "Get-ChildItem 'gwc.native' -File | Where-Object { (Get-Content 'config\include.txt') -Contains $_.Name } | Compress-Archive -Force -DestinationPath 'dist\gwc-include-!VERSION!.zip'"

POPD

EXIT /B 0
