//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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

        bool open    ();
        bool shutdown();

        bool isOpen    ();
        bool isShutdown();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);

        void wait(int milliseconds);

        int getWindowWidth ();
        int getWindowHeight();
        int getRenderWidth ();
        int getRenderHeight();

        bool isKeyDownAvailable ();
        void flushKeyDown       ();
        bool consumeKeyDown     (gKeys& modifiers, gKeys& key);
        bool discardKeyDown     ();
        void waitKeyDown        ();
        bool isKeyDownLost      ();
        bool isKeyDownBufferFull();

        bool isKeyUpAvailable ();
        void flushKeyUp       ();
        bool consumeKeyUp     (gKeys& modifiers, gKeys& key);
        bool discardKeyUp     ();
        void waitKeyUp        ();
        bool isKeyUpLost      ();
        bool isKeyUpBufferFull();

        bool isMouseDownAvailable ();
        void flushMouseDown       ();
        bool consumeMouseDown     (gPoint& location, gMouseButtons& button);
        bool discardMouseDown     ();
        void waitMouseDown        ();
        bool isMouseDownLost      ();
        bool isMouseDownBufferFull();

        bool isMouseUpAvailable ();
        void flushMouseUp       ();
        bool consumeMouseUp     (gPoint& location, gMouseButtons& button);
        bool discardMouseUp     ();
        void waitMouseUp        ();
        bool isMouseUpLost      ();
        bool isMouseUpBufferFull();

        int getCanvasWidth ();
        int getCanvasHeight();

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
