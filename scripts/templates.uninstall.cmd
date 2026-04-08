:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.uninstall.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (scripts\templates.txt) DO (
    SET TEMPLATE=%%D-!VERSION!.zip

    IF EXIST "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE!" (
        DEL "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE!"
    )
)

POPD

EXIT /B 0
