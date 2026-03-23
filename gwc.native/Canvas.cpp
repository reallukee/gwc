//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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
        void* nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Drawing::Color^ managedBorderColor = CanvasHandler::Invoke(managedHandle)->BorderColor;

        Color nativeColor = Color(
            (int)managedBorderColor->A,
            (int)managedBorderColor->R,
            (int)managedBorderColor->G,
            (int)managedBorderColor->B
        );

        return nativeColor;
    }

    void Canvas::setBorderColor(Color color)
    {
        void* nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
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

        CanvasHandler::Invoke(managedHandle)->BorderColor = managedColor;
    }

    Color Canvas::getFillColor()
    {
        void* nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
        {
            throw gcnew NullReferenceException("");
        }

        Drawing::Color^ managedFillColor = CanvasHandler::Invoke(managedHandle)->FillColor;

        Color nativeColor = Color(
            (int)managedFillColor->A,
            (int)managedFillColor->R,
            (int)managedFillColor->G,
            (int)managedFillColor->B
        );

        return nativeColor;
    }

    void Canvas::setFillColor(Color color)
    {
        void* nativeHandle = canvas;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (CanvasHandler::IsNull(managedHandle))
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

        CanvasHandler::Invoke(managedHandle)->FillColor = managedColor;
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
