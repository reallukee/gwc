@ECHO OFF

SET CURRENT_DIR=%CD%

CD /D "%~dp0.."

CALL "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd"

CALL "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd"

msbuild gwc.sln /p:Configuration=Release /p:Platform=x86 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=x86 /t:gwc_native
msbuild gwc.sln /p:Configuration=Release /p:Platform=x64 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=x64 /t:gwc_native
msbuild gwc.sln /p:Configuration=Release /p:Platform=arm64 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=arm64 /t:gwc_native

CD %CURRENT_DIR%

EXIT /B 0
