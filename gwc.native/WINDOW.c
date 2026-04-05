//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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
    CLRWindow window;
} WINDOW;



WINDOW* window_new(int width, int height)
{
    IntPtr managedHandle = WindowHandler::Alloc(width, height);

    WINDOW* window = (WINDOW*)calloc(1, sizeof(WINDOW));

    if (window == NULL)
    {
        return NULL;
    }

    CLRWindow nativeHandle = reinterpret_cast<CLRWindow>(managedHandle.ToPointer());

    window->window = nativeHandle;

    return window;
}

void window_delete(WINDOW* window)
{
    if (window == NULL)
    {
        return;
    }

    CLRWindow nativeHandle = window->window;

    if (nativeHandle != NULL)
    {
        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            return;
        }

        WindowHandler::Free(managedHandle);
    }

    free(window);
}



bool window_isInitialized(const WINDOW* window)
{
    if (window == NULL)
    {
        return false;
    }

    return window->window != NULL;
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



Color* window_getBorderColor(const WINDOW* window)
{
    CCI_WINDOW_GET_COLOR_C(window, BorderColor);
}

void window_setBorderColor(const WINDOW* window, const Color* color)
{
    CCI_WINDOW_SET_COLOR_C(window, BorderColor, color);
}

Color* window_getFillColor(const WINDOW* window)
{
    CCI_WINDOW_GET_COLOR_C(window, FillColor);
}

void window_setFillColor(const WINDOW* window, const Color* color)
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

void window_resetKeyDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, ResetKeyDown());
}

bool window_consumeKeyDown(const WINDOW* window, int* key)
{
    CC_WINDOW_BOOL_C(window);

    if (key == NULL)
    {
        return false;
    }

    int _key;

    bool result = WindowHandler::Invoke(managedHandle)->ConsumeKeyDown(_key);

    *key = _key;

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



bool window_isKeyUpAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsKeyUpAvailable);
}

void window_resetKeyUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, ResetKeyUp());
}

bool window_consumeKeyUp(const WINDOW* window, int* key)
{
    CC_WINDOW_BOOL_C(window);

    if (key == NULL)
    {
        return false;
    }

    int _key;

    bool result = WindowHandler::Invoke(managedHandle)->ConsumeKeyUp(_key);

    *key = _key;

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



bool window_isMouseDownAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseDownAvailable);
}

void window_resetMouseDown(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, ResetMouseDown());
}

bool window_consumeMouseDown(const WINDOW* window, Point** location, int* button)
{
    CC_WINDOW_BOOL_C(window);

    Drawing::Point _location;
    int            _button;

    bool result = WindowHandler::Invoke(managedHandle)->ConsumeMouseDown(_location, _button);

    *location = point_new(_location.X, _location.Y);
    *button   = _button;

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



bool window_isMouseUpAvailable(const WINDOW* window)
{
    CCI_WINDOW_BOOL_C(window, IsMouseUpAvailable);
}

void window_resetMouseUp(const WINDOW* window)
{
    CCI_WINDOW_VOID_C(window, ResetMouseUp());
}

bool window_consumeMouseUp(const WINDOW* window, Point** location, int* button)
{
    CC_WINDOW_BOOL_C(window);

    Drawing::Point _location;
    int            _button;

    bool result = WindowHandler::Invoke(managedHandle)->ConsumeMouseUp(_location, _button);

    *location = point_new(_location.X, _location.Y);
    *button   = _button;

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
