//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  WindowHandler.clr.cpp
//

#include "WindowHandler.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    WindowHandler::WindowHandler() {}

    WindowHandler::~WindowHandler() {}

    IntPtr WindowHandler::alloc()
    {
        Window^ window = gcnew Window();

        GCHandle managedHandle = GCHandle::Alloc(window);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }

    bool WindowHandler::free(IntPtr handle)
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

    Window^ WindowHandler::invoke(IntPtr handle)
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

    bool WindowHandler::isNull(IntPtr handle)
    {
        IntPtr nativeHandle = handle;

        return nativeHandle == IntPtr::Zero;
    }
}
}
}

#endif // __cplusplus_cli
