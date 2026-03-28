//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Canvas.hpp"
#include "canvas_macros.hpp"

#ifdef __cplusplus

namespace gwc
{
    Canvas::Canvas(int width, int height)
    {
        IntPtr managedHandle = CanvasHandler::Alloc(width, height);

        void* nativeHandle = reinterpret_cast<void*>(managedHandle.ToPointer());

        canvas = nativeHandle;
    }

    Canvas::Canvas()
    {
        IntPtr managedHandle = CanvasHandler::Alloc();

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



    Color Canvas::getBorderColor()
    {
        INVOKE_CANVAS_GET_COLOR_CPP(canvas, BorderColor);
    }

    void Canvas::setBorderColor(Color color)
    {
        INVOKE_CANVAS_SET_COLOR_CPP(canvas, BorderColor, color);
    }

    Color Canvas::getFillColor()
    {
        INVOKE_CANVAS_GET_COLOR_CPP(canvas, FillColor);
    }

    void Canvas::setFillColor(Color color)
    {
        INVOKE_CANVAS_SET_COLOR_CPP(canvas, FillColor, color);
    }



    bool Canvas::drawBorderSquare(int x, int y, int side)
    {
        INVOKE_CANVAS_BOOL_CPP(canvas, DrawBorderSquare(x, y, side));
    }

    bool Canvas::drawFillSquare(int x, int y, int side)
    {
        INVOKE_CANVAS_BOOL_CPP(canvas, DrawFillSquare(x, y, side));
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
