:: :.:.:.:.:.:.:.:.:.:.:
:: templates.install.cmd
:: :.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (scripts\templates.txt) DO (
    SET TEMPLATE=%%D-!VERSION!.zip

    IF EXIST templates\!TEMPLATE! (
        COPY templates\!TEMPLATE! "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates"
    )
)

POPD

EXIT /B 0
