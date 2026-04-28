//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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

#include "header.hpp"

#include "types.hpp"

namespace gwc
{
    class GWC_CPP_API Sprite sealed
    {

    public:

        Sprite (int width, int height);
        Sprite ();
        ~Sprite();

        bool isInitialized();

        gColor getBorderColor();
        void   setBorderColor(gColor color);
        gColor getFillColor  ();
        void   setFillColor  (gColor color);

        gRectangle bounds();
        gSize      size();
        gPoint     location();

        int getWidth ();
        int getHeight();

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

        bool drawBorderCircle(int x, int y, int radius);
        bool drawFillCircle  (int x, int y, int radius);

        bool drawBorderEllipse(int x, int y, int width, int height);
        bool drawFillEllipse  (int x, int y, int width, int height);

        void render();

    private:

        CLRSpriteHost sprite;

    };
}

#endif //  __cplusplus

#endif // !GWC_SPRITE_HPP
