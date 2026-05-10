//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVAS.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "CANVAS.h"
#include "macros.h"

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

    if (host == NULL)
    {
        return false;
    }

    return !host->isNull();
}



gCOLOR* canvas_getBorderColor(const CANVAS* canvas)
{
    CCI_GET_COLOR_C(CanvasHost, canvas, BorderColor);
}

void canvas_setBorderColor(const CANVAS* canvas, const gCOLOR* color)
{
    CCI_SET_COLOR_C(CanvasHost, canvas, BorderColor, color);
}

gCOLOR* canvas_getFillColor(const CANVAS* canvas)
{
    CCI_GET_COLOR_C(CanvasHost, canvas, FillColor);
}

void canvas_setFillColor(const CANVAS* canvas, const gCOLOR* color)
{
    CCI_SET_COLOR_C(CanvasHost, canvas, FillColor, color);
}



gRECTANGLE* canvas_bounds(const CANVAS* canvas)
{
    CCI_GET_RECTANGLE_C(CanvasHost, canvas, Bounds);
}

gSIZE* canvas_size(const CANVAS* canvas)
{
    CCI_GET_SIZE_C(CanvasHost, canvas, Size);
}

gPOINT* canvas_location(const CANVAS* canvas)
{
    CCI_GET_POINT_C(CanvasHost, canvas, Location);
}



int canvas_getWidth(const CANVAS* canvas)
{
    CCI_INT_C(CanvasHost, canvas, Width);
}

int canvas_getHeight(const CANVAS* canvas)
{
    CCI_INT_C(CanvasHost, canvas, Height);
}



bool canvas_drawBorderSquare(const CANVAS* canvas, int x, int y, int side)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawBorderSquare(x, y, side));
}

bool canvas_drawFillSquare(const CANVAS* canvas, int x, int y, int side)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawFillSquare(x, y, side));
}



bool canvas_drawBorderRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawBorderRectangle(x, y, width, height));
}

bool canvas_drawFillRectangle(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawFillRectangle(x, y, width, height));
}



bool canvas_drawBorderCircle(const CANVAS* canvas, int x, int y, int radius)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawBorderCircle(x, y, radius));
}

bool canvas_drawFillCircle(const CANVAS* canvas, int x, int y, int radius)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawFillCircle(x, y, radius));
}



bool canvas_drawBorderEllipse(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawBorderEllipse(x, y, width, height));
}

bool canvas_drawFillEllipse(const CANVAS* canvas, int x, int y, int width, int height)
{
    CCI_BOOL_C(CanvasHost, canvas, DrawFillEllipse(x, y, width, height));
}



bool canvas_drawImage(const CANVAS* canvas, int x, int y, gIMAGE* image)
{
    CC_BOOL_C(CanvasHost, canvas);

    if (image == NULL)
    {
        return false;
    }

    if (!image_isLoaded(image))
    {
        return false;
    }

    HBITMAP nativeImage = image_get(image);

    Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        IntPtr imageHandle = IntPtr(nativeImage);

        managedImage = Drawing::Image::FromHbitmap(imageHandle);

        result = _host->invoke()->DrawImage(x, y, managedImage);
    }
    catch (Exception^ ex)
    {
        Windows::Forms::MessageBox::Show(ex->Message);
    }
    finally
    {
        if (managedImage)
        {
            delete managedImage;
        }
    }

    return result;
}

bool canvas_drawIcon(const CANVAS* canvas, int x, int y, gICON* icon)
{
    CC_BOOL_C(CanvasHost, canvas);

    if (icon == NULL)
    {
        return false;
    }

    if (!icon_isLoaded(icon))
    {
        return false;
    }

    HICON nativeIcon = icon_get(icon);

    Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIcon(x, y, managedIcon);
    }
    catch (Exception^ ex)
    {
        Windows::Forms::MessageBox::Show(ex->Message);
    }
    finally
    {
        if (managedIcon)
        {
            delete managedIcon;
        }
    }

    return result;
}



void canvas_render(const CANVAS* canvas)
{
    CCI_VOID_C(CanvasHost, canvas, Render());
}
