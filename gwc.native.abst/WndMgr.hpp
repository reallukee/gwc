/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native Abst
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : WndMgr.hpp
 *
 * Titolo    : WNDMGR
 * Sommario  : WndMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_ABST_WNDMGR_HPP
#define GWC_ABST_WNDMGR_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "types.hpp"

#include "SriMgr.hpp"
#include "CnvMgr.hpp"

using namespace gwc;

namespace gwc_abst
{
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
        static bool isKeyUpAvailable   ();
        static void flushKeyDown       ();
        static void flushKeyUp         ();
        static bool consumeKeyDown     (gKeys& modifiers, gKeys& key);
        static bool consumeKeyUp       (gKeys& modifiers, gKeys& key);
        static bool discardKeyDown     ();
        static bool discardKeyUp       ();
        static bool isKeyDownInBuffer  (gKeys modifiers, gKeys key);
        static bool isKeyUpInBuffer    (gKeys modifiers, gKeys key);
        static bool isKeyDownLost      ();
        static bool isKeyUpLost        ();
        static int  keyDownBufferLength();
        static int  keyUpBufferLength  ();

        static bool isMouseDownAvailable ();
        static bool isMouseUpAvailable   ();
        static void flushMouseDown       ();
        static void flushMouseUp         ();
        static bool consumeMouseDown     (gPoint& location, gMouseButtons& button);
        static bool consumeMouseUp       (gPoint& location, gMouseButtons& button);
        static bool discardMouseDown     ();
        static bool discardMouseUp       ();
        static bool isMouseDownInBuffer  (gPoint& location, gMouseButtons button);
        static bool isMouseUpInBuffer    (gPoint& location, gMouseButtons button);
        static bool isMouseDownLost      ();
        static bool isMouseUpLost        ();
        static int  mouseDownBufferLength();
        static int  mouseUpBufferLength  ();

        static int getCanvasWidth ();
        static int getCanvasHeight();

        static gColor getBorderColor();
        static void   setBorderColor(gColor color);
        static gColor getFillColor  ();
        static void   setFillColor  (gColor color);
        static gColor getBackColor  ();
        static void   setBackColor  (gColor color);

        static bool clear     ();
        static bool clearArea (int x, int y, int width, int height);
        static bool clearF    ();
        static bool clearAreaF(float x, float y, float width, float height);

        static bool drawCanvas (int x, int y, CanvasId canvasId);
        static bool drawCanvasF(float x, float y, CanvasId canvasId);

        static bool drawSprite (int x, int y, SpriteId spriteId);
        static bool drawSpriteF(float x, float y, const SpriteId spriteId);

        static bool drawBorderSquare (int x, int y, int side);
        static bool drawBorderSquareF(float x, float y, float side);
        static bool drawFillSquare   (int x, int y, int side);
        static bool drawFillSquareF  (float x, float y, float side);

        static bool drawBorderRectangle (int x, int y, int width, int height);
        static bool drawBorderRectangleF(float x, float y, float width, float height);
        static bool drawFillRectangle   (int x, int y, int width, int height);
        static bool drawFillRectangleF  (float x, float y, float width, float height);

        static bool drawBorderCircle (int x, int y, int radius);
        static bool drawBorderCircleF(float x, float y, float radius);
        static bool drawFillCircle   (int x, int y, int radius);
        static bool drawFillCircleF  (float x, float y, float radius);

        static bool drawBorderEllipse (int x, int y, int width, int height);
        static bool drawBorderEllipseF(float x, float y, float width, float height);
        static bool drawFillEllipse   (int x, int y, int width, int height);
        static bool drawFillEllipseF  (float x, float y, float width, float height);

        static bool drawImage (int x, int y, const gImage& image);
        static bool drawImageF(float x, float y, const gImage& image);
        static bool drawIcon  (int x, int y, const gIcon& icon);
        static bool drawIconF (float x, float y, const gIcon& icon);

    private:

        WndMgr () = default;
        ~WndMgr() = default;

    };

    typedef WndMgr WindowManager;
}

#endif // __cplusplus

#endif // !GWC_ABST_WNDMGR_HPP
