//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Sprite.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITE_HPP
#define GWC_SPRITE_HPP

#ifdef  __cplusplus

#include "types.hpp"

namespace gwc
{
    class Canvas;
    class SpriteHelper;

    class GWC_CPP_API Sprite sealed
    {

    public:

        friend class SpriteHelper;

        Sprite (int width, int height);
        Sprite ();
        ~Sprite();

        bool isInitialized();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);

        gRectangle bounds  ();
        gSize      size    ();
        gPoint     location();

        int getWidth ();
        int getHeight();

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

        void render();

    private:

        CLRSpriteHost sprite;

    };
}

#endif //  __cplusplus

#endif // !GWC_SPRITE_HPP
