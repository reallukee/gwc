//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// IMAGE.c
//  Licenza MIT
//

#include "IMAGE.h"

typedef struct gIMAGE
{
    HBITMAP image;
} gIMAGE;



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
    gIMAGE* image = (gIMAGE*)calloc(1, sizeof(gIMAGE));

    if (image == NULL)
    {
        return NULL;
    }

    wchar_t* wpath = strToWStr(path);

    if (wpath == NULL)
    {
        free(image);

        return NULL;
    }

    image->image = (HBITMAP)LoadImageW(
        NULL,
        wpath,
        IMAGE_BITMAP,
        0,
        0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION
    );

    free(wpath);

    return image;
}

void image_delete(gIMAGE* image)
{
    if (image != NULL)
    {
        if (image->image != NULL)
        {
            DeleteObject(image->image);
        }

        free(image);

        image = NULL;
    }
}



bool image_isLoaded(const gIMAGE* image)
{
    return image->image != NULL;
}

void image_release(const gIMAGE* image)
{
    if (!image_isLoaded(image))
    {
        return;
    }

    DeleteObject(image->image);
}

HBITMAP image_get(const gIMAGE* image)
{
    return image->image;
}
