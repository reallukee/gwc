//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  WINDOW.c
//

#include "WINDOW.h"
#include "window_macros.h"

#include "WindowHandler.clr.hpp"

using namespace Reallukee::GWC::Interop;

typedef struct WINDOW {} WINDOW;

WINDOW* window_new()
{
    IntPtr managedHandle = WindowHandler::alloc();

    WINDOW* nativeHandle = reinterpret_cast<WINDOW*>(managedHandle.ToPointer());

    WINDOW* window = nativeHandle;

    return window;
}

void window_delete(WINDOW* window)
{
    WINDOW* nativeHandle = window;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (WindowHandler::isNull(managedHandle))
    {
        return;
    }

    WindowHandler::free(managedHandle);
}

bool window_open(WINDOW* window)
{
    INVOKE_C_BOOL(window, Open());
}

bool window_shutdown(WINDOW* window)
{
    INVOKE_C_BOOL(window, Shutdown());
}

bool window_isOpen(WINDOW* window)
{
    INVOKE_C_BOOL(window, IsOpen);
}

bool window_isShutdown(WINDOW* window)
{
    INVOKE_C_BOOL(window, IsShutdown);
}

bool window_drawBorderRectangle(WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_C_BOOL(window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawFillRectangle(WINDOW* window, int x, int y, int width, int height)
{
    INVOKE_C_BOOL(window, DrawFillRectangle(x, y, width, height));
}
