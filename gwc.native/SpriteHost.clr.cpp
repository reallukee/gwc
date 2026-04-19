//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHost.clr.cpp
//  Licenza MIT
//

#include "SpriteHost.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    SpriteHost::SpriteHost(int width, int height)
    {
        sprite = gcnew Sprite(width, height);
    }

    SpriteHost::SpriteHost()
    {
        sprite = gcnew Sprite();
    }

    SpriteHost::~SpriteHost()
    {
        Sprite^ unwrapSprite = sprite;

        if (unwrapSprite != nullptr)
        {
            return;
        }

        sprite = nullptr;
    }



    bool SpriteHost::isNull()
    {
        Sprite^ unwrapSprite = sprite;

        return unwrapSprite == nullptr;
    }



    Sprite^ SpriteHost::invoke()
    {
        Sprite^ unwrapSprite = sprite;

        if (unwrapSprite == nullptr)
        {
            return nullptr;
        }

        return sprite;
    }
}
}
}

#endif // __cplusplus_cli
