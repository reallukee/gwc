//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVAS.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "CANVAS.h"
#include "CANVASHELPER.h"
#include "macros.h"

#include "ICONHELPER.h"
#include "IMAGEHELPER.h"

#include "SPRITE.h"
#include "SPRITEHELPER.h"

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



bool canvas_clear(const CANVAS* canvas, const gCOLOR* color)
{
    Drawing::Color managedColor = Drawing::Color::FromArgb(
        color_getAlpha(color),
        color_getRed  (color),
        color_getGreen(color),
        color_getBlue (color)
    );

    CCI_BOOL_C(CanvasHost, canvas, Clear(managedColor));
}

bool canvas_drawCanvas(const CANVAS* canvas, int x, int y, const CANVAS* canvas_)
{
    CanvasHost* canvasHost = canvasHelper_get(canvas_);

    GWC::Canvas^ managedCanvas = canvasHost->invoke();

    CCI_BOOL_C(CanvasHost, canvas, DrawCanvas(x, y, managedCanvas));
}

bool canvas_drawSprite(const CANVAS* canvas, int x, int y, const SPRITE* sprite)
{
    SpriteHost* spriteHost = spriteHelper_get(sprite);

    GWC::Sprite^ managedSprite = spriteHost->invoke();

    CCI_BOOL_C(CanvasHost, canvas, DrawSprite(x, y, managedSprite));
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



static Drawing::Bitmap^ toManagedBitmap(Gdiplus::Bitmap* nativeBitmap)
{
    if (!nativeBitmap)
    {
        return nullptr;
    }

    UINT width  = nativeBitmap->GetWidth();
    UINT height = nativeBitmap->GetHeight();

    Gdiplus::Rect nativeRect(
        0,
        0,
        width,
        height
    );

    Gdiplus::BitmapData nativeBitmapData;

    bool result = nativeBitmap->LockBits(
        &nativeRect,
        Gdiplus::ImageLockModeRead,
        PixelFormat32bppPARGB,
        &nativeBitmapData
    );

    if (result != Gdiplus::Status::Ok)
    {
        return nullptr;
    }

    Drawing::Bitmap^ managedBitmap = nullptr;

    try
    {
        managedBitmap = gcnew Drawing::Bitmap(
            width,
            height,
            nativeBitmapData.Stride,
            Drawing::Imaging::PixelFormat::Format32bppPArgb,
            (IntPtr)nativeBitmapData.Scan0
        );

        Drawing::Rectangle managedRectangle(
            0,
            0,
            width,
            height
        );

        Drawing::Bitmap^ copy = managedBitmap->Clone(
            managedRectangle,
            Drawing::Imaging::PixelFormat::Format32bppPArgb
        );

        delete managedBitmap;

        managedBitmap = copy;
    }
    catch (Exception^ ex)
    {
        Windows::Forms::MessageBox::Show(ex->Message);
    }
    finally
    {
        nativeBitmap->UnlockBits(&nativeBitmapData);
    }

    return managedBitmap;
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

    Bitmap* nativeImage = imageHelper_get(image);

    if (nativeImage == NULL)
    {
        return false;
    }

    Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        managedImage = toManagedBitmap(nativeImage);

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

    HICON nativeIcon = iconHelper_get(icon);

    if (nativeIcon == NULL)
    {
        return false;
    }

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



CanvasHost* canvasHelper_get(const CANVAS* canvas)
{
    CanvasHost* canvasHost = static_cast<CanvasHost*>(canvas->canvas);

    return canvasHost;
}
