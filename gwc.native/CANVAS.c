//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  CANVAS.c
//

#include "CANVAS.h"
#include "canvas_macros.h"

#include "gwc.clr.hpp"

typedef struct CANVAS {
    void* canvas;
} CANVAS;

CANVAS* canvas_new(int width, int height)
{
    IntPtr managedHandle = CanvasHandler::Alloc(width, height);

    CANVAS* canvas = (CANVAS*)calloc(1, sizeof(CANVAS));

    if (canvas == NULL)
    {
        return NULL;
    }

    void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

    canvas->canvas = nativeHandle;

    return canvas;
}

void canvas_delete(CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return;
    }

    void* nativeHandle = canvas->canvas;

    if (nativeHandle)
    {
        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
        {
            return;
        }

        CanvasHandler::Free(managedHandle);
    }

    free(canvas);
}

bool canvas_isInitialized(CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return false;
    }

    return canvas->canvas != NULL;
}



bool canvas_drawBorderRectangle(CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawBorderRectangle(x, y, width, height));
}

bool canvas_drawFillRectangle(CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawFillRectangle(x, y, width, height));
}
