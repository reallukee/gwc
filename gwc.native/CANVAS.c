//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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
    if (canvas == NULL)
    {
        return color_new(0, 0, 0, 0);
    }

    void* nativeHandle = canvas->canvas;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (CanvasHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    Drawing::Color^ managedBorderColor = CanvasHandler::Invoke(managedHandle)->BorderColor;

    COLOR* nativeColor = color_new(
        (int)managedBorderColor->A,
        (int)managedBorderColor->R,
        (int)managedBorderColor->G,
        (int)managedBorderColor->B
    );

    return nativeColor;
}

void canvas_setBorderColor(const CANVAS* canvas, const COLOR* color)
{
    if (canvas == NULL || color == NULL)
    {
        return;
    }

    void* nativeHandle = canvas->canvas;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (CanvasHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    const COLOR* nativeColor = color;

    Drawing::Color managedColor = Drawing::Color::FromArgb(
        color_getAlpha(nativeColor),
        color_getRed  (nativeColor),
        color_getBlue (nativeColor),
        color_getGreen(nativeColor)
    );

    CanvasHandler::Invoke(managedHandle)->BorderColor = managedColor;
}

COLOR* canvas_getFillColor(const CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return color_new(0, 0, 0, 0);
    }

    void* nativeHandle = canvas->canvas;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (CanvasHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    Drawing::Color^ managedBorderColor = CanvasHandler::Invoke(managedHandle)->FillColor;

    COLOR* nativeColor = color_new(
        (int)managedBorderColor->A,
        (int)managedBorderColor->R,
        (int)managedBorderColor->G,
        (int)managedBorderColor->B
    );

    return nativeColor;
}

void canvas_setFillColor(const CANVAS* canvas, const COLOR* color)
{
    if (canvas == NULL || color == NULL)
    {
        return;
    }

    void* nativeHandle = canvas->canvas;

    IntPtr managedHandle = IntPtr(nativeHandle);

    if (CanvasHandler::IsNull(managedHandle))
    {
        throw gcnew NullReferenceException("");
    }

    const COLOR* nativeColor = color;

    Drawing::Color managedColor = Drawing::Color::FromArgb(
        color_getAlpha(nativeColor),
        color_getRed  (nativeColor),
        color_getBlue (nativeColor),
        color_getGreen(nativeColor)
    );

    CanvasHandler::Invoke(managedHandle)->FillColor = managedColor;
}



bool canvas_drawBorderRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawBorderRectangle(x, y, width, height));
}

bool canvas_drawFillRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    INVOKE_CANVAS_BOOL_C(canvas, DrawFillRectangle(x, y, width, height));
}
