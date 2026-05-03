:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.uninstall.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (config\templates.txt) DO (
    SET TEMPLATE_VERSION=%%D-!VERSION!.zip
    SET         TEMPLATE=%%D.zip

    IF EXIST "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE_VERSION!" (
        DEL "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE_VERSION!" >NUL
    )

    IF EXIST "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE!" (
        DEL "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates\!TEMPLATE!" >NUL
    )
)

POPD

EXIT /B 0
