//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SPRITE.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "SPRITE.h"
#include "macros.h"

#include "ICONHELPER.h"
#include "IMAGEHELPER.h"

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



bool sprite_drawBorderSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderSquare(x, y, side));
}

bool sprite_drawFillSquare(const SPRITE* sprite, int x, int y, int side)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillSquare(x, y, side));
}



bool sprite_drawBorderRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderRectangle(x, y, width, height));
}

bool sprite_drawFillRectangle(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillRectangle(x, y, width, height));
}



bool sprite_drawBorderCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderCircle(x, y, radius));
}

bool sprite_drawFillCircle(const SPRITE* sprite, int x, int y, int radius)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillCircle(x, y, radius));
}



bool sprite_drawBorderEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawBorderEllipse(x, y, width, height));
}

bool sprite_drawFillEllipse(const SPRITE* sprite, int x, int y, int width, int height)
{
    CCI_BOOL_C(SpriteHost, sprite, DrawFillEllipse(x, y, width, height));
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

bool sprite_drawImage(const SPRITE* sprite, int x, int y, gIMAGE* image)
{
    CC_BOOL_C(SpriteHost, sprite);

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

bool sprite_drawIcon(const SPRITE* sprite, int x, int y, gICON* icon)
{
    CC_BOOL_C(SpriteHost, sprite);

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



void sprite_render(const SPRITE* sprite)
{
    CCI_VOID_C(SpriteHost, sprite, Render());
}
