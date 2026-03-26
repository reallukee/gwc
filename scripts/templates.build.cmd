:: :.:.:.:.:.:.:.:.:.:
:: templates.setup.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%D in (scripts\templates.txt) DO (
    SET INCLUDE=templates\%%D\include
    SET  STATIC=templates\%%D\static
    SET  SHARED=templates\%%D\shared

    IF NOT EXIST !INCLUDE! MKDIR !INCLUDE! >NUL
    IF NOT EXIST !STATIC!  MKDIR !STATIC!  >NUL
    IF NOT EXIST !SHARED!  MKDIR !SHARED!  >NUL

    FOR /F %%I in (scripts\include.txt) DO (
        COPY gwc.native\%%I !INCLUDE! >NUL
    )

    FOR /F %%S in (scripts\static.txt) DO (
        IF EXIST bin\%%S (
            COPY bin\%%S !STATIC! >NUL
        )
    )

    FOR /F %%S in (scripts\shared.txt) DO (
        IF EXIST bin\%%S (
            COPY bin\%%S !SHARED! >NUL
        )
    )
)

POPD

EXIT /B 0
