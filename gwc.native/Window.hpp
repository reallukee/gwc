//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Window.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_HPP
#define GWC_WINDOW_HPP

#ifdef __cplusplus

#include "types.hpp"

#include "Canvas.hpp"
#include "Sprite.hpp"

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

    private:

        CLRWindowHost window;

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
