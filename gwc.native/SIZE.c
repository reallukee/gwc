//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SIZE.c
//  Licenza MIT
//

#include "SIZE.h"

typedef struct gSIZE
{
    int width;
    int height;
} gSIZE;



gSIZE* size_new(int width, int height)
{
    gSIZE* size = (gSIZE*)calloc(1, sizeof(gSIZE));

    if (size == NULL)
    {
        return NULL;
    }

    if (width < 0)
    {
        width = 0;
    }

    if (height < 0)
    {
        height = 0;
    }

    size->width  = width;
    size->height = height;

    return size;
}

void size_delete(gSIZE* size)
{
    if (size != NULL)
    {
        free(size);

        size = NULL;
    }
}



int size_getWidth(const gSIZE* size)
{
    return size->width;
}

void size_setWidth(gSIZE* size, int value)
{
    if (value < 0)
    {
        return;
    }

    size->width = value;
}

int size_getHeight(const gSIZE* size)
{
    return size->height;
}

void size_setHeight(gSIZE* size, int value)
{
    if (value < 0)
    {
        return;
    }

    size->height = value;
}



bool size_equal(const gSIZE* size, const gSIZE* other)
{
    if (size == NULL || other == NULL)
    {
        return false;
    }

    return size->width  == other->width  &&
           size->height == other->height;
}

bool size_notequal(const gSIZE* size, const gSIZE* other)
{
    if (size == NULL || other == NULL)
    {
        return false;
    }

    return size->width  != other->width  &&
           size->height != other->height;
}
