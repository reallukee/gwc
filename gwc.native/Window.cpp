//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Window.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Window.hpp"
#include "window_macros.hpp"

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
        CCI_WINDOW_BOOL_CPP(window, Open());
    }

    bool Window::shutdown()
    {
        CCI_WINDOW_BOOL_CPP(window, Shutdown());
    }



    bool Window::isOpen()
    {
        CCI_WINDOW_BOOL_CPP(window, IsOpen);
    }

    bool Window::isShutdown()
    {
        CCI_WINDOW_BOOL_CPP(window, IsShutdown);
    }



    gColor Window::getBorderColor()
    {
    CCI_WINDOW_GET_COLOR_CPP(window, BorderColor);
    }

    void Window::setBorderColor(gColor color)
    {
        CCI_WINDOW_SET_COLOR_CPP(window, BorderColor, color);
    }

    gColor Window::getFillColor()
    {
        CCI_WINDOW_GET_COLOR_CPP(window, FillColor);
    }

    void Window::setFillColor(gColor color)
    {
        CCI_WINDOW_SET_COLOR_CPP(window, FillColor, color);
    }



    void Window::wait(int milliseconds)
    {
        CCI_WINDOW_VOID_CPP(window, Wait(milliseconds));
    }



    int Window::getWindowWidth()
    {
        CCI_WINDOW_INT_CPP(window, WindowWidth);
    }

    int Window::getWindowHeight()
    {
        CCI_WINDOW_INT_CPP(window, WindowHeight);
    }

    int Window::getRenderWidth()
    {
        CCI_WINDOW_INT_CPP(window, RenderWidth);
    }

    int Window::getRenderHeight()
    {
        CCI_WINDOW_INT_CPP(window, RenderHeight);
    }



    bool Window::isKeyDownAvailable()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyDownAvailable);
    }

    void Window::flushKeyDown()
    {
        CCI_WINDOW_VOID_CPP(window, FlushKeyDown());
    }

    bool Window::consumeKeyDown(gKeys& modifiers, gKeys& key)
    {
        CC_WINDOW_BOOL_CPP(window);

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
        CCI_WINDOW_BOOL_CPP(window, DiscardKeyDown());
    }

    void Window::waitKeyDown()
    {
        CCI_WINDOW_VOID_CPP(window, WaitKeyDown());
    }

    bool Window::isKeyDownLost()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyDownLost);
    }

    bool Window::isKeyDownBufferFull()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyDownBufferFull);
    }



    bool Window::isKeyUpAvailable()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyUpAvailable);
    }

    void Window::flushKeyUp()
    {
        CCI_WINDOW_VOID_CPP(window, FlushKeyUp());
    }

    bool Window::consumeKeyUp(gKeys& modifiers, gKeys& key)
    {
        CC_WINDOW_BOOL_CPP(window);

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
        CCI_WINDOW_BOOL_CPP(window, DiscardKeyUp());
    }

    void Window::waitKeyUp()
    {
        CCI_WINDOW_VOID_CPP(window, WaitKeyUp());
    }

    bool Window::isKeyUpLost()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyUpLost);
    }

    bool Window::isKeyUpBufferFull()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyUpBufferFull);
    }



    bool Window::isMouseDownAvailable()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseDownAvailable);
    }

    void Window::flushMouseDown()
    {
        CCI_WINDOW_VOID_CPP(window, FlushMouseDown());
    }

    bool Window::consumeMouseDown(gPoint& location, gMouseButtons& button)
    {
        CC_WINDOW_BOOL_CPP(window);

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
        CCI_WINDOW_BOOL_CPP(window, DiscardMouseDown());
    }

    void Window::waitMouseDown()
    {
        CCI_WINDOW_VOID_CPP(window, WaitMouseDown());
    }

    bool Window::isMouseDownLost()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseDownLost);
    }

    bool Window::isMouseDownBufferFull()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseDownBufferFull);
    }



    bool Window::isMouseUpAvailable()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseUpAvailable);
    }

    void Window::flushMouseUp()
    {
        CCI_WINDOW_VOID_CPP(window, FlushMouseUp());
    }

    bool Window::consumeMouseUp(gPoint& location, gMouseButtons& button)
    {
        CC_WINDOW_BOOL_CPP(window);

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
        CCI_WINDOW_BOOL_CPP(window, DiscardMouseUp());
    }

    void Window::waitMouseUp()
    {
        CCI_WINDOW_VOID_CPP(window, WaitMouseUp());
    }

    bool Window::isMouseUpLost()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseUpLost);
    }

    bool Window::isMouseUpBufferFull()
    {
        CCI_WINDOW_BOOL_CPP(window, IsMouseUpBufferFull);
    }



    int Window::getCanvasWidth()
    {
        CCI_WINDOW_INT_CPP(window, CanvasWidth);
    }

    int Window::getCanvasHeight()
    {
        CCI_WINDOW_INT_CPP(window, CanvasHeight);
    }



    bool Window::drawBorderSquare(int x, int y, int side)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawBorderSquare(x, y, side));
    }

    bool Window::drawFillSquare(int x, int y, int side)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawFillSquare(x, y, side));
    }



    bool Window::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawBorderRectangle(x, y, width, height));
    }

    bool Window::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawFillRectangle(x, y, width, height));
    }



    bool Window::drawBorderCircle(int x, int y, int radius)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawBorderCircle(x, y, radius));
    }

    bool Window::drawFillCircle(int x, int y, int radius)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawFillCircle(x, y, radius));
    }



    bool Window::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawBorderEllipse(x, y, width, height));
    }

    bool Window::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_WINDOW_BOOL_CPP(window, DrawFillEllipse(x, y, width, height));
    }
}

#endif // __cplusplus
