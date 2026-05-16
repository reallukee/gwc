:: :.:.:.:.:.:.:
:: setup_env.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
ENDLOCAL

PUSHD "%~dp0"

SET "PATH=%CD%;%CD%\scripts;%PATH%"

IF EXIST "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd" (
    CALL "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd" >NUL
)

IF EXIST "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" (
    CALL "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" >NUL
)

POPD

EXIT /B 0
