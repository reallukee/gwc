:: :.:.:.:.:.:.:.:.:.:.:.
:: templates.pack_all.cmd
:: :.:.:.:.:.:.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\templates.pack.cmd

SET /P VERSION=<VERSION

IF NOT EXIST "templates\dist\latest" (
    MKDIR "templates\dist\latest"
)

FOR /F %%D in (config\templates.txt) DO (
    POWERSHELL -Command "Compress-Archive -Force -Path 'templates\%%D\*' -DestinationPath 'templates\dist\latest\%%D-latest.zip'"
)

POPD

EXIT /B 0
