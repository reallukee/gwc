//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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



    int Window::getRefreshRate()
    {
        return GWC::Window::RefreshRate;
    }

    void Window::setRefreshRate(int value)
    {
        GWC::Window::RefreshRate = value;
    }

    int Window::getDutyCycle()
    {
        return GWC::Window::DutyCycle;
    }

    void Window::setDutyCycle(int value)
    {
        GWC::Window::DutyCycle = value;
    }

    double Window::getFrameTime()
    {
        return GWC::Window::FrameTime;
    }

    double Window::getUtilFrameTime()
    {
        return GWC::Window::UtilFrameTime;
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
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Drawing::Color^ managedBorderColor = WindowHandler::Invoke(managedHandle)->BorderColor;

        Color nativeColor = Color(
            (int)managedBorderColor->A,
            (int)managedBorderColor->R,
            (int)managedBorderColor->G,
            (int)managedBorderColor->B
        );

        return nativeColor;
    }

    void Window::setBorderColor(Color color)
    {
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Color nativeColor = color;

        Drawing::Color managedColor = Drawing::Color::FromArgb(
            nativeColor.getAlpha(),
            nativeColor.getRed(),
            nativeColor.getBlue(),
            nativeColor.getGreen()
        );

        WindowHandler::Invoke(managedHandle)->BorderColor = managedColor;
    }

    Color Window::getFillColor()
    {
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Drawing::Color^ managedFillColor = WindowHandler::Invoke(managedHandle)->FillColor;

        Color nativeColor = Color(
            (int)managedFillColor->A,
            (int)managedFillColor->R,
            (int)managedFillColor->G,
            (int)managedFillColor->B
        );

        return nativeColor;
    }

    void Window::setFillColor(Color color)
    {
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Color nativeColor = color;

        Drawing::Color managedColor = Drawing::Color::FromArgb(
            nativeColor.getAlpha(),
            nativeColor.getRed(),
            nativeColor.getBlue(),
            nativeColor.getGreen()
        );

        WindowHandler::Invoke(managedHandle)->FillColor = managedColor;
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
