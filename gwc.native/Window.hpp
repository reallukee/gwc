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
 * Nome file : Window.hpp
 *
 * Titolo    : WINDOW
 * Sommario  : Window
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_WINDOW_HPP
#define GWC_WINDOW_HPP

#ifdef __cplusplus

#include "types.hpp"

#include "Sprite.hpp"
#include "Canvas.hpp"

namespace gwc
{
    class GWC_CPP_API Window sealed
    {

    public:

        Window (int width, int height);
        Window ();
        ~Window();

        bool isInitialized();

        bool open ();
        bool close();

        bool isOpen ();
        bool isClose();

        bool suspend();
        bool resume ();

        bool isSuspend();
        bool isResume ();

        void wait(int milliseconds);

        void skip(int frames);

        bool show();
        bool hide();

        int getWindowWidth ();
        int getWindowHeight();
        int getRenderWidth ();
        int getRenderHeight();

        bool isKeyDownAvailable ();
        bool isKeyUpAvailable   ();
        void flushKeyDown       ();
        void flushKeyUp         ();
        bool consumeKeyDown     (gKeys& modifiers, gKeys& key);
        bool consumeKeyUp       (gKeys& modifiers, gKeys& key);
        bool discardKeyDown     ();
        bool discardKeyUp       ();
        bool isKeyDownInBuffer  (gKeys modifiers, gKeys key);
        bool isKeyUpInBuffer    (gKeys modifiers, gKeys key);
        bool isKeyDownLost      ();
        bool isKeyUpLost        ();
        int  keyDownBufferLength();
        int  keyUpBufferLength  ();

        bool isMouseDownAvailable ();
        bool isMouseUpAvailable   ();
        void flushMouseDown       ();
        void flushMouseUp         ();
        bool consumeMouseDown     (gPoint& location, gMouseButtons& button);
        bool consumeMouseUp       (gPoint& location, gMouseButtons& button);
        bool discardMouseDown     ();
        bool discardMouseUp       ();
        bool isMouseDownInBuffer  (gPoint& location, gMouseButtons button);
        bool isMouseUpInBuffer    (gPoint& location, gMouseButtons button);
        bool isMouseDownLost      ();
        bool isMouseUpLost        ();
        int  mouseDownBufferLength();
        int  mouseUpBufferLength  ();

        int getCanvasWidth ();
        int getCanvasHeight();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);
        gColor getBackColor  ();
        void   setBackColor  (gColor color);

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

    private:

        CLRWindowHost window;

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
