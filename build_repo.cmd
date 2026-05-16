:: :.:.:.:.:
:: build.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0"

:: BUILD GWC
CALL scripts\build_all.cmd
CALL scripts\pack_all.cmd

:: BUILD GWC TEMPLATES
CALL scripts\templates.build_all.cmd
CALL scripts\templates.pack_all.cmd

POPD

EXIT /B 0
