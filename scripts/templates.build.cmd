:: :.:.:.:.:.:.:.:.:.:
:: templates.build.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%D in (config\templates.txt) DO (
    SET STATIC=templates\%%D\static
    SET SHARED=templates\%%D\shared

    IF NOT EXIST !STATIC! MKDIR !STATIC! >NUL
    IF NOT EXIST !SHARED! MKDIR !SHARED! >NUL

    FOR /F %%S in (config\static.txt) DO (
        SET TARGET=bin\%%S

        IF EXIST !TARGET! (
            COPY !TARGET! !STATIC! >NUL
        )
    )

    FOR /F %%S in (config\shared.txt) DO (
        SET TARGET=bin\%%S

        IF EXIST !TARGET! (
            COPY !TARGET! !SHARED! >NUL
        )
    )
)

POPD

EXIT /B 0
