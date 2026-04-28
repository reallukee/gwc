//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_HPP
#define GWC_CANVAS_HPP

#ifdef  __cplusplus

#include "header.hpp"

#include "types.hpp"

namespace gwc
{
    class GWC_CPP_API Canvas sealed
    {

    public:

        Canvas (int width, int height);
        Canvas ();
        ~Canvas();

        bool isInitialized();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);

        gRectangle bounds();
        gSize      size();
        gPoint     location();

        int getWidth ();
        int getHeight();

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

        bool drawBorderCircle(int x, int y, int radius);
        bool drawFillCircle  (int x, int y, int radius);

        bool drawBorderEllipse(int x, int y, int width, int height);
        bool drawFillEllipse  (int x, int y, int width, int height);

        void render();

    private:

        CLRCanvasHost canvas;

    };
}

#endif //  __cplusplus

#endif // !GWC_CANVAS_HPP
