:: :.:.:.:.:.:.:.:.:.:
:: templates.clear.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

IF EXIST templates\.vs   RMDIR /S /Q templates\.vs
IF EXIST templates\bin   RMDIR /S /Q templates\bin
IF EXIST templates\obj   RMDIR /S /Q templates\obj
IF EXIST templates\x86   RMDIR /S /Q templates\x86
IF EXIST templates\x64   RMDIR /S /Q templates\x64
IF EXIST templates\ARM64 RMDIR /S /Q templates\ARM64

POPD

EXIT /B 0
