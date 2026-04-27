//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WINDOW.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "WINDOW.h"
#include "window_macros.h"

typedef struct WINDOW {
    CLRWindowHost window;
} WINDOW;



WINDOW* window_new(int width, int height)
{
    WINDOW* window = (WINDOW*)calloc(1, sizeof(WINDOW));

    if (window == NULL)
    {
        return NULL;
    }

    WindowHost* host = new WindowHost(width, height);

    window->window = static_cast<CLRWindowHost>(host);

    return window;
}

void window_delete(WINDOW* window)
{
    if (window == NULL)
    {
        return;
    }

    WindowHost* host = static_cast<WindowHost*>(window->window);

    delete host;

    free(window);
}



bool window_isInitialized(const WINDOW* window)
{
    if (window == NULL)
    {
        return false;
    }

    WindowHost* host = static_cast<WindowHost*>(window->window);

    if (host == nullptr)
    {
        return false;
    }

    return !host->isNull();
}



bool window_open(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, Open());
}

bool window_shutdown(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, Shutdown());
}



bool window_isOpen(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsOpen);
}

bool window_isShutdown(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsShutdown);
}



gCOLOR* window_getBorderColor(const WINDOW* window)
{
    CCI_WINDOW_GET_COLOR_C(window, BorderColor);
}

void window_setBorderColor(const WINDOW* window, const gCOLOR* color)
{
    CCI_WINDOW_SET_COLOR_C(window, BorderColor, color);
}

gCOLOR* window_getFillColor(const WINDOW* window)
{
    CCI_WINDOW_GET_COLOR_C(window, FillColor);
}

void window_setFillColor(const WINDOW* window, const gCOLOR* color)
{
    CCI_WINDOW_SET_COLOR_C(window, FillColor, color);
}



void window_wait(const WINDOW* window, int milliseconds)
{
    CCI_WINDOW_VOID_C(window, Wait(milliseconds));
}



int window_getWindowWidth(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, WindowWidth);
}

int window_getWindowHeight(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, WindowHeight);
}

int window_getRenderWidth(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, RenderWidth);
}

int window_getRenderHeight(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, RenderHeight);
}



bool window_isKeyDownAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyDownAvailable);
}

void window_flushKeyDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, FlushKeyDown());
}

bool window_consumeKeyDown(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_WINDOW_BOOL_C(window);

    if (key == NULL)
    {
        return false;
    }

    Windows::Forms::Keys managedModifiers;
    Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyDown(
        managedModifiers, managedKey
    );

    int rawModifiers = static_cast<int>(managedModifiers);
    int rawKey = static_cast<int>(managedKey);

    *modifiers = static_cast<gKEYS>(rawModifiers);
    *key       = static_cast<gKEYS>(rawKey);

    return result;
}

bool window_discardKeyDown(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, DiscardKeyDown());
}

void window_waitKeyDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, WaitKeyDown());
}

bool window_isKeyDownLost(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyDownLost);
}

bool window_isKeyDownBufferFull(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyDownBufferFull);
}



bool window_isKeyUpAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyUpAvailable);
}

void window_flushKeyUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, FlushKeyUp());
}

bool window_consumeKeyUp(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_WINDOW_BOOL_C(window);

    if (key == NULL)
    {
        return false;
    }

    Windows::Forms::Keys managedModifiers;
    Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyUp(
        managedModifiers, managedKey
    );

    int rawModifiers = static_cast<int>(managedModifiers);
    int rawKey = static_cast<int>(managedKey);

    *modifiers = static_cast<gKEYS>(rawModifiers);
    *key       = static_cast<gKEYS>(rawKey);

    return result;
}

bool window_discardKeyUp(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, DiscardKeyUp());
}

void window_waitKeyUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, WaitKeyUp());
}

bool window_isKeyUpLost(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyUpLost);
}

bool window_isKeyUpBufferFull(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyUpBufferFull);
}



bool window_isMouseDownAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseDownAvailable);
}

void window_flushMouseDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, FlushMouseDown());
}

bool window_consumeMouseDown(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_WINDOW_BOOL_C(window);

    Drawing::Point               managedLocation;
    Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseDown(
        managedLocation, managedButton
    );

    int rawButton = static_cast<int>(managedButton);

    *location = point_new(managedLocation.X, managedLocation.Y);
    *button   = static_cast<gMOUSEBUTTONS>(rawButton);

    return result;
}

bool window_discardMouseDown(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, DiscardMouseDown());
}

void window_waitMouseDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, WaitMouseDown());
}

bool window_isMouseDownLost(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseDownLost);
}

bool window_isMouseDownBufferFull(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseDownBufferFull);
}



bool window_isMouseUpAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseUpAvailable);
}

void window_flushMouseUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, FlushMouseUp());
}

bool window_consumeMouseUp(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_WINDOW_BOOL_C(window);

    Drawing::Point               managedLocation;
    Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseUp(
        managedLocation, managedButton
    );

    int rawButton = static_cast<int>(managedButton);

    *location = point_new(managedLocation.X, managedLocation.Y);
    *button   = static_cast<gMOUSEBUTTONS>(rawButton);

    return result;
}

bool window_discardMouseUp(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, DiscardMouseUp());
}

void window_waitMouseUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, WaitMouseUp());
}

bool window_isMouseUpLost(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseUpLost);
}

bool window_isMouseUpBufferFull(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseUpBufferFull);
}



int window_getCanvasWidth(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, CanvasWidth);
}

int window_getCanvasHeight(const WINDOW* window)
{
    CCI_WINDOW_INT_C(window, CanvasHeight);
}



bool window_drawBorderSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_WINDOW_BOOL_C(window, DrawBorderSquare(x, y, side));
}

bool window_drawFillSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_WINDOW_BOOL_C(window, DrawFillSquare(x, y, side));
}



bool window_drawBorderRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_WINDOW_BOOL_C(window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawFillRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_WINDOW_BOOL_C(window, DrawFillRectangle(x, y, width, height));
}



bool window_drawBorderCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_WINDOW_BOOL_C(window, DrawBorderCircle(x, y, radius));
}

bool window_drawFillCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_WINDOW_BOOL_C(window, DrawFillCircle(x, y, radius));
}



bool window_drawBorderEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_WINDOW_BOOL_C(window, DrawBorderEllipse(x, y, width, height));
}

bool window_drawFillEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_WINDOW_BOOL_C(window, DrawFillEllipse(x, y, width, height));
}
