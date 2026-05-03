:: :.:.:.:.:
:: clear.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%D in (config\projects.txt) DO (
    SET  VS=%%D\.vs
    SET OBJ=%%D\obj

    IF EXIST  !VS! RMDIR /S /Q !VS!  >nul
    IF EXIST !OBJ! RMDIR /S /Q !OBJ! >nul
)

SET  VS=.vs
SET OBJ=obj

IF EXIST  !VS! RMDIR /S /Q !VS!  >nul
IF EXIST !OBJ! RMDIR /S /Q !OBJ! >nul

POPD

EXIT /B 0
