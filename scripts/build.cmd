:: :.:.:.:.:
:: build.cmd
:: :.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

IF EXIST "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd" (
    CALL "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd" >NUL
) ELSE (
    IF EXIST "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" (
        CALL "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd" >NUL
    ) ELSE (
        EXIT /B 1
    )
)

msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=x64
msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=ARM64

msbuild gwc.sln /t:gwc_mono /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc_mono /p:Configuration=Release /p:Platform=x64

msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=x64
msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=ARM64

POPD

EXIT /B 0
