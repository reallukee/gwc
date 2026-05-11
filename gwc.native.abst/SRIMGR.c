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

#include "SRIMGR.h"

#include <SPRITE.h>

static const int MAX_ITEMS_COUNT = 10;
static const int NO_ITEM         = -1;

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



bool srimgr_setCurrent(int id)
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

int srimgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



int srimgr_alloc(int width, int height, bool select)
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
    if (!ready)
    {
        return false;
    }

    return sprite_isInitialized(ITEM);
}
