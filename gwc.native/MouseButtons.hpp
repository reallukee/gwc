//
// :.:.:.:.:.
// GWC.Native
// v0.2.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// MouseButtons.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_MOUSEBUTTONS_HPP
#define GWC_MOUSEBUTTONS_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    enum class GWC_CPP_API MouseButtons
    {
        None     = 0,
        Left     = 1048576,
        Right    = 2097152,
        Middle   = 4194304,
        XButton1 = 8388608,
        XButton2 = 16777216
    };
}

#endif // __cplusplus

#endif // !GWC_MOUSEBUTTONS_HPP
