/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : Canvas.hpp
 *
 * Titolo    : CANVAS
 * Sommario  : Canvas
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

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
        gColor getBackColor  ();
        void   setBackColor  (gColor color);

        gRectangle bounds  ();
        gSize      size    ();
        gPoint     location();

        int getWidth ();
        int getHeight();

        bool clear     ();
        bool clearArea (int x, int y, int width, int height);
        bool clearF    ();
        bool clearAreaF(float x, float y, float width, float height);

        bool drawCanvas (int x, int y, const Canvas* canvas);
        bool drawCanvasF(float x, float y, const Canvas* canvas);

        bool drawSprite (int x, int y, const Sprite* sprite);
        bool drawSpriteF(float x, float y, const Sprite* sprite);

        bool drawBorderSquare (int x, int y, int side);
        bool drawBorderSquareF(float x, float y, float side);
        bool drawFillSquare   (int x, int y, int side);
        bool drawFillSquareF  (float x, float y, float side);

        bool drawBorderRectangle (int x, int y, int width, int height);
        bool drawBorderRectangleF(float x, float y, float width, float height);
        bool drawFillRectangle   (int x, int y, int width, int height);
        bool drawFillRectangleF  (float x, float y, float width, float height);

        bool drawBorderCircle (int x, int y, int radius);
        bool drawBorderCircleF(float x, float y, float radius);
        bool drawFillCircle   (int x, int y, int radius);
        bool drawFillCircleF  (float x, float y, float radius);

        bool drawBorderEllipse (int x, int y, int width, int height);
        bool drawBorderEllipseF(float x, float y, float width, float height);
        bool drawFillEllipse   (int x, int y, int width, int height);
        bool drawFillEllipseF  (float x, float y, float width, float height);

        bool drawImage (int x, int y, const gImage& image);
        bool drawImageF(float x, float y, const gImage& image);
        bool drawIcon  (int x, int y, const gIcon& icon);
        bool drawIconF (float x, float y, const gIcon& icon);

        void render();

    private:

        CLRCanvasHost canvas;

    };
}

#endif //  __cplusplus

#endif // !GWC_CANVAS_HPP
