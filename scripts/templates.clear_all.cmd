:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.clear_all.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\templates.clear.cmd

SET /P VERSION=<VERSION

FOR /F %%D in (config\templates.txt) DO (
    SET INCLUDE=templates\%%D\include
    SET  STATIC=templates\%%D\static
    SET  SHARED=templates\%%D\shared

    SET TEMPLATE_VERSION=templates\%%D-!VERSION!.zip
    SET  TEMPLATE_LATEST=templates\%%D-latest.zip

    IF EXIST !INCLUDE! RMDIR /S /Q !INCLUDE! >NUL
    IF EXIST !STATIC!  RMDIR /S /Q !STATIC!  >NUL
    IF EXIST !SHARED!  RMDIR /S /Q !SHARED!  >NUL

    IF EXIST !TEMPLATE_VERSION! DEL !TEMPLATE_VERSION! >NUL
    IF EXIST  !TEMPLATE_LATEST! DEL !TEMPLATE_LATEST!  >NUL
)

SET DIST=templates\dist

IF EXIST !DIST! RMDIR /S /Q !DIST! >nul

POPD

EXIT /B 0
