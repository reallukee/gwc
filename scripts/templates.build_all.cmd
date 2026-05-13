:: :.:.:.:.:.:.:.:.:.:.:.:
:: templates.build_all.cmd
:: :.:.:.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\templates.build.cmd

FOR /F %%D in (config\templates.txt) DO (
    SET INCLUDE=templates\%%D\include\gwc.native

    IF NOT EXIST !INCLUDE! (
        MKDIR !INCLUDE! >NUL
    )

    FOR /F %%I in (config\include.txt) DO (
        SET      SOURCE=gwc.native\%%I
        SET DESTINATION=!INCLUDE!\%%I

        IF EXIST !SOURCE! (
            IF EXIST !DESTINATION! (
                FOR %%A in (!SOURCE!)      DO SET      SOURCE_TIME=%%~tA
                FOR %%B in (!DESTINATION!) DO SET DESTINATION_TIME=%%~tB

                IF !SOURCE_TIME! GTR !DESTINATION_TIME! (
                    COPY !SOURCE! !DESTINATION! >NUL
                )
            ) ELSE (
                COPY !SOURCE! !DESTINATION! >NUL
            )
        )
    )
)

FOR /F %%D in (config\templates.abst.txt) DO (
    SET INCLUDE=templates\%%D\include\gwc.native.abst

    IF NOT EXIST !INCLUDE! (
        MKDIR !INCLUDE! >NUL
    )

    FOR /F %%I in (config\include.abst.txt) DO (
        SET      SOURCE=gwc.native.abst\%%I
        SET DESTINATION=!INCLUDE!\%%I

        IF EXIST !SOURCE! (
            IF EXIST !DESTINATION! (
                FOR %%A in (!SOURCE!)      DO SET      SOURCE_TIME=%%~tA
                FOR %%B in (!DESTINATION!) DO SET DESTINATION_TIME=%%~tB

                IF !SOURCE_TIME! GTR !DESTINATION_TIME! (
                    COPY !SOURCE! !DESTINATION! >NUL
                )
            ) ELSE (
                COPY !SOURCE! !DESTINATION! >NUL
            )
        )
    )
)

POPD

EXIT /B 0
