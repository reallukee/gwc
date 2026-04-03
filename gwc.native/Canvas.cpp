//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.cpp
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

        CLRCanvas nativeHandle = reinterpret_cast<CLRCanvas>(managedHandle.ToPointer());

        canvas = nativeHandle;
    }

    Canvas::Canvas()
    {
        IntPtr managedHandle = CanvasHandler::Alloc();

        CLRCanvas nativeHandle = reinterpret_cast<CLRCanvas>(managedHandle.ToPointer());

        canvas = nativeHandle;
    }

    Canvas::~Canvas()
    {
        CLRCanvas nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
        {
            return;
        }

        CanvasHandler::Free(managedHandle);
    }



    bool Canvas::isInitialized()
    {
        CLRCanvas nativeHandle = canvas;

        return nativeHandle != nullptr;
    }



    Color Canvas::getBorderColor()
    {
        CCI_CANVAS_GET_COLOR_CPP(canvas, BorderColor);
    }

    void Canvas::setBorderColor(Color color)
    {
        CCI_CANVAS_SET_COLOR_CPP(canvas, BorderColor, color);
    }

    Color Canvas::getFillColor()
    {
        CCI_CANVAS_GET_COLOR_CPP(canvas, FillColor);
    }

    void Canvas::setFillColor(Color color)
    {
        CCI_CANVAS_SET_COLOR_CPP(canvas, FillColor, color);
    }



    int Canvas::getWidth()
    {
        CCI_CANVAS_INT_CPP(canvas, Width);
    }

    int Canvas::getHeight()
    {
        CCI_CANVAS_INT_CPP(canvas, Height);
    }



    bool Canvas::drawBorderSquare(int x, int y, int side)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawBorderSquare(x, y, side));
    }

    bool Canvas::drawFillSquare(int x, int y, int side)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawFillSquare(x, y, side));
    }



    bool Canvas::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawBorderRectangle(x, y, width, height));
    }

    bool Canvas::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawFillRectangle(x, y, width, height));
    }
}

#endif // __cplusplus
