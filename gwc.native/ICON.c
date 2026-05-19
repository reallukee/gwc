//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// ICON.c
//  Licenza MIT
//

#include "ICON.h"
#include "ICONHELPER.h"

static wchar_t* strToWStr(const char* str)
{
    int size = MultiByteToWideChar(
        CP_UTF8,
        0,
        str,
        -1,
        NULL,
        0
    );

    wchar_t* wstr = (wchar_t*)calloc(size, sizeof(wchar_t));

    if (wstr == NULL)
    {
        return NULL;
    }

    MultiByteToWideChar(
        CP_UTF8,
        0,
        str,
        -1,
        wstr,
        size
    );

    return wstr;
}



gICON* icon_new(const char* path)
{
    return icon_newA(path);
}

gICON* icon_newA(const char* path)
{
    wchar_t* wpath = strToWStr(path);

    gICON* result = icon_newW(wpath);

    free(wpath);

    return result;
}

gICON* icon_newW(const wchar_t* path)
{
    gICON* icon = (gICON*)calloc(1, sizeof(gICON));

    if (icon == NULL)
    {
        return NULL;
    }

    icon->icon = NULL;

    icon_loadW(icon, path);

    return icon;
}

void icon_delete(gICON* icon)
{
    icon_unload(icon);

    icon = NULL;
}



static HICON loadIcon(const wchar_t* path)
{
    if (path == NULL)
    {
        return NULL;
    }

    HICON icon = (HICON)LoadImageW(
        NULL,
        path,
        IMAGE_ICON,
        0,
        0,
        LR_LOADFROMFILE
    );

    return icon;
}

static NativeIcon shareIcon(HICON icon)
{
    auto destructor = [](HICON icon)
    {
        if (icon)
        {
            DestroyIcon(icon);
        }
    };

    NativeIcon _icon(icon, destructor);

    return _icon;
}



bool icon_load(gICON* icon, const char* path)
{
    return icon_loadA(icon, path);
}

bool icon_loadA(gICON* icon, const char* path)
{
    wchar_t* wpath = strToWStr(path);

    bool result = icon_loadW(icon, wpath);

    free(wpath);

    return result;
}

bool icon_loadW(gICON* icon, const wchar_t* path)
{
    if (icon == NULL)
    {
        return false;
    }

    if (icon_isLoaded(icon))
    {
        return false;
    }

    HICON _icon = loadIcon(path);

    if (_icon == NULL)
    {
        return false;
    }

    icon->icon = shareIcon(_icon);

    return true;
}

void icon_unload(gICON* icon)
{
    if (!icon_isLoaded(icon))
    {
        return;
    }

    icon->icon.reset();
}



bool icon_isLoaded(const gICON* icon)
{
    if (icon == NULL)
    {
        return false;
    }

    return icon->icon != NULL;
}

bool icon_isUnloaded(const gICON* icon)
{
    if (icon == NULL)
    {
        return true;
    }

    return icon->icon == NULL;
}



HICON iconHelper_get(const gICON* icon)
{
    HICON _icon = static_cast<HICON>(icon->icon.get());

    return _icon;
}
