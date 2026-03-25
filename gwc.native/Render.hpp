//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Render.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_RENDER_HPP
#define GWC_RENDER_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API Render final
    {

    public:

        static int    getRefreshRate  ();
        static void   setRefreshRate  (int value);
        static int    getDutyCycle    ();
        static void   setDutyCycle    (int value);
        static double getFrameTime    ();
        static double getUtilFrameTime();

    private:

        Render ();
        ~Render();

    };
}

#endif // __cplusplus

#endif // !GWC_RENDER_HPP
