:: :.:.:.:.:.:.:
:: clear_all.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\clear.cmd

FOR /F %%D in (scripts\projects.txt) DO (
    SET   BIN=%%D\bin
    SET   X86=%%D\x86
    SET   X64=%%D\x64
    SET ARM64=%%D\ARM64

    IF EXIST   !BIN! RMDIR /S /Q !BIN!
    IF EXIST   !X86! RMDIR /S /Q !X86!
    IF EXIST   !X64! RMDIR /S /Q !X64!
    IF EXIST !ARM64! RMDIR /S /Q !ARM64!
)

SET   BIN=bin
SET   X86=x86
SET   X64=x64
SET ARM64=ARM64

IF EXIST   !BIN! RMDIR /S /Q !BIN!
IF EXIST   !X86! RMDIR /S /Q !X86!
IF EXIST   !X64! RMDIR /S /Q !X64!
IF EXIST !ARM64! RMDIR /S /Q !ARM64!

POPD

EXIT /B 0
