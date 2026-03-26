<img src="./assets/gwc.png" width="128px" height="128px" />

# GWC

![License](https://img.shields.io/github/license/reallukee/gwc)
![Release](https://img.shields.io/github/v/release/reallukee/gwc?include_prereleases)
![Language](https://img.shields.io/github/languages/top/reallukee/gwc)

[Utilizzo](#utilizzo)
~
[Compilazione](#compilazione)
~
[Download](#download)
~
[Autore](#autore)
~
[Licenza](#licenza)

🖼️ A C#, C++ and C graphics library written in C#, C++ and C

Caratteristiche:

* 😜 Folle (Un Wrapper di un Wrapper di un Wrapper)
* 🔬 Sperimentale (Nel SENSO più LETTERALE)
* 🤪 Instabile
* 🧱 Incompleta
* 🤤 Goduriosa

Nessuna Pretesa, Solo Chill!



# Utilizzo

> [!WARNING]
> CI STO LAVORANDO!

## Requisiti

* [Windows](#windows)
* [Linux](#linux)
* [macOS](#macos)

## Windows

* .NET Framework
  * .NET Framework 4.8.1 Runtime
  * .NET Framework 4.7.2 Runtime
* Microsoft Visual C++
  * Microsoft Visual C++ v14 Redistributable (x64)
  * Microsoft Visual C++ v14 Redistributable (x86)
  * Microsoft Visual C++ v14 Redistributable (arm64)

## Linux

> [!WARNING]
> `GWC` è supportata su Linux tramite `Mono` (Verificato).<br />
> `GWC.Native` è **FORSE** supportata su Linux con `Wine` (Non verificato).

> [!WARNING]
> ARM64 non è supportato da Mono!

> [!IMPORTANT]
> GWC è fortemente legata a Windows. Questi sono layer di compatibilità.
> Non è assicurato un comportamento corretto!

* Mono Runtime 6.8.0+<br />
  (System.Drawing.dll e System.Windows.Forms.dll devono essere
  presenti!)

## macOS

> [!WARNING]
> `GWC` è supportata su macOS tramite `Mono` (Verificato).<br />
> `GWC.Native` è **FORSE** supportata su macOS con `Wine` (Non verificato).

> [!WARNING]
> ARM64 non è supportato da Mono!

> [!IMPORTANT]
> GWC è fortemente legata a Windows. Questi sono layer di compatibilità.
> Non è assicurato un comportamento corretto!

* Mono Runtime 6.8.0+<br />
  (System.Drawing.dll e System.Windows.Forms.dll devono essere
  presenti!)



# Compilazione

> [!WARNING]
> CI STO LAVORANDO!

* [Prerequisiti](#1-prerequisiti)
* [Sorgente](#2-sorgente)
* [Compilazione](#3-compilazione)



## 1. Prerequisiti

* `git`
* [Visual Studio 2026](https://aka.ms/vs/stable/vs_Community.exe)
  oppure
  [Build Tools per Visual Studio 2026](https://aka.ms/vs/stable/vs_BuildTools.exe)

In Visual Studio Installer:

* Sviluppo per Desktop .NET
  * .NET Framework 4.8.1 Targeting Pack
  * .NET Framework 4.8.1 SDK
  * .NET Framework 4.7.2 Targeting Pack
  * .NET Framework 4.7.2 SDK
* Sviluppo di Applicazioni Desktop con C++
  * Strumenti di Compilazione MSVC per ARM64/ARM64EC (Ultima Versione)
  * Strumenti di Compilazione MSVC per x64/x86 (Ultima Versione)
  * Supporto a C++/CLI (Ultima Versione)



## 2. Sorgente

```
git clone https://github.com/reallukee/gwc.git
```



## 3. Compilazione

```cmd
REM Visual Studio 2026
CALL "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd"

REM Build Tools per Visual Studio 2026
CALL "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd"
```

```cmd
REM GWC
msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=x64
msbuild gwc.sln /t:gwc /p:Configuration=Release /p:Platform=ARM64

REM GWC.Mono
msbuild gwc.sln /t:gwc_mono /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc_mono /p:Configuration=Release /p:Platform=x64

REM GWC.Native
msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=x64
msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=x86
msbuild gwc.sln /t:gwc_native /p:Configuration=Release /p:Platform=ARM64
```



# Download

> [Ultima Release](https://github.com/reallukee/gwc/releases)



# Autore

* [Luca Pollicino](https://github.com/reallukee)



# Licenza

Licenza [MIT](./LICENSE)
