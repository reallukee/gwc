//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// IMAGE.c
//  Licenza MIT
//

#include "IMAGE.h"
#include "IMAGEHELPER.h"

#include <gdiplus.h>

using namespace Gdiplus;

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



gIMAGE* image_new(const char* path)
{
    return image_newA(path);
}

gIMAGE* image_newA(const char* path)
{
    wchar_t* wpath = strToWStr(path);

    gIMAGE* result = image_newW(wpath);

    free(wpath);

    return result;
}

gIMAGE* image_newW(const wchar_t* path)
{
    gIMAGE* image = (gIMAGE*)calloc(1, sizeof(gIMAGE));

    if (image == NULL)
    {
        return NULL;
    }

    image->image = NULL;

    image_loadW(image, path);

    return image;
}

void image_delete(gIMAGE* image)
{
    image_unload(image);

    image = NULL;
}



static HBITMAP loadImage(const wchar_t* path)
{
    if (path == NULL)
    {
        return NULL;
    }

    HBITMAP image = (HBITMAP)LoadImageW(
        NULL,
        path,
        IMAGE_BITMAP,
        0,
        0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION
    );

    return image;
}

static NativeImage shareImage(HBITMAP image)
{
    auto destructor = [](HBITMAP image)
    {
        if (image)
        {
            DeleteObject(image);
        }
    };

    NativeImage _image(image, destructor);

    return _image;
}



bool image_load(gIMAGE* image, const char* path)
{
    return image_loadA(image, path);
}

bool image_loadA(gIMAGE* image, const char* path)
{
    wchar_t* wpath = strToWStr(path);

    bool result = image_loadW(image, wpath);

    free(wpath);

    return result;
}

bool image_loadW(gIMAGE* image, const wchar_t* path)
{
    if (image == NULL)
    {
        return false;
    }

    if (image_isLoaded(image))
    {
        return false;
    }

    HBITMAP _image = loadImage(path);

    if (_image == NULL)
    {
        return false;
    }

    image->image = shareImage(_image);

    return true;
}

void image_unload(gIMAGE* image)
{
    if (!image_isLoaded(image))
    {
        return;
    }

    image->image.reset();
}



bool image_isLoaded(const gIMAGE* image)
{
    if (image == NULL)
    {
        return false;
    }

    return image->image != NULL;
}

bool image_isUnloaded(const gIMAGE* image)
{
    if (image == NULL)
    {
        return true;
    }

    return image->image == NULL;
}



HBITMAP imageHelper_get(const gIMAGE* image)
{
    HBITMAP _image = static_cast<HBITMAP>(image->image.get());

    return _image;
}
