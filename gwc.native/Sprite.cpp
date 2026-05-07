//
// :.:.:.:.:.
// GWC.Native
// v0.4.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Sprite.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Sprite.hpp"
#include "macros.hpp"

#ifdef __cplusplus

namespace gwc
{
    Sprite::Sprite(int width, int height)
    {
        SpriteHost* host = new SpriteHost(width, height);

        sprite = static_cast<CLRSpriteHost>(host);
    }

    Sprite::Sprite()
    {
        SpriteHost* host = new SpriteHost();

        sprite = static_cast<CLRSpriteHost>(host);
    }

    Sprite::~Sprite()
    {
        SpriteHost* host = static_cast<SpriteHost*>(sprite);

        delete host;
    }



    bool Sprite::isInitialized()
    {
        SpriteHost* host = static_cast<SpriteHost*>(sprite);

        if (host == nullptr)
        {
            return false;
        }

        return !host->isNull();
    }



    gColor Sprite::getBorderColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, sprite, BorderColor);
    }

    void Sprite::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, sprite, BorderColor, color);
    }

    gColor Sprite::getFillColor()
    {
        CCI_GET_COLOR_CPP(SpriteHost, sprite, FillColor);
    }

    void Sprite::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(SpriteHost, sprite, FillColor, color);
    }



    gRectangle Sprite::bounds()
    {
        CCI_GET_RECTANGLE_CPP(SpriteHost, sprite, Bounds);
    }

    gSize Sprite::size()
    {
        CCI_GET_SIZE_CPP(SpriteHost, sprite, Size);
    }

    gPoint Sprite::location()
    {
        CCI_GET_POINT_CPP(SpriteHost, sprite, Location);
    }



    int Sprite::getWidth()
    {
        CCI_INT_CPP(SpriteHost, sprite, Width);
    }

    int Sprite::getHeight()
    {
        CCI_INT_CPP(SpriteHost, sprite, Height);
    }



    bool Sprite::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderSquare(x, y, side));
    }

    bool Sprite::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillSquare(x, y, side));
    }



    bool Sprite::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderRectangle(x, y, width, height));
    }

    bool Sprite::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillRectangle(x, y, width, height));
    }



    bool Sprite::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderCircle(x, y, radius));
    }

    bool Sprite::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillCircle(x, y, radius));
    }



    bool Sprite::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawBorderEllipse(x, y, width, height));
    }

    bool Sprite::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(SpriteHost, sprite, DrawFillEllipse(x, y, width, height));
    }



    void Sprite::render()
    {
        CCI_VOID_CPP(SpriteHost, sprite, Render());
    }
}

#endif // __cplusplus
