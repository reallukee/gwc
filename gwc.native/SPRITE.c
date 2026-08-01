/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : SPRITE.c
 *
 * Titolo    : SPRITE
 * Sommario  : Sprite
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#include "gwc.clr.hpp"

#include "SPRITE.h"
#include "SPRITEHELPER.h"
#include "macros.h"

#include "ICONHELPER.h"
#include "IMAGEHELPER.h"

#include "CANVAS.h"
#include "CANVASHELPER.h"

typedef struct SPRITE {
    CLRSpriteHost sprite;
} SPRITE;



SPRITE* sprite_new(int width, int height)
{
    SPRITE* sprite = (SPRITE*)calloc(1, sizeof(SPRITE));

    if (sprite == NULL)
    {
        return NULL;
    }

    SpriteHost* host = new SpriteHost(width, height);

    sprite->sprite = static_cast<CLRSpriteHost>(host);

    return sprite;
}

void sprite_delete(SPRITE* sprite)
{
    if (sprite == NULL)
    {
        return;
    }

    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite);

    delete host;

    free(sprite);
}



bool sprite_isInitialized(const SPRITE* sprite)
{
    if (sprite == NULL)
    {
        return false;
    }

    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite);

    if (host == NULL)
    {
        return false;
    }

    return !host->isNull();
}



gCOLOR* sprite_getBorderColor(const SPRITE* sprite)
{
    CCI_GET_COLOR_C(SpriteHost, sprite, BorderColor);
}

void sprite_setBorderColor(const SPRITE* sprite, const gCOLOR* color)
{
    CCI_SET_COLOR_C(SpriteHost, sprite, BorderColor, color);
}

gCOLOR* sprite_getFillColor(const SPRITE* sprite)
{
    CCI_GET_COLOR_C(SpriteHost, sprite, FillColor);
}

void sprite_setFillColor(const SPRITE* sprite, const gCOLOR* color)
{
    CCI_SET_COLOR_C(SpriteHost, sprite, FillColor, color);
}

gCOLOR* sprite_getBackColor(const SPRITE* sprite)
{
    CCI_GET_COLOR_C(SpriteHost, sprite, BackColor);
}

void sprite_setBackColor(const SPRITE* sprite, const gCOLOR* color)
{
    CCI_SET_COLOR_C(SpriteHost, sprite, BackColor, color);
}



gRECTANGLE* sprite_bounds(const SPRITE* sprite)
{
    CCI_GET_RECTANGLE_C(SpriteHost, sprite, Bounds);
}

gSIZE* sprite_size(const SPRITE* sprite)
{
    CCI_GET_SIZE_C(SpriteHost, sprite, Size);
}

gPOINT* sprite_location(const SPRITE* sprite)
{
    CCI_GET_POINT_C(SpriteHost, sprite, Location);
}



int sprite_getWidth(const SPRITE* sprite)
{
    CCI_INT_C(SpriteHost, sprite, Width);
}

int sprite_getHeight(const SPRITE* sprite)
{
    CCI_INT_C(SpriteHost, sprite, Height);
}



bool sprite_clear(const SPRITE* sprite)
{
    CCI_BOOL_C(SpriteHost, sprite, Clear());
}

bool sprite_clearArea(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, ClearArea(x, y, width, height));
}

bool sprite_clearF(const SPRITE* sprite)
{
    CCI_BOOL_C(SpriteHost, sprite, ClearF());
}

bool sprite_clearAreaF(const SPRITE* sprite, float x, float y, float width, float height)
{
    CCI_BOOL_C(SpriteHost, sprite, ClearAreaF(x, y, width, height));
}



bool sprite_drawCanvas(const SPRITE* sprite, int x, int y, const CANVAS* canvas)
{
    CanvasHost* canvasHost = canvasHelper_get(canvas);

    GWC::Canvas^ managedCanvas = canvasHost->invoke();

    CCI_BOOL_C(SpriteHost, sprite, DrawCanvas(x, y, managedCanvas));
}

bool sprite_drawCanvasF(const SPRITE* sprite, float x, float y, const CANVAS* canvas)
{
    CanvasHost* canvasHost = canvasHelper_get(canvas);

    GWC::Canvas^ managedCanvas = canvasHost->invoke();

    CCI_BOOL_C(SpriteHost, sprite, DrawCanvasF(x, y, managedCanvas));
}



bool sprite_drawSprite(const SPRITE* sprite, int x, int y, const SPRITE* sprite_)
{
    SpriteHost* spriteHost = spriteHelper_get(sprite_);

    GWC::Sprite^ managedSprite = spriteHost->invoke();

    CCI_BOOL_C(SpriteHost, sprite, DrawSprite(x, y, managedSprite));
}

bool sprite_drawSpriteF(const SPRITE* sprite, float x, float y, const SPRITE* sprite_)
{
    SpriteHost* spriteHost = spriteHelper_get(sprite_);

    GWC::Sprite^ managedSprite = spriteHost->invoke();

    CCI_BOOL_C(SpriteHost, sprite, DrawSpriteF(x, y, managedSprite));
}



bool sprite_drawBorderSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderSquare(x, y, side));
}

bool sprite_drawBorderSquareF(const SPRITE* sprite, float x, float y, float side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderSquareF(x, y, side));
}

bool sprite_drawFillSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillSquare(x, y, side));
}

bool sprite_drawFillSquareF(const SPRITE* sprite, float x, float y, float side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillSquareF(x, y, side));
}



bool sprite_drawBorderRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderRectangle(x, y, width, height));
}

bool sprite_drawBorderRectangleF(const SPRITE* sprite, float x, float y, float width, float height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderRectangleF(x, y, width, height));
}

bool sprite_drawFillRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillRectangle(x, y, width, height));
}

bool sprite_drawFillRectangleF(const SPRITE* sprite, float x, float y, float width, float height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillRectangleF(x, y, width, height));
}



bool sprite_drawBorderCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderCircle(x, y, radius));
}

bool sprite_drawBorderCircleF(const SPRITE* sprite, float x, float y, float radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderCircleF(x, y, radius));
}

bool sprite_drawFillCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillCircle(x, y, radius));
}

bool sprite_drawFillCircleF(const SPRITE* sprite, float x, float y, float radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillCircleF(x, y, radius));
}



bool sprite_drawBorderEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderEllipse(x, y, width, height));
}

bool sprite_drawBorderEllipseF(const SPRITE* sprite, float x, float y, float width, float height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderEllipseF(x, y, width, height));
}

bool sprite_drawFillEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillEllipse(x, y, width, height));
}

bool sprite_drawFillEllipseF(const SPRITE* sprite, float x, float y, float width, float height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillEllipseF(x, y, width, height));
}



static System::Drawing::Bitmap^ toManagedBitmap(Gdiplus::Bitmap* nativeBitmap)
{
    if (!nativeBitmap)
    {
        return nullptr;
    }

    UINT width = nativeBitmap->GetWidth();
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

    System::Drawing::Bitmap^ managedBitmap = nullptr;

    try
    {
        managedBitmap = gcnew System::Drawing::Bitmap(
            width,
            height,
            nativeBitmapData.Stride,
            System::Drawing::Imaging::PixelFormat::Format32bppPArgb,
            (IntPtr)nativeBitmapData.Scan0
        );

        System::Drawing::Rectangle managedRectangle(
            0,
            0,
            width,
            height
        );

        System::Drawing::Bitmap^ copy = managedBitmap->Clone(
            managedRectangle,
            System::Drawing::Imaging::PixelFormat::Format32bppPArgb
        );

        delete managedBitmap;

        managedBitmap = copy;
    }
    finally
    {
        nativeBitmap->UnlockBits(&nativeBitmapData);
    }

    return managedBitmap;
}

static Bitmap* getNativeImage(const gIMAGE* image)
{
    if (!image_isLoaded(image))
    {
        return false;
    }

    Bitmap* nativeImage = imageHelper_get(image);

    if (nativeImage == nullptr)
    {
        return false;
    }

    return nativeImage;
}

static HICON getNativeIcon(const gICON* icon)
{
    if (!icon_isLoaded(icon))
    {
        return false;
    }

    HICON nativeIcon = iconHelper_get(icon);

    if (nativeIcon == nullptr)
    {
        return false;
    }

    return nativeIcon;
}



bool sprite_drawImage(const SPRITE* sprite, int x, int y, gIMAGE* image)
{
    CC_BOOL_C(SpriteHost, sprite);

    Bitmap* nativeImage = getNativeImage(image);

    System::Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        managedImage = toManagedBitmap(nativeImage);

        result = _host->invoke()->DrawImage(x, y, managedImage);
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

bool sprite_drawImageF(const SPRITE* sprite, float x, float y, gIMAGE* image)
{
    CC_BOOL_C(SpriteHost, sprite);

    Bitmap* nativeImage = getNativeImage(image);

    System::Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        managedImage = toManagedBitmap(nativeImage);

        result = _host->invoke()->DrawImageF(x, y, managedImage);
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

bool sprite_drawIcon(const SPRITE* sprite, int x, int y, gICON* icon)
{
    CC_BOOL_C(SpriteHost, sprite);

    HICON nativeIcon = getNativeIcon(icon);

    System::Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = System::Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIcon(x, y, managedIcon);
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

bool sprite_drawIconF(const SPRITE* sprite, float x, float y, gICON* icon)
{
    CC_BOOL_C(SpriteHost, sprite);

    HICON nativeIcon = getNativeIcon(icon);

    System::Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = System::Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIconF(x, y, managedIcon);
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



void sprite_render(const SPRITE* sprite)
{
    CCI_VOID_C(SpriteHost, sprite, Render());
}



SpriteHost* spriteHelper_get(const SPRITE* sprite)
{
    SpriteHost* spriteHost = static_cast<SpriteHost*>(sprite->sprite);

    return spriteHost;
}
