//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// COLOR.c
//  Licenza MIT
//

#include "COLOR.h"

typedef struct gCOLOR
{
    int alpha;
    int red;
    int green;
    int blue;
} gCOLOR;



gCOLOR* color_new(int alpha, int red, int green, int blue)
{
    gCOLOR* color = (gCOLOR*)calloc(1, sizeof(gCOLOR));

    if (color == NULL)
    {
        return NULL;
    }

    if (alpha < 0 || alpha > 100)
    {
        alpha = 100;
    }

    if (red < 0 || red > 255)
    {
        red = 255;
    }

    if (green < 0 || green > 255)
    {
        green = 255;
    }

    if (blue < 0 || blue > 255)
    {
        blue = 255;
    }

    color->alpha = alpha;
    color->red   = red;
    color->green = green;
    color->blue  = blue;

    return color;
}

void color_delete(gCOLOR* color)
{
    if (color != NULL)
    {
        free(color);

        color = NULL;
    }
}



int color_getAlpha(const gCOLOR* color)
{
    return color->alpha;
}

void color_setAlpha(gCOLOR* color, int value)
{
    if (value < 0 || value > 100)
    {
        return;
    }

    color->alpha = value;
}

int color_getRed(const gCOLOR* color)
{
    return color->red;
}

void color_setRed(gCOLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->red = value;
}

int color_getGreen(const gCOLOR* color)
{
    return color->green;
}

void color_setGreen(gCOLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->green = value;
}

int color_getBlue(const gCOLOR* color)
{
    return color->blue;
}

void color_setBlue(gCOLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->blue = value;
}



bool color_equal(const gCOLOR* color, const gCOLOR* other)
{
    if (color == NULL || other == NULL)
    {
        return false;
    }

    return color->alpha == other->alpha &&
           color->red   == other->red   &&
           color->green == other->green &&
           color->blue  == other->blue;
}

bool color_notequal(const gCOLOR* color, const gCOLOR* other)
{
    if (color == NULL || other == NULL)
    {
        return false;
    }

    return color->alpha != other->alpha &&
           color->red   != other->red   &&
           color->green != other->green &&
           color->blue  != other->blue;
}
