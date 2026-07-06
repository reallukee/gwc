//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.cpp
//  Licenza MIT
//

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



    bool Canvas::clear(gColor color)
    {
        Drawing::Color managedColor = Drawing::Color::FromArgb(
            color.getAlpha(),
            color.getRed  (),
            color.getGreen(),
            color.getBlue ()
        );

        CCI_BOOL_CPP(CanvasHost, canvas, Clear(managedColor));
    }



    bool Canvas::drawCanvas(int x, int y, const Canvas* canvas)
    {
        CanvasHost* canvasHost = CanvasHelper::get(canvas);

        GWC::Canvas^ managedCanvas = canvasHost->invoke();

        CCI_BOOL_CPP(CanvasHost, this->canvas, DrawCanvas(x, y, managedCanvas));
    }

    bool Canvas::drawSprite(int x, int y, const Sprite* sprite)
    {
        SpriteHost* spriteHost = SpriteHelper::get(sprite);

        GWC::Sprite^ managedSprite = spriteHost->invoke();

        CCI_BOOL_CPP(CanvasHost, this->canvas, DrawSprite(x, y, managedSprite));
    }



    bool Canvas::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderSquare(x, y, side));
    }

    bool Canvas::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillSquare(x, y, side));
    }



    bool Canvas::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderRectangle(x, y, width, height));
    }

    bool Canvas::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillRectangle(x, y, width, height));
    }



    bool Canvas::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderCircle(x, y, radius));
    }

    bool Canvas::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillCircle(x, y, radius));
    }



    bool Canvas::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderEllipse(x, y, width, height));
    }

    bool Canvas::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillEllipse(x, y, width, height));
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

    bool Canvas::drawImage(int x, int y, const gImage& image)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

        if (!image.isLoaded())
        {
            return false;
        }

        Bitmap* nativeImage = ImageHelper::get(image);

        if (nativeImage == nullptr)
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

    bool Canvas::drawIcon(int x, int y, const gIcon& icon)
    {
        CC_BOOL_CPP(CanvasHost, canvas);

        if (!icon.isLoaded())
        {
            return false;
        }

        HICON nativeIcon = IconHelper::get(icon);

        if (nativeIcon == nullptr)
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
