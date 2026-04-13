:: :.:.:.:.:.:.:.:.:.:
:: templates.clear.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET    VS=templates\.vs
SET   BIN=templates\bin
SET   OBJ=templates\obj
SET   X86=templates\x86
SET   X64=templates\x64
SET ARM64=templates\ARM64

IF EXIST    !VS! RMDIR /S /Q !VS!
IF EXIST   !BIN! RMDIR /S /Q !BIN!
IF EXIST   !OBJ! RMDIR /S /Q !OBJ!
IF EXIST   !X86! RMDIR /S /Q !X86!
IF EXIST   !X64! RMDIR /S /Q !X64!
IF EXIST !ARM64! RMDIR /S /Q !ARM64!

POPD

EXIT /B 0
