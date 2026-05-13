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

#pragma unmanaged

#include "WNDMGR.h"

#include <WINDOW.h>

#include "MACROS.h"

static const int MAX_ITEMS_COUNT = 10;

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



bool wndmgr_setCurrent(WND_ID id)
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

WND_ID wndmgr_getCurrent()
{
    if (!ready)
    {
        return NO_ITEM;
    }

    return currentItem;
}



WND_ID wndmgr_alloc(int width, int height, bool select)
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
    CCI_BOOL_C(window_isInitialized(ITEM));
}



bool wndmgr_open()
{
    CCI_BOOL_C(window_open(ITEM));
}

bool wndmgr_close()
{
    CCI_BOOL_C(window_close(ITEM));
}



bool wndmgr_isOpen()
{
    CCI_BOOL_C(window_isOpen(ITEM));
}

bool wndmgr_isClose()
{
    CCI_BOOL_C(window_isClose(ITEM));
}



bool wndmgr_suspend()
{
    CCI_BOOL_C(window_suspend(ITEM));
}

bool wndmgr_resume()
{
    CCI_BOOL_C(window_resume(ITEM));
}



bool wndmgr_isSuspend()
{
    CCI_BOOL_C(window_isSuspend(ITEM));
}

bool wndmgr_isResume()
{
    CCI_BOOL_C(window_isResume(ITEM));
}



void wndmgr_wait(int milliseconds)
{
    CCI_VOID_C(window_wait(ITEM, milliseconds));
}

void wndmgr_skip(int frames)
{
    CCI_VOID_C(window_skip(ITEM, frames));
}



bool wndmgr_show()
{
    CCI_BOOL_C(window_show(ITEM));
}

bool wndmgr_hide()
{
    CCI_BOOL_C(window_hide(ITEM));
}



int wndmgr_getWindowWidth()
{
    CCI_INT_C(window_getWindowWidth(ITEM));
}

int wndmgr_getWindowHeight()
{
    CCI_INT_C(window_getWindowHeight(ITEM));
}

int wndmgr_getRenderWidth()
{
    CCI_INT_C(window_getRenderWidth(ITEM));
}

int wndmgr_getRenderHeight()
{
    CCI_INT_C(window_getRenderHeight(ITEM));
}



bool wndmgr_isKeyDownAvailable()
{
    CCI_BOOL_C(window_isKeyDownAvailable(ITEM));
}

void wndmgr_flushKeyDown()
{
    CCI_VOID_C(window_flushKeyDown(ITEM));
}

bool wndmgr_consumeKeyDown(gKEYS* modifiers, gKEYS* key)
{
    CCI_BOOL_C(window_consumeKeyDown(ITEM, modifiers, key));
}

bool wndmgr_discardKeyDown()
{
    CCI_BOOL_C(window_discardKeyDown(ITEM));
}

bool wndmgr_isKeyDownLost()
{
    CCI_BOOL_C(window_isKeyDownLost(ITEM));
}

bool wndmgr_isKeyDownBufferFull()
{
    CCI_BOOL_C(window_isKeyDownBufferFull(ITEM));
}



bool wndmgr_isKeyUpAvailable()
{
    CCI_BOOL_C(window_isKeyUpAvailable(ITEM));
}

void wndmgr_flushKeyUp()
{
    CCI_VOID_C(window_flushKeyUp(ITEM));
}

bool wndmgr_consumeKeyUp(gKEYS* modifiers, gKEYS* key)
{
    CCI_BOOL_C(window_consumeKeyUp(ITEM, modifiers, key));
}

bool wndmgr_discardKeyUp()
{
    CCI_BOOL_C(window_discardKeyUp(ITEM));
}

bool wndmgr_isKeyUpLost()
{
    CCI_BOOL_C(window_isKeyUpLost(ITEM));
}

bool wndmgr_isKeyUpBufferFull()
{
    CCI_BOOL_C(window_isKeyUpBufferFull(ITEM));
}



bool wndmgr_isMouseDownAvailable()
{
    CCI_BOOL_C(window_isMouseDownAvailable(ITEM));
}

void wndmgr_flushMouseDown()
{
    CCI_VOID_C(window_flushMouseDown(ITEM));
}

bool wndmgr_consumeMouseDown(gPOINT** location, gMOUSEBUTTONS* button)
{
    CCI_BOOL_C(window_consumeMouseDown(ITEM, location, button));
}

bool wndmgr_discardMouseDown()
{
    CCI_BOOL_C(window_discardMouseDown(ITEM));
}

bool wndmgr_isMouseDownLost()
{
    CCI_BOOL_C(window_isMouseDownLost(ITEM));
}

bool wndmgr_isMouseDownBufferFull()
{
    CCI_BOOL_C(window_isMouseDownBufferFull(ITEM));
}



bool wndmgr_isMouseUpAvailable()
{
    CCI_BOOL_C(window_isMouseUpAvailable(ITEM));
}

void wndmgr_flushMouseUp()
{
    CCI_VOID_C(window_flushMouseUp(ITEM));
}

bool wndmgr_consumeMouseUp(gPOINT** location, gMOUSEBUTTONS* button)
{
    CCI_BOOL_C(window_consumeMouseUp(ITEM, location, button));
}

bool wndmgr_discardMouseUp()
{
    CCI_BOOL_C(window_discardMouseUp(ITEM));
}

bool wndmgr_isMouseUpLost()
{
    CCI_BOOL_C(window_isMouseUpLost(ITEM));
}

bool wndmgr_isMouseUpBufferFull()
{
    CCI_BOOL_C(window_isMouseUpBufferFull(ITEM));
}



int wndmgr_getCanvasWidth()
{
    CCI_INT_C(window_getCanvasWidth(ITEM));
}

int wndmgr_getCanvasHeight()
{
    CCI_INT_C(window_getCanvasHeight(ITEM));
}



gCOLOR* wndmgr_getBorderColor()
{
    CCI_GET_COLOR_C(window_getBorderColor(ITEM));
}

void wndmgr_setBorderColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(window_setBorderColor(ITEM, color));
}

gCOLOR* wndmgr_getFillColor()
{
    CCI_GET_COLOR_C(window_getFillColor(ITEM));
}

void wndmgr_setFillColor(const gCOLOR* color)
{
    CCI_SET_COLOR_C(window_setFillColor(ITEM, color));
}



bool wndmgr_drawBorderSquare(int x, int y, int side)
{
    CCI_BOOL_C(window_drawBorderSquare(ITEM, x, y, side));
}

bool wndmgr_drawFillSquare(int x, int y, int side)
{
    CCI_BOOL_C(window_drawFillSquare(ITEM, x, y, side));
}



bool wndmgr_drawBorderRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(window_drawBorderRectangle(ITEM, x, y, width, height));
}

bool wndmgr_drawFillRectangle(int x, int y, int width, int height)
{
    CCI_BOOL_C(window_drawFillRectangle(ITEM, x, y, width, height));
}



bool wndmgr_drawBorderCircle(int x, int y, int radius)
{
    CCI_BOOL_C(window_drawBorderCircle(ITEM, x, y, radius));
}

bool wndmgr_drawFillCircle(int x, int y, int radius)
{
    CCI_BOOL_C(window_drawFillCircle(ITEM, x, y, radius));
}



bool wndmgr_drawBorderEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(window_drawBorderEllipse(ITEM, x, y, width, height));
}

bool wndmgr_drawFillEllipse(int x, int y, int width, int height)
{
    CCI_BOOL_C(window_drawFillEllipse(ITEM, x, y, width, height));
}



bool wndmgr_drawImage(int x, int y, gIMAGE* image)
{
    CCI_BOOL_C(window_drawImage(ITEM, x, y, image));
}

bool wndmgr_drawIcon(int x, int y, gICON* icon)
{
    CCI_BOOL_C(window_drawIcon(ITEM, x, y, icon));
}
