//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CNVMGR.c
//  Licenza MIT
//

#pragma unmanaged

#include "CNVMGR.h"
#include "CNVMGRHELPER.h"

#include "SRIMGRHELPER.h"

#include "MACROS.h"

static const int MAX_ITEMS_COUNT = 10;

static bool ready = false;

static CANVAS* items[MAX_ITEMS_COUNT] = { NULL };
static int     currentItem            = NO_ITEM;

#define ITEM items[currentItem]

void cnvmgr_init()
{
    if (ready)
    {
        return;
    }

    for (int i = 0; i < MAX_ITEMS_COUNT; i++)
    {
        items[i] = NULL;
    }

    currentItem = NO_ITEM;

    ready = true;
}

void cnvmgr_shutdown()
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
            canvas_delete(items[i]);

            items[i] = NULL;
        }
    }
}



bool cnvmgr_setCurrent(CNV_ID id)
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

CNV_ID cnvmgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



CNV_ID cnvmgr_alloc(int width, int height, bool select)
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

    CANVAS* canvas = canvas_new(width, height);

    if (canvas == NULL)
    {
        return NO_ITEM;
    }

    items[nextItem] = canvas;

    if (select)
    {
        currentItem = nextItem;
    }

    return nextItem;
}

void cnvmgr_free()
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

    canvas_delete(items[currentItem]);

    items[currentItem] = NULL;
}



bool cnvmgr_isInitialized()
{
    CCI_BOOL_C(canvas_isInitialized(ITEM));
}



gCOLOR* cnvmgr_getBorderColor()
{
    CCI_GET_COLOR_C(canvas_getBorderColor(ITEM));
}

void cnvmgr_setBorderColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(canvas_setBorderColor(ITEM, color));
}

gCOLOR* cnvmgr_getFillColor()
{
    CCI_GET_COLOR_C(canvas_getFillColor(ITEM));
}

void cnvmgr_setFillColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(canvas_setFillColor(ITEM, color));
}



gRECTANGLE* cnvmgr_bounds()
{
    CCI_GET_RECTANGLE_C(canvas_bounds(ITEM));
}

gSIZE* cnvmgr_size()
{
    CCI_GET_SIZE_C(canvas_size(ITEM));
}

gPOINT* cnvmgr_location()
{
    CCI_GET_POINT_C(canvas_location(ITEM));
}



int cnvmgr_getWidth()
{
    CCI_INT_C(canvas_getWidth(ITEM));
}

int cnvmgr_getHeight()
{
    CCI_INT_C(canvas_getHeight(ITEM));
}



bool cnvmgr_clear(const gCOLOR* color)
{
    CCI_BOOL_C(canvas_clear(ITEM, color));
}



bool cnvmgr_drawCanvas(int x, int y, CNV_ID canvasId)
{
    CANVAS* canvas = cnvmgrHelper_get(canvasId);

    CCI_BOOL_C(canvas_drawCanvas(ITEM, x, y, canvas));
}

bool cnvmgr_drawSprite(int x, int y, SRI_ID spriteId)
{
    SPRITE* sprite = srimgrHelper_get(spriteId);

    CCI_BOOL_C(canvas_drawSprite(ITEM, x, y, sprite));
}



bool cnvmgr_drawBorderSquare(int x, int y, int side)
{
    CCI_BOOL_C(canvas_drawBorderSquare(ITEM, x, y, side));
}

bool cnvmgr_drawFillSquare(int x, int y, int side)
{
    CCI_BOOL_C(canvas_drawFillSquare(ITEM, x, y, side));
}



bool cnvmgr_drawBorderRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(canvas_drawBorderRectangle(ITEM, x, y, width, height));
}

bool cnvmgr_drawFillRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(canvas_drawFillRectangle(ITEM, x, y, width, height));
}



bool cnvmgr_drawBorderCircle(int x, int y, int radius)
{
    CCI_BOOL_C(canvas_drawBorderCircle(ITEM, x, y, radius));
}

bool cnvmgr_drawFillCircle(int x, int y, int radius)
{
    CCI_BOOL_C(canvas_drawFillCircle(ITEM, x, y, radius));
}



bool cnvmgr_drawBorderEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(canvas_drawBorderEllipse(ITEM, x, y, width, height));
}

bool cnvmgr_drawFillEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(canvas_drawFillEllipse(ITEM, x, y, width, height));
}



bool cnvmgr_drawImage(int x, int y, gIMAGE* image)
{
    CCI_BOOL_C(canvas_drawImage(ITEM, x, y, image));
}

bool cnvmgr_drawIcon(int x, int y, gICON* icon)
{
    CCI_BOOL_C(canvas_drawIcon(ITEM, x, y, icon));
}



void cnvmgr_render()
{
    CCI_VOID_C(canvas_render(ITEM));
}



CANVAS* cnvmgrHelper_get(CNV_ID id)
{
    if (!ready)
    {
        return NULL;
    }

    if (id < 0 || id > MAX_ITEMS_COUNT - 1)
    {
        return NULL;
    }

    if (items[id] == NULL)
    {
        return NULL;
    }

    return items[id];
}
