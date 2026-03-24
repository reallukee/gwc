//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CanvasHandler.clr.cpp
//  Licenza MIT
//

#include "CanvasHandler.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    IntPtr CanvasHandler::Alloc(int width, int height)
    {
        Canvas^ canvas = gcnew Canvas(width, height);

        GCHandle managedHandle = GCHandle::Alloc(canvas);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }

    IntPtr CanvasHandler::Alloc()
    {
        Canvas^ canvas = gcnew Canvas();

        GCHandle managedHandle = GCHandle::Alloc(canvas);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }



    bool CanvasHandler::Free(IntPtr handle)
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



    bool CanvasHandler::IsNull(IntPtr handle)
    {
        IntPtr nativeHandle = handle;

        return nativeHandle == IntPtr::Zero;
    }



    Canvas^ CanvasHandler::Invoke(IntPtr handle)
    {
        if (handle == IntPtr::Zero)
        {
            return nullptr;
        }

        IntPtr nativeHandle = IntPtr(handle);

        GCHandle managedHandle = GCHandle::FromIntPtr(nativeHandle);

        Canvas^ canvas = safe_cast<Canvas^>(managedHandle.Target);

        return canvas;
    }



    CanvasHandler::CanvasHandler() {}

    CanvasHandler::~CanvasHandler() {}
}
}
}

#endif // __cplusplus_cli
