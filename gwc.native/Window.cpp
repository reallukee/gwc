//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
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

        void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

        window = nativeHandle;
    }

    Window::Window()
    {
        IntPtr managedHandle = WindowHandler::Alloc();

        void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

        window = nativeHandle;
    }

    Window::~Window()
    {
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            return;
        }

        WindowHandler::Free(managedHandle);
    }



    bool Window::isInitialized()
    {
        void* nativeHandle = window;

        return nativeHandle != nullptr;
    }



    bool Window::open()
    {
        INVOKE_WINDOW_BOOL_CPP(window, Open());
    }

    bool Window::shutdown()
    {
        INVOKE_WINDOW_BOOL_CPP(window, Shutdown());
    }



    bool Window::isOpen()
    {
        INVOKE_WINDOW_BOOL_CPP(window, IsOpen);
    }

    bool Window::isShutdown()
    {
        INVOKE_WINDOW_BOOL_CPP(window, IsShutdown);
    }



    Color Window::getBorderColor()
    {
        INVOKE_WINDOW_GET_COLOR_CPP(window, BorderColor);
    }

    void Window::setBorderColor(Color color)
    {
        INVOKE_WINDOW_SET_COLOR_CPP(window, BorderColor, color);
    }

    Color Window::getFillColor()
    {
        INVOKE_WINDOW_GET_COLOR_CPP(window, FillColor);
    }

    void Window::setFillColor(Color color)
    {
        INVOKE_WINDOW_SET_COLOR_CPP(window, FillColor, color);
    }



    bool Window::drawBorderSquare(int x, int y, int side)
    {
        INVOKE_WINDOW_BOOL_CPP(window, DrawBorderSquare(x, y, side));
    }

    bool Window::drawFillSquare(int x, int y, int side)
    {
        INVOKE_WINDOW_BOOL_CPP(window, DrawFillSquare(x, y, side));
    }

    bool Window::drawBorderRectangle(int x, int y, int width, int height)
    {
        INVOKE_WINDOW_BOOL_CPP(window, DrawBorderRectangle(x, y, width, height));
    }

    bool Window::drawFillRectangle(int x, int y, int width, int height)
    {
        INVOKE_WINDOW_BOOL_CPP(window, DrawFillRectangle(x, y, width, height));
    }
}

#endif // __cplusplus
