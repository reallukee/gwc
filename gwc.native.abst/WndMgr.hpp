//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// WndMgr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_WNDMGR_HPP
#define GWC_ABST_WNDMGR_HPP

#ifdef __cplusplus

#include "header.hpp"

#include <types.hpp>

using namespace gwc;

namespace gwc_abst
{
    typedef int WndId;

    class GWC_ABST_CPP_API WndMgr sealed
    {

    public:

        static void init    ();
        static void shutdown();

        static bool  setCurrent(WndId id);
        static WndId getCurrent();

        static WndId alloc(int width, int height, bool select);
        static WndId alloc(bool select);
        static void  free ();

        static bool isInitialized();

        static bool open ();
        static bool close();

        static bool isOpen ();
        static bool isClose();

        static bool suspend();
        static bool resume ();

        static bool isSuspend();
        static bool isResume ();

        static void wait(int milliseconds);

        static void skip(int frames);

        static bool show();
        static bool hide();

        static int getWindowWidth ();
        static int getWindowHeight();
        static int getRenderWidth ();
        static int getRenderHeight();

        static bool isKeyDownAvailable ();
        static void flushKeyDown       ();
        static bool consumeKeyDown     (gKeys& modifiers, gKeys& key);
        static bool discardKeyDown     ();
        static bool isKeyDownLost      ();
        static bool isKeyDownBufferFull();

        static bool isKeyUpAvailable ();
        static void flushKeyUp       ();
        static bool consumeKeyUp     (gKeys& modifiers, gKeys& key);
        static bool discardKeyUp     ();
        static bool isKeyUpLost      ();
        static bool isKeyUpBufferFull();

        static bool isMouseDownAvailable ();
        static void flushMouseDown       ();
        static bool consumeMouseDown     (gPoint& location, gMouseButtons& button);
        static bool discardMouseDown     ();
        static bool isMouseDownLost      ();
        static bool isMouseDownBufferFull();

        static bool isMouseUpAvailable ();
        static void flushMouseUp       ();
        static bool consumeMouseUp     (gPoint& location, gMouseButtons& button);
        static bool discardMouseUp     ();
        static bool isMouseUpLost      ();
        static bool isMouseUpBufferFull();

        static int getCanvasWidth ();
        static int getCanvasHeight();

        static gColor getBorderColor();
        static void   setBorderColor(gColor color);
        static gColor getFillColor();
        static void   setFillColor(gColor color);

        static bool drawBorderSquare(int x, int y, int side);
        static bool drawFillSquare  (int x, int y, int side);

        static bool drawBorderRectangle(int x, int y, int width, int height);
        static bool drawFillRectangle  (int x, int y, int width, int height);

        static bool drawBorderCircle(int x, int y, int radius);
        static bool drawFillCircle  (int x, int y, int radius);

        static bool drawBorderEllipse(int x, int y, int width, int height);
        static bool drawFillEllipse  (int x, int y, int width, int height);

        static bool drawImage(int x, int y, const gImage& image);
        static bool drawIcon (int x, int y, const gIcon& icon);

    private:

        WndMgr ();
        ~WndMgr();

    };

    typedef WndId WindowId;

    typedef WndMgr WindowManager;
}

#endif // __cplusplus

#endif // !GWC_ABST_WNDMGR_HPP
