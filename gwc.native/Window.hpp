//
// :.:.:.:.:.
// GWC.Native
// v0.4.0
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

#include "header.hpp"

#include "types.hpp"

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
        void flushKeyDown       ();
        bool consumeKeyDown     (gKeys& modifiers, gKeys& key);
        bool discardKeyDown     ();
        bool isKeyDownLost      ();
        bool isKeyDownBufferFull();

        bool isKeyUpAvailable ();
        void flushKeyUp       ();
        bool consumeKeyUp     (gKeys& modifiers, gKeys& key);
        bool discardKeyUp     ();
        bool isKeyUpLost      ();
        bool isKeyUpBufferFull();

        bool isMouseDownAvailable ();
        void flushMouseDown       ();
        bool consumeMouseDown     (gPoint& location, gMouseButtons& button);
        bool discardMouseDown     ();
        bool isMouseDownLost      ();
        bool isMouseDownBufferFull();

        bool isMouseUpAvailable ();
        void flushMouseUp       ();
        bool consumeMouseUp     (gPoint& location, gMouseButtons& button);
        bool discardMouseUp     ();
        bool isMouseUpLost      ();
        bool isMouseUpBufferFull();

        int getCanvasWidth ();
        int getCanvasHeight();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor();
        void   setFillColor(gColor color);

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

        bool drawBorderCircle(int x, int y, int radius);
        bool drawFillCircle  (int x, int y, int radius);

        bool drawBorderEllipse(int x, int y, int width, int height);
        bool drawFillEllipse  (int x, int y, int width, int height);

    private:

        CLRWindowHost window;

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
