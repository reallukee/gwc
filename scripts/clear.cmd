@ECHO OFF

SET CURRENT_DIR=%CD%

CD /D "%~dp0.."

IF EXIST ".vs" RD /S /Q ".vs"
IF EXIST "bin" RD /S /Q "bin"
IF EXIST "obj" RD /S /Q "obj"

CD %CURRENT_DIR%

EXIT /B 0
