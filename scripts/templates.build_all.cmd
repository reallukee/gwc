:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.build_all.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\templates.build.cmd

FOR /F %%D in (config\templates.txt) DO (
    SET INCLUDE=templates\%%D\include

    IF NOT EXIST !INCLUDE! MKDIR !INCLUDE! >NUL

    FOR /F %%I in (config\include.txt) DO (
        SET TARGET=gwc.native\%%I

        IF EXIST !TARGET! (
            COPY !TARGET! !INCLUDE! >NUL
        )
    )
)

POPD

EXIT /B 0
