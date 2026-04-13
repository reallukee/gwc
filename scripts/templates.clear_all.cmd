:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.clear_all.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\templates.clear.cmd

SET /P VERSION=<VERSION

FOR /F %%D in (scripts\templates.txt) DO (
    SET INCLUDE=templates\%%D\include
    SET  STATIC=templates\%%D\static
    SET  SHARED=templates\%%D\shared
    SET     X86=templates\%%D\x86
    SET     X64=templates\%%D\x64
    SET   ARM64=templates\%%D\ARM64

    SET TEMPLATE=templates\%%D-!VERSION!.zip

    IF EXIST !INCLUDE! RMDIR /S /Q !INCLUDE! >NUL
    IF EXIST !STATIC!  RMDIR /S /Q !STATIC!  >NUL
    IF EXIST !SHARED!  RMDIR /S /Q !SHARED!  >NUL
    IF EXIST !X86!     RMDIR /S /Q !X86!     >NUL
    IF EXIST !X64!     RMDIR /S /Q !X64!     >NUL
    IF EXIST !ARM64!   RMDIR /S /Q !ARM64!   >NUL

    IF EXIST !TEMPLATE! DEL !TEMPLATE! >NUL
)

POPD

EXIT /B 0
