//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVAS.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "CANVAS.h"
#include "canvas_macros.h"

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



bool canvas_isInitialized(const CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return false;
    }

    return canvas->canvas != NULL;
}



COLOR* canvas_getBorderColor(const CANVAS* canvas)
{
    INVOKE_CANVAS_GET_COLOR_C(canvas, BorderColor);
}

void canvas_setBorderColor(const CANVAS* canvas, const COLOR* color)
{
    INVOKE_CANVAS_SET_COLOR_C(canvas, BorderColor, color);
}

COLOR* canvas_getFillColor(const CANVAS* canvas)
{
    INVOKE_CANVAS_GET_COLOR_C(canvas, FillColor);
}

void canvas_setFillColor(const CANVAS* canvas, const COLOR* color)
{
    INVOKE_CANVAS_SET_COLOR_C(canvas, FillColor, color);
}



bool canvas_drawBorderSquare(const CANVAS* canvas, int x, int y, int side)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawBorderSquare(x, y, side));
}

bool canvas_drawFillSquare(const CANVAS* canvas, int x, int y, int side)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawFillSquare(x, y, side));
}

bool canvas_drawBorderRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawBorderRectangle(x, y, width, height));
}

bool canvas_drawFillRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawFillRectangle(x, y, width, height));
}
