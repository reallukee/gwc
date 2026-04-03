//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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
        IntPtr managedHandle = WindowHandler::Alloc(width, height);

        CLRWindow nativeHandle = reinterpret_cast<CLRWindow>(managedHandle.ToPointer());

        window = nativeHandle;
    }

    Window::Window()
    {
        IntPtr managedHandle = WindowHandler::Alloc();

        CLRWindow nativeHandle = reinterpret_cast<CLRWindow>(managedHandle.ToPointer());

        window = nativeHandle;
    }

    Window::~Window()
    {
        CLRWindow nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            return;
        }

        WindowHandler::Free(managedHandle);
    }



    bool Window::isInitialized()
    {
        CLRWindow nativeHandle = window;

        return nativeHandle != nullptr;
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



    Color Window::getBorderColor()
    {
    CCI_WINDOW_GET_COLOR_CPP(window, BorderColor);
    }

    void Window::setBorderColor(Color color)
    {
        CCI_WINDOW_SET_COLOR_CPP(window, BorderColor, color);
    }

    Color Window::getFillColor()
    {
        CCI_WINDOW_GET_COLOR_CPP(window, FillColor);
    }

    void Window::setFillColor(Color color)
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

    void Window::resetKeyDown()
    {
        CCI_WINDOW_VOID_CPP(window, ResetKeyDown());
    }

    bool Window::consumeKeyDown(int& key)
    {
        CCI_WINDOW_BOOL_CPP(window, ConsumeKeyDown(key));
    }

    bool Window::discardKeyDown()
    {
        CCI_WINDOW_BOOL_CPP(window, DiscardKeyDown());
    }

    void Window::waitKeyDown()
    {
        CCI_WINDOW_VOID_CPP(window, WaitKeyDown());
    }



    bool Window::isKeyUpAvailable()
    {
        CCI_WINDOW_BOOL_CPP(window, IsKeyUpAvailable);
    }

    void Window::resetKeyUp()
    {
        CCI_WINDOW_VOID_CPP(window, ResetKeyUp());
    }

    bool Window::consumeKeyUp(int& key)
    {
        CCI_WINDOW_BOOL_CPP(window, ConsumeKeyUp(key));
    }

    bool Window::discardKeyUp()
    {
        CCI_WINDOW_BOOL_CPP(window, DiscardKeyUp());
    }

    void Window::waitKeyUp()
    {
        CCI_WINDOW_VOID_CPP(window, WaitKeyUp());
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
}

#endif // __cplusplus
