//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Sprite.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Sprite.hpp"
#include "sprite_macros.hpp"

#ifdef __cplusplus

namespace gwc
{
    Sprite::Sprite(int width, int height)
    {
        IntPtr managedHandle = SpriteHandler::Alloc(width, height);

        CLRSprite nativeHandle = reinterpret_cast<CLRSprite>(managedHandle.ToPointer());

        sprite = nativeHandle;
    }

    Sprite::Sprite()
    {
        IntPtr managedHandle = SpriteHandler::Alloc();

        CLRSprite nativeHandle = reinterpret_cast<CLRSprite>(managedHandle.ToPointer());

        sprite = nativeHandle;
    }

    Sprite::~Sprite()
    {
        CLRSprite nativeHandle = sprite;

        IntPtr managedHandle = IntPtr(nativeHandle);

        if (SpriteHandler::IsNull(managedHandle))
        {
            return;
        }

        SpriteHandler::Free(managedHandle);
    }



    bool Sprite::isInitialized()
    {
        CLRSprite nativeHandle = sprite;

        return nativeHandle != nullptr;
    }



    Color Sprite::getBorderColor()
    {
        CCI_SPRITE_GET_COLOR_CPP(sprite, BorderColor);
    }

    void Sprite::setBorderColor(Color color)
    {
        CCI_SPRITE_SET_COLOR_CPP(sprite, BorderColor, color);
    }

    Color Sprite::getFillColor()
    {
        CCI_SPRITE_GET_COLOR_CPP(sprite, FillColor);
    }

    void Sprite::setFillColor(Color color)
    {
        CCI_SPRITE_SET_COLOR_CPP(sprite, FillColor, color);
    }



    int Sprite::getWidth()
    {
        CCI_SPRITE_INT_CPP(sprite, Width);
    }

    int Sprite::getHeight()
    {
        CCI_SPRITE_INT_CPP(sprite, Height);
    }



    bool Sprite::drawBorderSquare(int x, int y, int side)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawBorderSquare(x, y, side));
    }

    bool Sprite::drawFillSquare(int x, int y, int side)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawFillSquare(x, y, side));
    }



    bool Sprite::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawBorderRectangle(x, y, width, height));
    }

    bool Sprite::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawFillRectangle(x, y, width, height));
    }



    bool Sprite::drawBorderCircle(int x, int y, int radius)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawBorderCircle(x, y, radius));
    }

    bool Sprite::drawFillCircle(int x, int y, int radius)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawFillCircle(x, y, radius));
    }



    bool Sprite::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawBorderEllipse(x, y, width, height));
    }

    bool Sprite::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_SPRITE_BOOL_CPP(sprite, DrawFillEllipse(x, y, width, height));
    }



    void Sprite::render()
    {
        CCI_SPRITE_VOID_CPP(sprite, Render());
    }
}

#endif // __cplusplus
