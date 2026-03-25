//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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
    if (window == NULL)
    {
        return color_new(0, 0, 0, 0);
    }

    void* nativeHandle = window->window;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (WindowHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    Drawing::Color^ managedBorderColor = WindowHandler::Invoke(managedHandle)->BorderColor;

    COLOR* nativeColor = color_new(
        (int)managedBorderColor->A,
        (int)managedBorderColor->R,
        (int)managedBorderColor->G,
        (int)managedBorderColor->B
    );

    return nativeColor;
}

void window_setBorderColor(const WINDOW* window, const COLOR* color)
{
    if (window == NULL || color == NULL)
    {
        return;
    }

    void* nativeHandle = window->window;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (WindowHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    const COLOR* nativeColor = color;

    Drawing::Color managedColor = Drawing::Color::FromArgb(
        color_getAlpha(nativeColor),
        color_getRed(nativeColor),
        color_getBlue(nativeColor),
        color_getGreen(nativeColor)
    );

    WindowHandler::Invoke(managedHandle)->BorderColor = managedColor;
}

COLOR* window_getFillColor(const WINDOW* window)
{
    if (window == NULL)
    {
        return color_new(0, 0, 0, 0);
    }

    void* nativeHandle = window->window;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (WindowHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    Drawing::Color^ managedBorderColor = WindowHandler::Invoke(managedHandle)->FillColor;

    COLOR* nativeColor = color_new(
        (int)managedBorderColor->A,
        (int)managedBorderColor->R,
        (int)managedBorderColor->G,
        (int)managedBorderColor->B
    );

    return nativeColor;
}

void window_setFillColor(const WINDOW* window, const COLOR* color)
{
    if (window == NULL || color == NULL)
    {
        return;
    }

    void* nativeHandle = window->window;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (WindowHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    const COLOR* nativeColor = color;

    Drawing::Color managedColor = Drawing::Color::FromArgb(
        color_getAlpha(nativeColor),
        color_getRed(nativeColor),
        color_getBlue(nativeColor),
        color_getGreen(nativeColor)
    );

    WindowHandler::Invoke(managedHandle)->FillColor = managedColor;
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
