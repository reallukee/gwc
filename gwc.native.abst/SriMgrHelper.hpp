//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SriMgrHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_SRIMGRHELPER_HPP
#define GWC_ABST_SRIMGRHELPER_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "types.hpp"

#include <Sprite.hpp>

using namespace gwc;

namespace gwc_abst
{
    class SriMgrHelper sealed
    {

    public:

        static Sprite* get(SpriteId id);

    private:

        SriMgrHelper () = default;
        ~SriMgrHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_ABST_SRIMGRHELPER_HPP
