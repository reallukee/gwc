//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CNVMGR.c
//  Licenza MIT
//

#include "CNVMGR.h"

#include <CANVAS.h>

static const int MAX_ITEMS_COUNT = 10;
static const int NO_ITEM         = -1;

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
        items[i] = nullptr;
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



bool cnvmgr_setCurrent(int id)
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

int cnvmgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



int cnvmgr_alloc(int width, int height, bool select)
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
    if (!ready)
    {
        return false;
    }

    return canvas_isInitialized(ITEM);
}
