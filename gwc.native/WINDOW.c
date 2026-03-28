//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
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
    void* window;
} WINDOW;



WINDOW* window_new(int width, int height)
{
    IntPtr managedHandle = WindowHandler::Alloc(width, height);

    WINDOW* window = (WINDOW*)calloc(1, sizeof(WINDOW));

    if (window == NULL)
    {
        return NULL;
    }

    void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

    window->window = nativeHandle;

    return window;
}

void window_delete(WINDOW* window)
{
    if (window == NULL)
    {
        return;
    }

    void* nativeHandle = window->window;

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
    INVOKE_WINDOW_BOOL_C(window, Open());
}

bool window_shutdown(const WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, Shutdown());
}

bool window_isOpen(const WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, IsOpen);
}

bool window_isShutdown(const WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, IsShutdown);
}



COLOR* window_getBorderColor(const WINDOW* window)
{
    INVOKE_WINDOW_GET_COLOR_C(window, BorderColor);
}

void window_setBorderColor(const WINDOW* window, const COLOR* color)
{
    INVOKE_WINDOW_SET_COLOR_C(window, BorderColor, color);
}

COLOR* window_getFillColor(const WINDOW* window)
{
    INVOKE_WINDOW_GET_COLOR_C(window, FillColor);
}

void window_setFillColor(const WINDOW* window, const COLOR* color)
{
    INVOKE_WINDOW_SET_COLOR_C(window, FillColor, color);
}



bool window_drawBorderSquare(const WINDOW* window, int x, int y, int side)
{
    INVOKE_WINDOW_BOOL_C(window, DrawBorderSquare(x, y, side));
}

bool window_drawFillSquare(const WINDOW* window, int x, int y, int side)
{
    INVOKE_WINDOW_BOOL_C(window, DrawFillSquare(x, y, side));
}

bool window_drawBorderRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_WINDOW_BOOL_C(window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawFillRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_WINDOW_BOOL_C(window, DrawFillRectangle(x, y, width, height));
}
