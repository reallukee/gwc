:: :.:.:.:.:.:.:.:.:.
:: templates.pack.cmd
:: :.:.:.:.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (scripts\templates.txt) DO (
    POWERSHELL -Command "Compress-Archive -Force -Path 'templates\%%D\*' -DestinationPath 'templates\%%D-!VERSION!.zip'"
)

POPD

EXIT /B 0
