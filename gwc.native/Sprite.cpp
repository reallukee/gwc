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
 * Nome file : Sprite.cpp
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

#include "Sprite.hpp"
#include "SpriteHelper.hpp"
#include "macros.hpp"

#include "ImageHelper.hpp"
#include "IconHelper.hpp"

#include "Canvas.hpp"
#include "CanvasHelper.hpp"

#ifdef __cplusplus

namespace gwc
{
    Sprite::Sprite(int width, int height)
    {
        SpriteHost* host = new SpriteHost(width, height);

        sprite = static_cast<CLRSpriteHost>(host);
    }

    Sprite::Sprite()
    {
        SpriteHost* host = new SpriteHost();

        sprite = static_cast<CLRSpriteHost>(host);
    }

    Sprite::~Sprite()
    {
        SpriteHost* host = static_cast<SpriteHost*>(sprite);

        delete host;
    }



    bool Sprite::isInitialized()
    {
        SpriteHost* host = static_cast<SpriteHost*>(sprite);

        if (host == nullptr)
        {
            return false;
        }

        return !host->isNull();
    }



    gColor Sprite::getBorderColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, sprite, BorderColor);
    }

    void Sprite::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, sprite, BorderColor, color);
    }

    gColor Sprite::getFillColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, sprite, FillColor);
    }

    void Sprite::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, sprite, FillColor, color);
    }

    gColor Sprite::getBackColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, sprite, BackColor);
    }

    void Sprite::setBackColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, sprite, BackColor, color);
    }



    gRectangle Sprite::bounds()
    {
        CCI_GET_RECTANGLE_CPP(SpriteHost, sprite, Bounds);
    }

    gSize Sprite::size()
    {
        CCI_GET_SIZE_CPP(SpriteHost, sprite, Size);
    }

    gPoint Sprite::location()
    {
        CCI_GET_POINT_CPP(SpriteHost, sprite, Location);
    }



    int Sprite::getWidth()
    {
        CCI_INT_CPP(SpriteHost, sprite, Width);
    }

    int Sprite::getHeight()
    {
        CCI_INT_CPP(SpriteHost, sprite, Height);
    }



    bool Sprite::clear()
    {
        CCI_BOOL_CPP(SpriteHost, sprite, Clear());
    }

    bool Sprite::clearArea(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, ClearArea(x, y, width, height));
    }

    bool Sprite::clearF()
    {
        CCI_BOOL_CPP(SpriteHost, sprite, ClearF());
    }

    bool Sprite::clearAreaF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, ClearAreaF(x, y, width, height));
    }



    bool Sprite::drawCanvas(int x, int y, const Canvas* canvas)
    {
        CanvasHost* canvasHost = CanvasHelper::get(canvas);

        GWC::Canvas^ managedCanvas = canvasHost->invoke();

        CCI_BOOL_CPP(SpriteHost, sprite, DrawCanvas(x, y, managedCanvas));
    }

    bool Sprite::drawCanvasF(float x, float y, const Canvas* canvas)
    {
        CanvasHost* canvasHost = CanvasHelper::get(canvas);

        GWC::Canvas^ managedCanvas = canvasHost->invoke();

        CCI_BOOL_CPP(SpriteHost, sprite, DrawCanvasF(x, y, managedCanvas));
    }



    bool Sprite::drawSprite(int x, int y, const Sprite* sprite)
    {
        SpriteHost* spriteHost = SpriteHelper::get(sprite);

        GWC::Sprite^ managedSprite = spriteHost->invoke();

        CCI_BOOL_CPP(SpriteHost, this->sprite, DrawSprite(x, y, managedSprite));
    }

    bool Sprite::drawSpriteF(float x, float y, const Sprite* sprite)
    {
        SpriteHost* spriteHost = SpriteHelper::get(sprite);

        GWC::Sprite^ managedSprite = spriteHost->invoke();

        CCI_BOOL_CPP(SpriteHost, this->sprite, DrawSpriteF(x, y, managedSprite));
    }



    bool Sprite::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderSquare(x, y, side));
    }

    bool Sprite::drawBorderSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderSquareF(x, y, side));
    }

    bool Sprite::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillSquare(x, y, side));
    }

    bool Sprite::drawFillSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillSquareF(x, y, side));
    }



    bool Sprite::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderRectangle(x, y, width, height));
    }

    bool Sprite::drawBorderRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderRectangleF(x, y, width, height));
    }

    bool Sprite::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillRectangle(x, y, width, height));
    }

    bool Sprite::drawFillRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillRectangleF(x, y, width, height));
    }



    bool Sprite::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderCircle(x, y, radius));
    }

    bool Sprite::drawBorderCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderCircleF(x, y, radius));
    }

    bool Sprite::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillCircle(x, y, radius));
    }

    bool Sprite::drawFillCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillCircleF(x, y, radius));
    }



    bool Sprite::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderEllipse(x, y, width, height));
    }

    bool Sprite::drawBorderEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderEllipseF(x, y, width, height));
    }

    bool Sprite::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillEllipse(x, y, width, height));
    }

    bool Sprite::drawFillEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillEllipseF(x, y, width, height));
    }



    static System::Drawing::Bitmap^ toManagedBitmap(Gdiplus::Bitmap* nativeBitmap)
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

    static Bitmap* getNativeImage(const gImage& image)
    {
        if (!image.isLoaded())
        {
            return false;
        }

        Bitmap* nativeImage = ImageHelper::get(image);

        if (nativeImage == nullptr)
        {
            return false;
        }

        return nativeImage;
    }

    static HICON getNativeIcon(const gIcon& icon)
    {
        if (!icon.isLoaded())
        {
            return false;
        }

        HICON nativeIcon = IconHelper::get(icon);

        if (nativeIcon == nullptr)
        {
            return false;
        }

        return nativeIcon;
    }



    bool Sprite::drawImage(int x, int y, const gImage& image)
    {
        CC_BOOL_CPP(SpriteHost, sprite);

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

    bool Sprite::drawImageF(float x, float y, const gImage& image)
    {
        CC_BOOL_CPP(SpriteHost, sprite);

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

    bool Sprite::drawIcon(int x, int y, const gIcon& icon)
    {
        CC_BOOL_CPP(SpriteHost, sprite);

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

    bool Sprite::drawIconF(float x, float y, const gIcon& icon)
    {
        CC_BOOL_CPP(SpriteHost, sprite);

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



    void Sprite::render()
    {
        CCI_VOID_CPP(SpriteHost, sprite, Render());
    }



    SpriteHost* SpriteHelper::get(const Sprite* sprite)
    {
        SpriteHost* spriteHost = static_cast<SpriteHost*>(sprite->sprite);

        return spriteHost;
    }
}

#endif // __cplusplus
