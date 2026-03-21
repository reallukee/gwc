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

* [Requisiti](#0-requisiti)
* [Progetto](#1-progetto)



## 0. Requisiti

* .NET Framework
  * .NET Framework 4.8.1 Runtime
  * .NET Framework 4.7.2 Runtime
* Microsoft Visual C++
  * Microsoft Visual C++ v14 Redistributable (x64)
  * Microsoft Visual C++ v14 Redistributable (x86)
  * Microsoft Visual C++ v14 Redistributable (arm64)
* Windows 10



## 1. Progetto

### API C

```c
// GWC 0.1.0

#include <gwc.h>

int main(int argc, const char* argv[])
{
    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        return 1;
    }

    if (window_isOpen(window))
    {
        window_drawFillRectangle(window, 50, 50, 100, 100);
        window_drawBorderRectangle(window, 50, 50, 100, 100);

        printf("Press any key to exit...\n");

        _getch();

        window_shutdown(window);
    }
    else
    {
        printf("Oh :(\n");
    }

    window_delete(window);

    return 0;
}
```

### API C++

```cpp
// GWC 0.1.0

#include <gwc.hpp>

#include <conio.h>

#include <iostream>

using namespace gwc;

using namespace std;

int main(int argc, const char* argv[])
{
    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        return 1;
    }

    if (window->isOpen())
    {
        window->drawFillRectangle(50, 50, 100, 100);
        window->drawBorderRectangle(50, 50, 100, 100);

        cout << "Press any key to exit..." << endl;

        _getch();

        window->shutdown();
    }
    else
    {
        cout << "Oh :(" << endl;
    }

    delete window;

    return 0;
}
```



# Compilazione

> [!WARNING]
> CI STO LAVORANDO!

* [Prerequisiti](#0-prerequisiti)
* [Sorgente](#1-sorgente)
* [Configurazione](#2-configurazione)
* [Compilazione](#3-compilazione)



## 0. Prerequisiti

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



## 1. Sorgente

```
git clone https://github.com/reallukee/gwc.git
```



## 2. Configurazione

```cmd
REM Visual Studio 2026
CALL "%PROGRAMFILES%\Microsoft Visual Studio\18\Community\Common7\Tools\vsdevcmd"

REM Build Tools per Visual Studio 2026
CALL "%PROGRAMFILES% (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\vsdevcmd"
```



## 3. Compilazione

```cmd
REM GWC x86
msbuild gwc.sln /p:Configuration=Release /p:Platform=x86 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=x86 /t:gwc_native

REM GWC x64
msbuild gwc.sln /p:Configuration=Release /p:Platform=x64 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=x64 /t:gwc_native

REM GWC arm64
msbuild gwc.sln /p:Configuration=Release /p:Platform=arm64 /t:gwc
msbuild gwc.sln /p:Configuration=Release /p:Platform=arm64 /t:gwc_native
```



# Download

> [Ultima Release](https://github.com/reallukee/gwc/releases)



# Autore

* [Luca Pollicino](https://github.com/reallukee)



# Licenza

Licenza [MIT](./LICENSE)
