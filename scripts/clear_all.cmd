:: :.:.:.:.:.:.:
:: clear_all.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\clear.cmd

FOR /F %%D in (config\projects.txt) DO (
    SET   BIN=%%D\bin
    SET  DIST=%%D\dist
    SET   X86=%%D\x86
    SET   X64=%%D\x64
    SET ARM64=%%D\ARM64

    IF EXIST   !BIN! RMDIR /S /Q !BIN!   >nul
    IF EXIST  !DIST! RMDIR /S /Q !DIST!  >nul
    IF EXIST   !X86! RMDIR /S /Q !X86!   >nul
    IF EXIST   !X64! RMDIR /S /Q !X64!   >nul
    IF EXIST !ARM64! RMDIR /S /Q !ARM64! >nul
)

SET   BIN=bin
SET  DIST=dist
SET   X86=x86
SET   X64=x64
SET ARM64=ARM64

IF EXIST   !BIN! RMDIR /S /Q !BIN!   >nul
IF EXIST  !DIST! RMDIR /S /Q !DIST!  >nul
IF EXIST   !X86! RMDIR /S /Q !X86!   >nul
IF EXIST   !X64! RMDIR /S /Q !X64!   >nul
IF EXIST !ARM64! RMDIR /S /Q !ARM64! >nul

POPD

EXIT /B 0
