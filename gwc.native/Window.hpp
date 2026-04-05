//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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
#include "Color.hpp"
#include "Point.hpp"

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

        Color getBorderColor();
        void  setBorderColor(Color color);
        Color getFillColor  ();
        void  setFillColor  (Color color);

        void wait(int milliseconds);

        int getWindowWidth ();
        int getWindowHeight();
        int getRenderWidth ();
        int getRenderHeight();

        bool isKeyDownAvailable();
        void resetKeyDown      ();
        bool consumeKeyDown    (int& key);
        bool discardKeyDown    ();
        void waitKeyDown       ();

        bool isKeyUpAvailable();
        void resetKeyUp      ();
        bool consumeKeyUp    (int& key);
        bool discardKeyUp    ();
        void waitKeyUp       ();

        bool isMouseDownAvailable();
        void resetMouseDown      ();
        bool consumeMouseDown    (Point& location, int& button);
        bool discardMouseDown    ();
        void waitMouseDown       ();

        bool isMouseUpAvailable();
        void resetMouseUp      ();
        bool consumeMouseUp    (Point& location, int& button);
        bool discardMouseUp    ();
        void waitMouseUp       ();

        int getCanvasWidth ();
        int getCanvasHeight();

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

    private:

        CLRWindow window;

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
