//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  Window.cpp
//

#include "Window.hpp"
#include "window_macros.hpp"

#include "gwc.clr.hpp"

#ifdef __cplusplus

namespace gwc
{
    Window::Window(int width, int height)
    {
        IntPtr managedHandle = WindowHandler::Alloc(width, height);

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
