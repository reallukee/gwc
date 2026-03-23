//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// COLOR.c
//  Licenza MIT
//

#include "COLOR.h"

typedef struct COLOR
{
    int alpha;
    int red;
    int blue;
    int green;
} COLOR;



COLOR* color_new(int alpha, int red, int blue, int green)
{
    COLOR* color = (COLOR*)calloc(1, sizeof(COLOR));

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

    if (blue < 0 || blue > 255)
    {
        blue = 255;
    }

    if (green < 0 || green > 255)
    {
        green = 255;
    }

    color->alpha = alpha;
    color->red   = red;
    color->blue  = blue;
    color->green = green;

    return color;
}

void color_delete(COLOR* color)
{
    free(color);
}



int color_getAlpha(const COLOR* color)
{
    return color->alpha;
}

void color_setAlpha(COLOR* color, int value)
{
    if (value < 0 || value > 100)
    {
        return;
    }

    color->alpha = value;
}

int color_getRed(const COLOR* color)
{
    return color->red;
}

void color_setRed(COLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->red = value;
}

int color_getBlue(const COLOR* color)
{
    return color->blue;
}

void color_setBlue(COLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->blue = value;
}

int color_getGreen(const COLOR* color)
{
    return color->green;
}

void color_setGreen(COLOR* color, int value)
{
    if (value < 0 || value > 255)
    {
        return;
    }

    color->green = value;
}
