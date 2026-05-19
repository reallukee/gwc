:: :.:.:.:.:.:.:
:: build_all.cmd
:: :.:.:.:.:.:.:

@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

PUSHD "%~dp0.."

CALL scripts\build.cmd

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

dotnet restore gwc.sln

msbuild gwc.sln /t:gwc /p:Configuration=Debug /p:Platform=x86
msbuild gwc.sln /t:gwc /p:Configuration=Debug /p:Platform=x64
msbuild gwc.sln /t:gwc /p:Configuration=Debug /p:Platform=ARM64

msbuild gwc.sln /t:gwc_mono /p:Configuration=Debug /p:Platform=x86
msbuild gwc.sln /t:gwc_mono /p:Configuration=Debug /p:Platform=x64

msbuild gwc.sln /t:gwc_native /p:Configuration=Debug /p:Platform=x86
msbuild gwc.sln /t:gwc_native /p:Configuration=Debug /p:Platform=x64
msbuild gwc.sln /t:gwc_native /p:Configuration=Debug /p:Platform=ARM64

msbuild gwc.sln /t:gwc_native_abst /p:Configuration=Debug /p:Platform=x86
msbuild gwc.sln /t:gwc_native_abst /p:Configuration=Debug /p:Platform=x64
msbuild gwc.sln /t:gwc_native_abst /p:Configuration=Debug /p:Platform=ARM64

POPD

EXIT /B 0
