:: :.:.:.:.:.:.:.:.:.:
:: templates.build.cmd
:: :.:.:.:.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

FOR /F %%T in (config\templates.txt) DO (
    SET STATIC=templates\%%T\static\gwc.native
    SET SHARED=templates\%%T\shared\gwc.native

    IF NOT EXIST !STATIC! (
        MKDIR !STATIC! >NUL
    )

    IF NOT EXIST !SHARED! (
        MKDIR !SHARED! >NUL
    )

    FOR /F %%S in (config\static.txt) DO (
        FOR %%F IN (bin\%%S)      DO SET      SAFE_SOURCE=%%~nxF
        FOR %%F IN (!STATIC!\%%S) DO SET SAFE_DESTINATION=%%~nxF

        SET      SOURCE=bin\%%S
        SET DESTINATION=!STATIC!\!SAFE_DESTINATION!

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

    FOR /F %%S in (config\shared.txt) DO (
        FOR %%F IN (bin\%%S)      DO SET      SAFE_SOURCE=%%~nxF
        FOR %%F IN (!SHARED!\%%S) DO SET SAFE_DESTINATION=%%~nxF

        SET      SOURCE=bin\%%S
        SET DESTINATION=!SHARED!\!SAFE_DESTINATION!

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

FOR /F %%T in (config\templates.abst.txt) DO (
    SET STATIC=templates\%%T\static\gwc.native.abst
    SET SHARED=templates\%%T\shared\gwc.native.abst

    IF NOT EXIST !STATIC! (
        MKDIR !STATIC! >NUL
    )

    IF NOT EXIST !SHARED! (
        MKDIR !SHARED! >NUL
    )

    FOR /F %%S in (config\static.abst.txt) DO (
        FOR %%F IN (bin\%%S)      DO SET      SAFE_SOURCE=%%~nxF
        FOR %%F IN (!STATIC!\%%S) DO SET SAFE_DESTINATION=%%~nxF

        SET      SOURCE=bin\%%S
        SET DESTINATION=!STATIC!\!SAFE_DESTINATION!

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

    FOR /F %%S in (config\shared.abst.txt) DO (
        FOR %%F IN (bin\%%S)      DO SET      SAFE_SOURCE=%%~nxF
        FOR %%F IN (!SHARED!\%%S) DO SET SAFE_DESTINATION=%%~nxF

        SET      SOURCE=bin\%%S
        SET DESTINATION=!SHARED!\!SAFE_DESTINATION!

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
