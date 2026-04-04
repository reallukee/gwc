:: :.:.:.:.:
:: clear.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%D in (scripts\projects.txt) DO (
    SET  VS=%%D\.vs
    SET OBJ=%%D\obj

    IF EXIST  !VS! RMDIR /S /Q !VS!
    IF EXIST !OBJ! RMDIR /S /Q !OBJ!
)

SET  VS=.vs
SET OBJ=obj

IF EXIST  !VS! RMDIR /S /Q !VS!
IF EXIST !OBJ! RMDIR /S /Q !OBJ!

POPD

EXIT /B 0
