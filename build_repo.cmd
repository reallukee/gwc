:: :.:.:.:.:.:.:.
:: build_repo.cmd
:: :.:.:.:.:.:.:.

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0"

:: BUILD GWC
CALL scripts\build_all.cmd
CALL scripts\pack.cmd

:: BUILD GWC TEMPLATES
CALL scripts\templates.build_all.cmd
CALL scripts\templates.pack.cmd

POPD

EXIT /B 0
