//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  Window.cpp
//

#include "Window.hpp"
#include "window_macros.hpp"

#include "WindowHandler.clr.hpp"

#ifdef __cplusplus

using namespace Reallukee::GWC::Interop;

namespace gwc
{
    Window::Window()
    {
        IntPtr managedHandle = WindowHandler::alloc();

        void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

        window = nativeHandle;
    }

    Window::~Window()
    {
        void* nativeHandle = window;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (WindowHandler::isNull(managedHandle))
        {
            return;
        }

        WindowHandler::free(managedHandle);
    }

    bool Window::open()
    {
        INVOKE_CPP_BOOL(window, Open());
    }

    bool Window::shutdown()
    {
        INVOKE_CPP_BOOL(window, Shutdown());
    }

    bool Window::isOpen()
    {
        INVOKE_CPP_BOOL(window, IsOpen);
    }

    bool Window::isShutdown()
    {
        INVOKE_CPP_BOOL(window, IsShutdown);
    }

    bool Window::drawBorderRectangle(int x, int y, int width, int height)
    {
        INVOKE_CPP_BOOL(window, DrawBorderRectangle(x, y, width, height));
    }

    bool Window::drawFillRectangle(int x, int y, int width, int height)
    {
        INVOKE_CPP_BOOL(window, DrawFillRectangle(x, y, width, height));
    }
}

#endif // __cplusplus
