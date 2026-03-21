//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  Canvas.cpp
//

#include "Canvas.hpp"
#include "canvas_macros.hpp"

#include "gwc.clr.hpp"

#ifdef __cplusplus

namespace gwc
{
    Canvas::Canvas(int width, int height)
    {
        IntPtr managedHandle = CanvasHandler::Alloc(width, height);

        void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

        canvas = nativeHandle;
    }

    Canvas::~Canvas()
    {
        void* nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
        {
            return;
        }

        CanvasHandler::Free(managedHandle);
    }

    bool Canvas::isInitialized()
    {
        void* nativeHandle = canvas;

        return nativeHandle != nullptr;
    }

    bool Canvas::drawBorderRectangle(int x, int y, int width, int height)
    {
        INVOKE_CANVAS_BOOL_CPP(canvas, DrawBorderRectangle(x, y, width, height));
    }

    bool Canvas::drawFillRectangle(int x, int y, int width, int height)
    {
        INVOKE_CANVAS_BOOL_CPP(canvas, DrawFillRectangle(x, y, width, height));
    }
}

#endif // __cplusplus
