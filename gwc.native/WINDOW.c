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

#include "WINDOW.h"
#include "window_macros.h"

#include "gwc.clr.hpp"

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

bool window_isInitialized(WINDOW* window)
{
    if (window == NULL)
    {
        return false;
    }

    return window->window != NULL;
}



bool window_open(WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, Open());
}

bool window_shutdown(WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, Shutdown());
}

bool window_isOpen(WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, IsOpen);
}

bool window_isShutdown(WINDOW* window)
{
    INVOKE_WINDOW_BOOL_C(window, IsShutdown);
}

bool window_drawBorderRectangle(WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_WINDOW_BOOL_C(window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawFillRectangle(WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_WINDOW_BOOL_C(window, DrawFillRectangle(x, y, width, height));
}
