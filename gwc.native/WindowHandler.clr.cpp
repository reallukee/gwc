//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WindowHandler.clr.cpp
//  Licenza MIT
//

// /!\ Deprecato
//     Guarda WindowHost.

#include "WindowHandler.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    IntPtr WindowHandler::Alloc(int width, int height)
    {
        Window^ window = gcnew Window(width, height);

        GCHandle managedHandle = GCHandle::Alloc(window);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }

    IntPtr WindowHandler::Alloc()
    {
        Window^ window = gcnew Window();

        GCHandle managedHandle = GCHandle::Alloc(window);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }



    bool WindowHandler::Free(IntPtr handle)
    {
        if (handle == IntPtr::Zero)
        {
            return false;
        }

        IntPtr nativeHandle = handle;

        GCHandle managedHandle = GCHandle::FromIntPtr(nativeHandle);

        managedHandle.Free();

        return true;
    }



    bool WindowHandler::IsNull(IntPtr handle)
    {
        IntPtr nativeHandle = handle;

        return nativeHandle == IntPtr::Zero;
    }



    Window^ WindowHandler::Invoke(IntPtr handle)
    {
        if (handle == IntPtr::Zero)
        {
            return nullptr;
        }

        IntPtr nativeHandle = IntPtr(handle);

        GCHandle managedHandle = GCHandle::FromIntPtr(nativeHandle);

        Window^ window = safe_cast<Window^>(managedHandle.Target);

        return window;
    }



    WindowHandler::WindowHandler() { }

    WindowHandler::~WindowHandler() { }
}
}
}

#endif // __cplusplus_cli
