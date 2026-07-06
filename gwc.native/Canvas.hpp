//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
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

#include "types.hpp"

namespace gwc
{
    class Sprite;
    class CanvasHelper;

    class GWC_CPP_API Canvas sealed
    {

    public:

        friend class CanvasHelper;

        Canvas (int width, int height);
        Canvas ();
        ~Canvas();

        bool isInitialized();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);

        gRectangle bounds  ();
        gSize      size    ();
        gPoint     location();

        int getWidth ();
        int getHeight();

        bool clear(gColor color);

        bool drawCanvas(int x, int y, const Canvas* canvas);
        bool drawSprite(int x, int y, const Sprite* sprite);

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

        bool drawBorderCircle(int x, int y, int radius);
        bool drawFillCircle  (int x, int y, int radius);

        bool drawBorderEllipse(int x, int y, int width, int height);
        bool drawFillEllipse  (int x, int y, int width, int height);

        bool drawImage(int x, int y, const gImage& image);
        bool drawIcon (int x, int y, const gIcon& icon);

        void render();

    private:

        CLRCanvasHost canvas;

    };
}

#endif //  __cplusplus

#endif // !GWC_CANVAS_HPP
