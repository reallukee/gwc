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
 * Nome file : CnvMgr.hpp
 *
 * Titolo    : CNVMGR
 * Sommario  : CnvMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_ABST_CNVMGR_HPP
#define GWC_ABST_CNVMGR_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "types.hpp"

#include "SriMgr.hpp"

using namespace gwc;

namespace gwc_abst
{
    class CnvMgrHelper;

    class GWC_ABST_CPP_API CnvMgr sealed
    {

    public:

        friend class CnvMgrHelper;

        static void init    ();
        static void shutdown();

        static bool  setCurrent(CnvId id);
        static CnvId getCurrent();

        static CnvId alloc(int width, int height, bool select);
        static CnvId alloc(bool select);
        static void  free ();

        static bool isInitialized();

        static gColor getBorderColor();
        static void   setBorderColor(gColor color);
        static gColor getFillColor  ();
        static void   setFillColor  (gColor color);
        static gColor getBackColor  ();
        static void   setBackColor  (gColor color);

        static gRectangle bounds  ();
        static gSize      size    ();
        static gPoint     location();

        static int getWidth ();
        static int getHeight();

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

        static void render();

    private:

        CnvMgr () = default;
        ~CnvMgr() = default;

    };

    typedef CnvMgr CanvasManager;
}

#endif // __cplusplus

#endif // !GWC_ABST_CNVMGR_HPP
