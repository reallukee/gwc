//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SPRITE.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "SPRITE.h"
#include "sprite_macros.h"

typedef struct SPRITE {
    CLRSpriteHost sprite;
} SPRITE;



SPRITE* sprite_new(int width, int height)
{
    SPRITE* sprite = (SPRITE*)calloc(1, sizeof(SPRITE));

    if (sprite == NULL)
    {
        return NULL;
    }

    SpriteHost* host = new SpriteHost(width, height);

    sprite->sprite = static_cast<CLRSpriteHost>(host);

    return sprite;
}

void sprite_delete(SPRITE* sprite)
{
    if (sprite == NULL)
    {
        return;
    }

    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite);

    delete host;

    free(sprite);
}



bool sprite_isInitialized(const SPRITE* sprite)
{
    if (sprite == NULL)
    {
        return false;
    }

    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite);

    if (host == nullptr)
    {
        return false;
    }

    return !host->isNull();
}



gCOLOR* sprite_getBorderColor(const SPRITE* sprite)
{
    CCI_SPRITE_GET_COLOR_C(sprite, BorderColor);
}

void sprite_setBorderColor(const SPRITE* sprite, const gCOLOR* color)
{
    CCI_SPRITE_SET_COLOR_C(sprite, BorderColor, color);
}

gCOLOR* sprite_getFillColor(const SPRITE* sprite)
{
    CCI_SPRITE_GET_COLOR_C(sprite, FillColor);
}

void sprite_setFillColor(const SPRITE* sprite, const gCOLOR* color)
{
    CCI_SPRITE_SET_COLOR_C(sprite, FillColor, color);
}



gRECTANGLE* sprite_bounds(const SPRITE* sprite)
{
    CCI_SPRITE_GET_RECTANGLE_C(sprite, Bounds);
}

gSIZE* sprite_size(const SPRITE* sprite)
{
    CCI_SPRITE_GET_SIZE_C(sprite, Size);
}

gPOINT* sprite_location(const SPRITE* sprite)
{
    CCI_SPRITE_GET_POINT_C(sprite, Location);
}



int sprite_getWidth(const SPRITE* sprite)
{
    CCI_SPRITE_INT_C(sprite, Width);
}

int sprite_getHeight(const SPRITE* sprite)
{
    CCI_SPRITE_INT_C(sprite, Height);
}



bool sprite_drawBorderSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_SPRITE_BOOL_C(sprite, DrawBorderSquare(x, y, side));
}

bool sprite_drawFillSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_SPRITE_BOOL_C(sprite, DrawFillSquare(x, y, side));
}



bool sprite_drawBorderRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_SPRITE_BOOL_C(sprite, DrawBorderRectangle(x, y, width, height));
}

bool sprite_drawFillRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_SPRITE_BOOL_C(sprite, DrawFillRectangle(x, y, width, height));
}



bool sprite_drawBorderCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_SPRITE_BOOL_C(sprite, DrawBorderCircle(x, y, radius));
}

bool sprite_drawFillCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_SPRITE_BOOL_C(sprite, DrawFillCircle(x, y, radius));
}



bool sprite_drawBorderEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_SPRITE_BOOL_C(sprite, DrawBorderEllipse(x, y, width, height));
}

bool sprite_drawFillEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_SPRITE_BOOL_C(sprite, DrawFillEllipse(x, y, width, height));
}



void sprite_render(const SPRITE* sprite)
{
    CCI_SPRITE_VOID_C(sprite, Render());
}
