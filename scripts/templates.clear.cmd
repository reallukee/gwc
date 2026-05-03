:: :.:.:.:.:.:.:.:.:.:
:: templates.clear.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (config\templates.txt) DO (
    SET    VS=templates\.vs
    SET   BIN=templates\bin
    SET   OBJ=templates\obj
    SET   X86=templates\%%D\x86
    SET   X64=templates\%%D\x64
    SET ARM64=templates\%%D\ARM64

    IF EXIST    !VS! RMDIR /S /Q !VS!    >nul
    IF EXIST   !BIN! RMDIR /S /Q !BIN!   >nul
    IF EXIST   !OBJ! RMDIR /S /Q !OBJ!   >nul
    IF EXIST   !X86! RMDIR /S /Q !X86!   >nul
    IF EXIST   !X64! RMDIR /S /Q !X64!   >nul
    IF EXIST !ARM64! RMDIR /S /Q !ARM64! >nul
)

SET    VS=templates\.vs
SET   BIN=templates\bin
SET   OBJ=templates\obj
SET   X86=templates\x86
SET   X64=templates\x64
SET ARM64=templates\ARM64

IF EXIST    !VS! RMDIR /S /Q !VS!    >nul
IF EXIST   !BIN! RMDIR /S /Q !BIN!   >nul
IF EXIST   !OBJ! RMDIR /S /Q !OBJ!   >nul
IF EXIST   !X86! RMDIR /S /Q !X86!   >nul
IF EXIST   !X64! RMDIR /S /Q !X64!   >nul
IF EXIST !ARM64! RMDIR /S /Q !ARM64! >nul

POPD

EXIT /B 0
