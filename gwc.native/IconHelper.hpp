//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// IconHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ICONHELPER_HPP
#define GWC_ICONHELPER_HPP

#ifdef __cplusplus

#include "Icon.hpp"

#include <gdiplus.h>

using namespace Gdiplus;

namespace gwc
{
    class IconHelper sealed
    {

    public:

        static HICON get(const gIcon& icon);

    private:

        IconHelper () = default;
        ~IconHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_ICONHELPER_HPP
