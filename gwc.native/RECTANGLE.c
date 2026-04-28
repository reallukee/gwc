//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// RECTANGLE.c
//  Licenza MIT
//

#include "RECTANGLE.h"

typedef struct gRECTANGLE
{
    int x;
    int y;
    int width;
    int height;
} gRECTANGLE;



gRECTANGLE* rectangle_new(int x, int y, int width, int height)
{
    gRECTANGLE* rectangle = (gRECTANGLE*)calloc(1, sizeof(gRECTANGLE));

    if (rectangle == NULL)
    {
        return NULL;
    }

    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    if (width < 0)
    {
        width = 0;
    }

    if (height < 0)
    {
        height = 0;
    }

    rectangle->x      = x;
    rectangle->y      = y;
    rectangle->width  = width;
    rectangle->height = height;

    return rectangle;
}

void rectangle_delete(gRECTANGLE* rectangle)
{
    if (rectangle != NULL)
    {
        free(rectangle);

        rectangle = NULL;
    }
}



int rectangle_getX(const gRECTANGLE* rectangle)
{
    return rectangle->x;
}

void rectangle_setX(gRECTANGLE* rectangle, int value)
{
    if (value < 0)
    {
        return;
    }

    rectangle->x = value;
}

int rectangle_getY(const gRECTANGLE* rectangle)
{
    return rectangle->y;
}

void rectangle_setY(gRECTANGLE* rectangle, int value)
{
    if (value < 0)
    {
        return;
    }

    rectangle->y = value;
}

int rectangle_getWidth(const gRECTANGLE* rectangle)
{
    return rectangle->width;
}

void rectangle_setWidth(gRECTANGLE* rectangle, int value)
{
    if (value < 0)
    {
        return;
    }

    rectangle->width = value;
}

int rectangle_getHeight(const gRECTANGLE* rectangle)
{
    return rectangle->height;
}

void rectangle_setHeight(gRECTANGLE* rectangle, int value)
{
    if (value < 0)
    {
        return;
    }

    rectangle->height = value;
}



bool rectangle_equal(const gRECTANGLE* rectangle, const gRECTANGLE* other)
{
    if (rectangle == NULL || other == NULL)
    {
        return false;
    }

    return rectangle->x      == other->x      &&
           rectangle->y      == other->y      &&
           rectangle->width  == other->width  &&
           rectangle->height == other->height;
}

bool rectangle_notequal(const gRECTANGLE* rectangle, const gRECTANGLE* other)
{
    if (rectangle == NULL || other == NULL)
    {
        return false;
    }

    return rectangle->x      != other->x      &&
           rectangle->y      != other->y      &&
           rectangle->width  != other->width  &&
           rectangle->height != other->height;
}
