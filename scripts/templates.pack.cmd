:: :.:.:.:.:.:.:.:.:.
:: templates.pack.cmd
:: :.:.:.:.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

IF NOT EXIST "templates\dist" (
    MKDIR "templates\dist"
)

FOR /F %%D in (config\templates.txt) DO (
    POWERSHELL -Command "Compress-Archive -Force -Path 'templates\%%D\*' -DestinationPath 'templates\dist\%%D-!VERSION!.zip'"
)

POPD

EXIT /B 0
