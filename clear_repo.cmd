:: :.:.:.:.:
:: build.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0"

:: CLEAR GWC
CALL scripts\clear_all.cmd

:: CLEAR GWC TEMPLATES
CALL scripts\templates.clear_all.cmd

POPD

EXIT /B 0
