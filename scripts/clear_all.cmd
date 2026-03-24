:: :.:.:.:.:.:.:
:: clear_all.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\clear.cmd

IF EXIST bin   RMDIR /S /Q bin
IF EXIST x86   RMDIR /S /Q x86
IF EXIST x64   RMDIR /S /Q x64
IF EXIST ARM64 RMDIR /S /Q ARM64

POPD

EXIT /B 0
