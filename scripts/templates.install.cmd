:: :.:.:.:.:.:.:.:.:.:.:
:: templates.install.cmd
:: :.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

SET /P VERSION=<VERSION

FOR /F %%D in (config\templates.txt) DO (
    SET TEMPLATE_VERSION=%%D-!VERSION!.zip
    SET  TEMPLATE_LATEST=%%D-latest.zip

    IF EXIST templates\dist\!TEMPLATE_VERSION! (
        COPY templates\dist\!TEMPLATE_VERSION! "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates" >NUL
    )

    IF EXIST templates\dist\!TEMPLATE_LATEST! (
        COPY templates\dist\!TEMPLATE_LATEST! "%USERPROFILE%\Documents\Visual Studio 18\Templates\ProjectTemplates" >NUL
    )
)

POPD

EXIT /B 0
