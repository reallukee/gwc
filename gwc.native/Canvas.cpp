//
// :.:.:.:.:.
// GWC.Native
// v0.4.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Canvas.hpp"
#include "macros.hpp"

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
        CCI_GET_COLOR_CPP(SpriteHost, canvas, BorderColor);
    }

    void Canvas::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, canvas, BorderColor, color);
    }

    gColor Canvas::getFillColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, canvas, FillColor);
    }

    void Canvas::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, canvas, FillColor, color);
    }



    gRectangle Canvas::bounds()
    {
        CCI_GET_RECTANGLE_CPP(SpriteHost, canvas, Bounds);
    }

    gSize Canvas::size()
    {
        CCI_GET_SIZE_CPP(SpriteHost, canvas, Size);
    }

    gPoint Canvas::location()
    {
        CCI_GET_POINT_CPP(SpriteHost, canvas, Location);
    }



    int Canvas::getWidth()
    {
        CCI_INT_CPP(SpriteHost, canvas, Width);
    }

    int Canvas::getHeight()
    {
        CCI_INT_CPP(SpriteHost, canvas, Height);
    }



    bool Canvas::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderSquare(x, y, side));
    }

    bool Canvas::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillSquare(x, y, side));
    }



    bool Canvas::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderRectangle(x, y, width, height));
    }

    bool Canvas::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillRectangle(x, y, width, height));
    }



    bool Canvas::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderCircle(x, y, radius));
    }

    bool Canvas::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillCircle(x, y, radius));
    }



    bool Canvas::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawBorderEllipse(x, y, width, height));
    }

    bool Canvas::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, canvas, DrawFillEllipse(x, y, width, height));
    }



    void Canvas::render()
    {
        CCI_VOID_CPP(SpriteHost, canvas, Render());
    }
}

#endif // __cplusplus
