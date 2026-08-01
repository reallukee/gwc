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
 * Nome file : Canvas.cpp
 *
 * Titolo    : CANVAS
 * Sommario  : Canvas
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#include "gwc.clr.hpp"

#include "Canvas.hpp"
#include "CanvasHelper.hpp"
#include "macros.hpp"

#include "ImageHelper.hpp"
#include "IconHelper.hpp"

#include "Sprite.hpp"
#include "SpriteHelper.hpp"

#ifdef __cplusplus

namespace gwc
{
    Canvas::Canvas(int width, int height)
    {
        CanvasHost* host = new CanvasHost(width, height);

        canvas = static_cast<CLRCanvasHost>(host);
    }

    Canvas::Canvas()
    {
        CanvasHost* host = new CanvasHost();

        canvas = static_cast<CLRCanvasHost>(host);
    }

    Canvas::~Canvas()
    {
        CanvasHost* host = static_cast<CanvasHost*>(canvas);

        delete host;
    }



    bool Canvas::isInitialized()
    {
        CanvasHost* host = static_cast<CanvasHost*>(canvas);

        if (host == nullptr)
        {
            return false;
        }

        return !host->isNull();
    }



    gColor Canvas::getBorderColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, canvas, BorderColor);
    }

    void Canvas::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, canvas, BorderColor, color);
    }

    gColor Canvas::getFillColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, canvas, FillColor);
    }

    void Canvas::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, canvas, FillColor, color);
    }

    gColor Canvas::getBackColor()
    {
        CCI_GET_COLOR_CPP(CanvasHost, canvas, BackColor);
    }

    void Canvas::setBackColor(gColor color)
    {
        CCI_SET_COLOR_CPP(CanvasHost, canvas, BackColor, color);
    }



    gRectangle Canvas::bounds()
    {
        CCI_GET_RECTANGLE_CPP(SpriteHost, canvas, Bounds);
    }

    gSize Canvas::size()
    {
        CCI_GET_SIZE_CPP(SpriteHost, canvas, Size);
    }

    gPoint Canvas::location()
    {
        CCI_GET_POINT_CPP(SpriteHost, canvas, Location);
    }



    int Canvas::getWidth()
    {
        CCI_INT_CPP(SpriteHost, canvas, Width);
    }

    int Canvas::getHeight()
    {
        CCI_INT_CPP(SpriteHost, canvas, Height);
    }



    bool Canvas::clear()
    {
        CCI_BOOL_CPP(CanvasHost, canvas, Clear());
    }

    bool Canvas::clearArea(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, ClearArea(x, y, width, height));
    }

    bool Canvas::clearF()
    {
        CCI_BOOL_CPP(CanvasHost, canvas, ClearF());
    }

    bool Canvas::clearAreaF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, ClearAreaF(x, y, width, height));
    }



    bool Canvas::drawCanvas(int x, int y, const Canvas* canvas)
    {
        CanvasHost* canvasHost = CanvasHelper::get(canvas);

        GWC::Canvas^ managedCanvas = canvasHost->invoke();

        CCI_BOOL_CPP(CanvasHost, this->canvas, DrawCanvas(x, y, managedCanvas));
    }

    bool Canvas::drawCanvasF(float x, float y, const Canvas* canvas)
    {
        CanvasHost* canvasHost = CanvasHelper::get(canvas);

        GWC::Canvas^ managedCanvas = canvasHost->invoke();

        CCI_BOOL_CPP(CanvasHost, this->canvas, DrawCanvasF(x, y, managedCanvas));
    }



    bool Canvas::drawSprite(int x, int y, const Sprite* sprite)
    {
        SpriteHost* spriteHost = SpriteHelper::get(sprite);

        GWC::Sprite^ managedSprite = spriteHost->invoke();

        CCI_BOOL_CPP(CanvasHost, canvas, DrawSprite(x, y, managedSprite));
    }

    bool Canvas::drawSpriteF(float x, float y, const Sprite* sprite)
    {
        SpriteHost* spriteHost = SpriteHelper::get(sprite);

        GWC::Sprite^ managedSprite = spriteHost->invoke();

        CCI_BOOL_CPP(CanvasHost, canvas, DrawSpriteF(x, y, managedSprite));
    }



    bool Canvas::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderSquare(x, y, side));
    }

    bool Canvas::drawBorderSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderSquareF(x, y, side));
    }

    bool Canvas::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillSquare(x, y, side));
    }

    bool Canvas::drawFillSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillSquareF(x, y, side));
    }



    bool Canvas::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderRectangle(x, y, width, height));
    }

    bool Canvas::drawBorderRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderRectangleF(x, y, width, height));
    }

    bool Canvas::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillRectangle(x, y, width, height));
    }

    bool Canvas::drawFillRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillRectangleF(x, y, width, height));
    }



    bool Canvas::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderCircle(x, y, radius));
    }

    bool Canvas::drawBorderCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderCircleF(x, y, radius));
    }

    bool Canvas::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillCircle(x, y, radius));
    }

    bool Canvas::drawFillCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillCircleF(x, y, radius));
    }



    bool Canvas::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderEllipse(x, y, width, height));
    }

    bool Canvas::drawBorderEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawBorderEllipseF(x, y, width, height));
    }

    bool Canvas::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillEllipse(x, y, width, height));
    }

    bool Canvas::drawFillEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(CanvasHost, canvas, DrawFillEllipseF(x, y, width, height));
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



    bool Canvas::drawImage(int x, int y, const gImage& image)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

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

    bool Canvas::drawImageF(float x, float y, const gImage& image)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

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

    bool Canvas::drawIcon(int x, int y, const gIcon& icon)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

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

    bool Canvas::drawIconF(float x, float y, const gIcon& icon)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

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



    void Canvas::render()
    {
        CCI_VOID_CPP(SpriteHost, canvas, Render());
    }



    CanvasHost* CanvasHelper::get(const Canvas* canvas)
    {
        CanvasHost* canvasHost = static_cast<CanvasHost*>(canvas->canvas);

        return canvasHost;
    }
}

#endif // __cplusplus
