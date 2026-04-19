//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHost.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITEHOST_CLR_HPP
#define GWC_SPRITEHOST_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    class SpriteHost sealed
    {

    public:

        SpriteHost(int width, int height);
        SpriteHost();
        ~SpriteHost();

        bool    isNull();

        Sprite^ invoke();

    private:

        gcroot<Sprite^> sprite;

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_SPRITEHOST_CLR_HPP
