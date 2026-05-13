:: :.:.:.:.:.:.:.:.:.:
:: templates.build.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%D in (config\templates.txt) DO (
    SET STATIC=templates\%%D\static\gwc.native
    SET SHARED=templates\%%D\shared\gwc.native

    IF NOT EXIST !STATIC! (
        MKDIR !STATIC! >NUL
    )

    IF NOT EXIST !SHARED! (
        MKDIR !SHARED! >NUL
    )

    FOR /F %%S in (config\static.txt) DO (
        SET      SOURCE=bin\%%S
        SET DESTINATION=!STATIC!

        IF EXIST !SOURCE! (
            COPY !SOURCE! !DESTINATION! >NUL
        )
    )

    FOR /F %%S in (config\shared.txt) DO (
        SET      SOURCE=bin\%%S
        SET DESTINATION=!SHARED!

        IF EXIST !SOURCE! (
            COPY !SOURCE! !DESTINATION! >NUL
        )
    )
)


FOR /F %%D in (config\templates.abst.txt) DO (
    SET STATIC=templates\%%D\static\gwc.native.abst
    SET SHARED=templates\%%D\shared\gwc.native.abst

    IF NOT EXIST !STATIC! (
        MKDIR !STATIC! >NUL
    )

    IF NOT EXIST !SHARED! (
        MKDIR !SHARED! >NUL
    )

    FOR /F %%S in (config\static.abst.txt) DO (
        SET      SOURCE=bin\%%S
        SET DESTINATION=!STATIC!

        IF EXIST !SOURCE! (
            COPY !SOURCE! !DESTINATION! >NUL
        )
    )

    FOR /F %%S in (config\shared.abst.txt) DO (
        SET      SOURCE=bin\%%S
        SET DESTINATION=!SHARED!

        IF EXIST !SOURCE! (
            COPY !SOURCE! !DESTINATION! >NUL
        )
    )
)

POPD

EXIT /B 0
