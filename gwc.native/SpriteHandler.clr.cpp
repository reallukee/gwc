//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHandler.clr.cpp
//  Licenza MIT
//

// /!\ Deprecato
//     Guarda SpriteHost.

#include "SpriteHandler.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    IntPtr SpriteHandler::Alloc(int width, int height)
    {
        Sprite^ sprite = gcnew Sprite(width, height);

        GCHandle managedHandle = GCHandle::Alloc(sprite);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }

    IntPtr SpriteHandler::Alloc()
    {
        Sprite^ sprite = gcnew Sprite();

        GCHandle managedHandle = GCHandle::Alloc(sprite);

        IntPtr nativeHandle = GCHandle::ToIntPtr(managedHandle);

        return nativeHandle;
    }



    bool SpriteHandler::Free(IntPtr handle)
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



    bool SpriteHandler::IsNull(IntPtr handle)
    {
        IntPtr nativeHandle = handle;

        return nativeHandle == IntPtr::Zero;
    }



    Sprite^ SpriteHandler::Invoke(IntPtr handle)
    {
        if (handle == IntPtr::Zero)
        {
            return nullptr;
        }

        IntPtr nativeHandle = IntPtr(handle);

        GCHandle managedHandle = GCHandle::FromIntPtr(nativeHandle);

        Sprite^ sprite = safe_cast<Sprite^>(managedHandle.Target);

        return sprite;
    }



    SpriteHandler::SpriteHandler() {}

    SpriteHandler::~SpriteHandler() {}
}
}
}

#endif // __cplusplus_cli
