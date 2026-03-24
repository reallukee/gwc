:: :.:.:.:.:
:: clear.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

IF EXIST .vs RMDIR /S /Q .vs
IF EXIST obj RMDIR /S /Q obj

POPD

EXIT /B 0
