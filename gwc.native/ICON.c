//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// ICON.c
//  Licenza MIT
//

#include "ICON.h"

typedef struct gICON
{
    HICON icon;
} gICON;



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
    gICON* icon = (gICON*)calloc(1, sizeof(gICON));

    if (icon == NULL)
    {
        return NULL;
    }

    wchar_t* wpath = strToWStr(path);

    if (wpath == NULL)
    {
        free(icon);

        return NULL;
    }

    icon->icon = (HICON)LoadImageW(
        NULL,
        wpath,
        IMAGE_ICON,
        0,
        0,
        LR_LOADFROMFILE
    );

    free(wpath);

    return icon;
}

void icon_delete(gICON* icon)
{
    if (icon != NULL)
    {
        if (icon->icon != NULL)
        {
            DestroyIcon(icon->icon);
        }

        free(icon);

        icon = NULL;
    }
}



bool icon_isLoaded(const gICON* icon)
{
    return icon->icon != NULL;
}

void icon_release(const gICON* icon)
{
    if (!icon_isLoaded(icon))
    {
        return;
    }

    DestroyIcon(icon->icon);
}

HICON icon_get(const gICON* icon)
{
    return icon->icon;
}
