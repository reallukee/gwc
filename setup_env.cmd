:: :.:.:.:.:.:.:
:: setup_env.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
ENDLOCAL

PUSHD "%~dp0"

SET "PATH=%CD%;%CD%\scripts;%PATH%"

SET "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

IF NOT EXIST "%VSWHERE%" (
    EXIT /B 1
)

FOR /F "usebackq delims=" %%I IN (`
    "%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.CoreIde -property installationPath`
) DO (
    SET "VSPATH=%%I"
)

IF NOT DEFINED VSPATH (
    FOR /F "usebackq delims=" %%I IN (`
        "%VSWHERE%" -latest -products Microsoft.VisualStudio.Product.BuildTools -requires Microsoft.VisualStudio.Component.VC.CoreIde -property installationPath
    `) DO (
        SET "VSPATH=%%I"
    )
)

IF NOT DEFINED VSPATH (
    EXIT /B 1
)

SET "VSDEVCMD=%VSPATH%\Common7\Tools\VsDevCmd.bat"

IF EXIST "%VSDEVCMD%" (
    CALL "%VSDEVCMD%" >NUL
)

POPD

EXIT /B 0
