//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
    CLRCanvasHost canvas;
} CANVAS;



CANVAS* canvas_new(int width, int height)
{
    CANVAS* canvas = (CANVAS*)calloc(1, sizeof(CANVAS));

    if (canvas == NULL)
    {
        return NULL;
    }

    CanvasHost* host = new CanvasHost(width, height);

    canvas->canvas = static_cast<CLRCanvasHost>(host);

    return canvas;
}

void canvas_delete(CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return;
    }

    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas);

    delete host;

    free(canvas);
}



bool canvas_isInitialized(const CANVAS* canvas)
{
    if (canvas == NULL)
    {
        return false;
    }

    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas);

    if (host == nullptr)
    {
        return false;
    }

    return !host->isNull();
}



gCOLOR* canvas_getBorderColor(const CANVAS* canvas)
{
    CCI_CANVAS_GET_COLOR_C(canvas, BorderColor);
}

void canvas_setBorderColor(const CANVAS* canvas, const gCOLOR* color)
{
    CCI_CANVAS_SET_COLOR_C(canvas, BorderColor, color);
}

gCOLOR* canvas_getFillColor(const CANVAS* canvas)
{
    CCI_CANVAS_GET_COLOR_C(canvas, FillColor);
}

void canvas_setFillColor(const CANVAS* canvas, const gCOLOR* color)
{
    CCI_CANVAS_SET_COLOR_C(canvas, FillColor, color);
}



int canvas_getWidth(const CANVAS* canvas)
{
    CCI_CANVAS_INT_C(canvas, Width);
}

int canvas_getHeight(const CANVAS* canvas)
{
    CCI_CANVAS_INT_C(canvas, Height);
}



bool canvas_drawBorderSquare(const CANVAS* canvas, int x, int y, int side)
{
    CCI_CANVAS_BOOL_C(canvas, DrawBorderSquare(x, y, side));
}

bool canvas_drawFillSquare(const CANVAS* canvas, int x, int y, int side)
{
    CCI_CANVAS_BOOL_C(canvas, DrawFillSquare(x, y, side));
}



bool canvas_drawBorderRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_CANVAS_BOOL_C(canvas, DrawBorderRectangle(x, y, width, height));
}

bool canvas_drawFillRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_CANVAS_BOOL_C(canvas, DrawFillRectangle(x, y, width, height));
}



bool canvas_drawBorderCircle(const CANVAS* canvas, int x, int y, int radius)
{
    CCI_CANVAS_BOOL_C(canvas, DrawBorderCircle(x, y, radius));
}

bool canvas_drawFillCircle(const CANVAS* canvas, int x, int y, int radius)
{
    CCI_CANVAS_BOOL_C(canvas, DrawFillCircle(x, y, radius));
}



bool canvas_drawBorderEllipse(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_CANVAS_BOOL_C(canvas, DrawBorderEllipse(x, y, width, height));
}

bool canvas_drawFillEllipse(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_CANVAS_BOOL_C(canvas, DrawFillEllipse(x, y, width, height));
}



void canvas_render(const CANVAS* canvas)
{
    CCI_CANVAS_VOID_C(canvas, Render());
}
