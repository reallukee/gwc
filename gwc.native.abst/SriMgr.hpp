//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SriMgr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_SRIMGR_HPP
#define GWC_ABST_SRIMGR_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "types.hpp"

#include "CnvMgr.hpp"

using namespace gwc;

namespace gwc_abst
{
    class SriMgrHelper;

    class GWC_ABST_CPP_API SriMgr sealed
    {

    public:

        friend class SriMgrHelper;

        static void init    ();
        static void shutdown();

        static bool  setCurrent(SriId id);
        static SriId getCurrent();

        static SriId alloc(int width, int height, bool select);
        static SriId alloc(bool select);
        static void  free ();

        static bool isInitialized();

        static gColor getBorderColor();
        static void   setBorderColor(gColor color);
        static gColor getFillColor  ();
        static void   setFillColor  (gColor color);

        static gRectangle bounds  ();
        static gSize      size    ();
        static gPoint     location();

        static int getWidth ();
        static int getHeight();

        static bool clear(gColor color);

        static bool drawCanvas(int x, int y, CnvId canvasId);
        static bool drawSprite(int x, int y, SriId spriteId);

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

        static void render();

    private:

        SriMgr () = default;
        ~SriMgr() = default;

    };

    typedef SriMgr SpriteManager;
}

#endif // __cplusplus

#endif // !GWC_ABST_SRIMGR_HPP
