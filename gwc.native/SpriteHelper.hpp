//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITEHELPER_HPP
#define GWC_SPRITEHELPER_HPP

#ifdef __cplusplus

#include "SpriteHost.clr.hpp"

using namespace Reallukee::GWC::Interop;

namespace gwc
{
    class Sprite;

    class SpriteHelper sealed
    {

    public:

        static SpriteHost* get(const Sprite* sprite);

    private:

        SpriteHelper () = default;
        ~SpriteHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_SPRITEHELPER_HPP
