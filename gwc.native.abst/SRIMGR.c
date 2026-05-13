//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SRIMGR.c
//  Licenza MIT
//

#pragma unmanaged

#include "SRIMGR.h"

#include <SPRITE.h>

#include "MACROS.h"

static const int MAX_ITEMS_COUNT = 10;

static bool ready = false;

static SPRITE* items[MAX_ITEMS_COUNT] = { NULL };
static int     currentItem            = NO_ITEM;

#define ITEM items[currentItem]

void srimgr_init()
{
    if (ready)
    {
        return;
    }

    for (int i = 0; i < MAX_ITEMS_COUNT; i++)
    {
        items[i] = nullptr;
    }

    currentItem = NO_ITEM;

    ready = true;
}

void srimgr_shutdown()
{
    if (!ready)
    {
        return;
    }

    ready = false;

    for (int i = 0; i < MAX_ITEMS_COUNT; i++)
    {
        if (items[i] != NULL)
        {
            sprite_delete(items[i]);

            items[i] = NULL;
        }
    }
}



bool srimgr_setCurrent(SRI_ID id)
{
    if (!ready)
    {
        return false;
    }

    if (id < 0 || id > MAX_ITEMS_COUNT - 1)
    {
        return false;
    }

    if (items[id] == NULL)
    {
        return false;
    }

    currentItem = id;

    return true;
}

SRI_ID srimgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



SRI_ID srimgr_alloc(int width, int height, bool select)
{
    if (!ready)
    {
        return NO_ITEM;
    }

    int nextItem = NO_ITEM;

    for (int i = 0; i < MAX_ITEMS_COUNT && nextItem == NO_ITEM; i++)
    {
        if (items[i] == NULL)
        {
            nextItem = i;
        }
    }

    if (nextItem == NO_ITEM)
    {
        return NO_ITEM;
    }

    SPRITE* sprite = sprite_new(width, height);

    if (sprite == NULL)
    {
        return NO_ITEM;
    }

    items[nextItem] = sprite;

    if (select)
    {
        currentItem = nextItem;
    }

    return nextItem;
}

void srimgr_free()
{
    if (!ready)
    {
        return;
    }

    if (currentItem < 0 || currentItem > MAX_ITEMS_COUNT - 1)
    {
        return;
    }

    if (items[currentItem] == NULL)
    {
        return;
    }

    sprite_delete(items[currentItem]);

    items[currentItem] = NULL;
}



bool srimgr_isInitialized()
{
    CCI_BOOL_C(sprite_isInitialized(ITEM));
}



gCOLOR* srimgr_getBorderColor()
{
    CCI_GET_COLOR_C(sprite_getBorderColor(ITEM));
}

void srimgr_setBorderColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(sprite_setBorderColor(ITEM, color));
}

gCOLOR* srimgr_getFillColor()
{
    CCI_GET_COLOR_C(sprite_getFillColor(ITEM));
}

void srimgr_setFillColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(sprite_setFillColor(ITEM, color));
}



gRECTANGLE* srimgr_bounds()
{
    CCI_GET_RECTANGLE_C(sprite_bounds(ITEM));
}

gSIZE* srimgr_size()
{
    CCI_GET_SIZE_C(sprite_size(ITEM));
}

gPOINT* srimgr_location()
{
    CCI_GET_POINT_C(sprite_location(ITEM));
}



int srimgr_getWidth()
{
    CCI_INT_C(sprite_getWidth(ITEM));
}

int srimgr_getHeight()
{
    CCI_INT_C(sprite_getHeight(ITEM));
}



bool srimgr_drawBorderSquare(int x, int y, int side)
{
    CCI_BOOL_C(sprite_drawBorderSquare(ITEM, x, y, side));
}

bool srimgr_drawFillSquare(int x, int y, int side)
{
    CCI_BOOL_C(sprite_drawFillSquare(ITEM, x, y, side));
}



bool srimgr_drawBorderRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(sprite_drawBorderRectangle(ITEM, x, y, width, height));
}

bool srimgr_drawFillRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(sprite_drawFillRectangle(ITEM, x, y, width, height));
}



bool srimgr_drawBorderCircle(int x, int y, int radius)
{
    CCI_BOOL_C(sprite_drawBorderCircle(ITEM, x, y, radius));
}

bool srimgr_drawFillCircle(int x, int y, int radius)
{
    CCI_BOOL_C(sprite_drawFillCircle(ITEM, x, y, radius));
}



bool srimgr_drawBorderEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(sprite_drawBorderEllipse(ITEM, x, y, width, height));
}

bool srimgr_drawFillEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(sprite_drawFillEllipse(ITEM, x, y, width, height));
}



bool srimgr_drawImage(int x, int y, gIMAGE* image)
{
    CCI_BOOL_C(sprite_drawImage(ITEM, x, y, image));
}

bool srimgr_drawIcon(int x, int y, gICON* icon)
{
    CCI_BOOL_C(sprite_drawIcon(ITEM, x, y, icon));
}



void srimgr_render()
{
    CCI_VOID_C(sprite_render(ITEM));
}
