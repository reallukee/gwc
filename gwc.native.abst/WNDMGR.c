//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// WNDMGR.c
//  Licenza MIT
//

#include "WNDMGR.h"

#include <WINDOW.h>

static const int MAX_ITEMS_COUNT = 10;
static const int NO_ITEM         = -1;

static bool ready = false;

static WINDOW* items[MAX_ITEMS_COUNT] = { NULL };
static int     currentItem            = NO_ITEM;

#define ITEM items[currentItem]

void wndmgr_init()
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

void wndmgr_shutdown()
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
            window_delete(items[i]);

            items[i] = NULL;
        }
    }
}



bool wndmgr_setCurrent(int id)
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

int wndmgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



int wndmgr_alloc(int width, int height, bool select)
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

    WINDOW* window = window_new(width, height);

    if (window == NULL)
    {
        return NO_ITEM;
    }

    items[nextItem] = window;

    if (select)
    {
        currentItem = nextItem;
    }

    return nextItem;
}

void wndmgr_free()
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

    window_delete(items[currentItem]);

    items[currentItem] = NULL;
}



bool wndmgr_isInitialized()
{
    if (!ready)
    {
        return false;
    }

    return window_isInitialized(ITEM);
}



bool wndmgr_open()
{
    if (!ready)
    {
        return false;
    }

    return window_open(ITEM);
}

bool wndmgr_close()
{
    if (!ready)
    {
        return false;
    }

    return window_close(ITEM);
}



bool wndmgr_isOpen()
{
    if (!ready)
    {
        return false;
    }

    return window_isOpen(ITEM);
}

bool wndmgr_isClose()
{
    if (!ready)
    {
        return false;
    }

    return window_isClose(ITEM);
}



void wndmgr_wait(int milliseconds)
{
    if (!ready)
    {
        return;
    }

    window_wait(ITEM, milliseconds);
}
