//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
        CanvasHost* host = new CanvasHost(width, height);

        canvas = static_cast<CLRCanvasHost>(host);
    }

    Canvas::Canvas()
    {
        CanvasHost* host = new CanvasHost();

        canvas = static_cast<CLRCanvasHost>(host);
    }

    Canvas::~Canvas()
    {
        CanvasHost* host = static_cast<CanvasHost*>(canvas);

        delete host;
    }



    bool Canvas::isInitialized()
    {
        CanvasHost* host = static_cast<CanvasHost*>(canvas);

        if (host == nullptr)
        {
            return false;
        }

        return !host->isNull();
    }



    gColor Canvas::getBorderColor()
    {
        CCI_CANVAS_GET_COLOR_CPP(canvas, BorderColor);
    }

    void Canvas::setBorderColor(gColor color)
    {
        CCI_CANVAS_SET_COLOR_CPP(canvas, BorderColor, color);
    }

    gColor Canvas::getFillColor()
    {
        CCI_CANVAS_GET_COLOR_CPP(canvas, FillColor);
    }

    void Canvas::setFillColor(gColor color)
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



    bool Canvas::drawBorderCircle(int x, int y, int radius)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawBorderCircle(x, y, radius));
    }

    bool Canvas::drawFillCircle(int x, int y, int radius)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawFillCircle(x, y, radius));
    }



    bool Canvas::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawBorderEllipse(x, y, width, height));
    }

    bool Canvas::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_CANVAS_BOOL_CPP(canvas, DrawFillEllipse(x, y, width, height));
    }



    void Canvas::render()
    {
        CCI_CANVAS_VOID_CPP(canvas, Render());
    }
}

#endif // __cplusplus
