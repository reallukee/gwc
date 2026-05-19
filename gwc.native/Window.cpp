//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Window.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Window.hpp"
#include "macros.hpp"

#include "ImageHelper.hpp"
#include "IconHelper.hpp"

#ifdef __cplusplus

namespace gwc
{
    Window::Window(int width, int height)
    {
        WindowHost* host = new WindowHost(width, height);

        window = static_cast<CLRWindowHost>(host);
    }

    Window::Window()
    {
        WindowHost* host = new WindowHost();

        window = static_cast<CLRWindowHost>(host);
    }

    Window::~Window()
    {
        WindowHost* host = static_cast<WindowHost*>(window);

        delete host;
    }



    bool Window::isInitialized()
    {
        WindowHost* host = static_cast<WindowHost*>(window);

        if (host == nullptr)
        {
            return false;
        }

        return !host->isNull();
    }



    bool Window::open()
    {
        CCI_BOOL_CPP(WindowHost, window, Open());
    }

    bool Window::close()
    {
        CCI_BOOL_CPP(WindowHost, window, Close());
    }



    bool Window::isOpen()
    {
        CCI_BOOL_CPP(WindowHost, window, IsOpen);
    }

    bool Window::isClose()
    {
        CCI_BOOL_CPP(WindowHost, window, IsClose);
    }



    bool Window::suspend()
    {
        CCI_BOOL_CPP(WindowHost, window, Suspend())
    }

    bool Window::resume()
    {
        CCI_BOOL_CPP(WindowHost, window, Resume())
    }



    bool Window::isSuspend()
    {
        CCI_BOOL_CPP(WindowHost, window, IsSuspend);
    }

    bool Window::isResume()
    {
        CCI_BOOL_CPP(WindowHost, window, IsResume);
    }



    void Window::wait(int milliseconds)
    {
        CCI_VOID_CPP(WindowHost, window, Wait(milliseconds));
    }

    void Window::skip(int frames)
    {
        CCI_VOID_CPP(WindowHost, window, Skip(frames));
    }



    bool Window::show()
    {
        CCI_BOOL_CPP(WindowHost, window, Show());
    }

    bool Window::hide()
    {
        CCI_BOOL_CPP(WindowHost, window, Hide());
    }



    int Window::getWindowWidth()
    {
        CCI_INT_CPP(WindowHost, window, WindowWidth);
    }

    int Window::getWindowHeight()
    {
        CCI_INT_CPP(WindowHost, window, WindowHeight);
    }

    int Window::getRenderWidth()
    {
        CCI_INT_CPP(WindowHost, window, RenderWidth);
    }

    int Window::getRenderHeight()
    {
        CCI_INT_CPP(WindowHost, window, RenderHeight);
    }



    bool Window::isKeyDownAvailable()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyDownAvailable);
    }

    void Window::flushKeyDown()
    {
        CCI_VOID_CPP(WindowHost, window, FlushKeyDown());
    }

    bool Window::consumeKeyDown(gKeys& modifiers, gKeys& key)
    {
        CC_BOOL_CPP(WindowHost, window);

        Windows::Forms::Keys managedModifiers;
        Windows::Forms::Keys managedKey;

        bool result = _host->invoke()->ConsumeKeyDown(
            managedModifiers, managedKey
        );

        int rawModifiers = static_cast<int>(managedModifiers);
        int rawKey       = static_cast<int>(managedKey);

        modifiers = static_cast<gKeys>(rawModifiers);
        key       = static_cast<gKeys>(rawKey);

        return result;
    }

    bool Window::discardKeyDown()
    {
        CCI_BOOL_CPP(WindowHost, window, DiscardKeyDown());
    }

    bool Window::isKeyDownLost()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyDownLost);
    }

    bool Window::isKeyDownBufferFull()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyDownBufferFull);
    }



    bool Window::isKeyUpAvailable()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyUpAvailable);
    }

    void Window::flushKeyUp()
    {
        CCI_VOID_CPP(WindowHost, window, FlushKeyUp());
    }

    bool Window::consumeKeyUp(gKeys& modifiers, gKeys& key)
    {
        CC_BOOL_CPP(WindowHost, window);

        Windows::Forms::Keys managedModifiers;
        Windows::Forms::Keys managedKey;

        bool result = _host->invoke()->ConsumeKeyUp(
            managedModifiers, managedKey
        );

        int rawModifiers = static_cast<int>(managedModifiers);
        int rawKey       = static_cast<int>(managedKey);

        modifiers = static_cast<gKeys>(rawModifiers);
        key       = static_cast<gKeys>(rawKey);

        return result;
    }

    bool Window::discardKeyUp()
    {
        CCI_BOOL_CPP(WindowHost, window, DiscardKeyUp());
    }

    bool Window::isKeyUpLost()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyUpLost);
    }

    bool Window::isKeyUpBufferFull()
    {
        CCI_BOOL_CPP(WindowHost, window, IsKeyUpBufferFull);
    }



    bool Window::isMouseDownAvailable()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseDownAvailable);
    }

    void Window::flushMouseDown()
    {
        CCI_VOID_CPP(WindowHost, window, FlushMouseDown());
    }

    bool Window::consumeMouseDown(gPoint& location, gMouseButtons& button)
    {
        CC_BOOL_CPP(WindowHost, window);

        Drawing::Point               managedLocation;
        Windows::Forms::MouseButtons managedButton;

        bool result = _host->invoke()->ConsumeMouseDown(
            managedLocation, managedButton
        );

        int rawButton = static_cast<int>(managedButton);

        location = gPoint(managedLocation.X, managedLocation.Y);
        button   = static_cast<gMouseButtons>(rawButton);

        return result;
    }

    bool Window::discardMouseDown()
    {
        CCI_BOOL_CPP(WindowHost, window, DiscardMouseDown());
    }

    bool Window::isMouseDownLost()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseDownLost);
    }

    bool Window::isMouseDownBufferFull()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseDownBufferFull);
    }



    bool Window::isMouseUpAvailable()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseUpAvailable);
    }

    void Window::flushMouseUp()
    {
        CCI_VOID_CPP(WindowHost, window, FlushMouseUp());
    }

    bool Window::consumeMouseUp(gPoint& location, gMouseButtons& button)
    {
        CC_BOOL_CPP(WindowHost, window);

        Drawing::Point               managedLocation;
        Windows::Forms::MouseButtons managedButton;

        bool result = _host->invoke()->ConsumeMouseUp(
            managedLocation, managedButton
        );

        int rawButton = static_cast<int>(managedButton);

        location = gPoint(managedLocation.X, managedLocation.Y);
        button   = static_cast<gMouseButtons>(rawButton);

        return result;
    }

    bool Window::discardMouseUp()
    {
        CCI_BOOL_CPP(WindowHost, window, DiscardMouseUp());
    }

    bool Window::isMouseUpLost()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseUpLost);
    }

    bool Window::isMouseUpBufferFull()
    {
        CCI_BOOL_CPP(WindowHost, window, IsMouseUpBufferFull);
    }



    int Window::getCanvasWidth()
    {
        CCI_INT_CPP(WindowHost, window, CanvasWidth);
    }

    int Window::getCanvasHeight()
    {
        CCI_INT_CPP(WindowHost, window, CanvasHeight);
    }



    gColor Window::getBorderColor()
    {
        CCI_GET_COLOR_CPP(WindowHost, window, BorderColor);
    }

    void Window::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(WindowHost, window, BorderColor, color);
    }

    gColor Window::getFillColor()
    {
        CCI_GET_COLOR_CPP(WindowHost, window, FillColor);
    }

    void Window::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(WindowHost, window, FillColor, color);
    }



    bool Window::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawBorderSquare(x, y, side));
    }

    bool Window::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawFillSquare(x, y, side));
    }



    bool Window::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawBorderRectangle(x, y, width, height));
    }

    bool Window::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawFillRectangle(x, y, width, height));
    }



    bool Window::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawBorderCircle(x, y, radius));
    }

    bool Window::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawFillCircle(x, y, radius));
    }



    bool Window::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawBorderEllipse(x, y, width, height));
    }

    bool Window::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(WindowHost, window, DrawFillEllipse(x, y, width, height));
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

    bool Window::drawImage(int x, int y, const gImage& image)
    {
        CC_BOOL_CPP(WindowHost, window);

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

    bool Window::drawIcon(int x, int y, const gIcon& icon)
    {
        CC_BOOL_CPP(WindowHost, window);

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
}

#endif // __cplusplus
