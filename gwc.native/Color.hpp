//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Color.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_COLOR_HPP
#define GWC_COLOR_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API Color
    {

    public:

        Color (int alpha, int red, int green, int blue);
        ~Color();

        int  getAlpha();
        void setAlpha(int value);
        int  getRed  ();
        void setRed  (int value);
        int  getGreen();
        void setGreen(int value);
        int  getBlue ();
        void setBlue (int value);

    private:

        int alpha;
        int red;
        int green;
        int blue;

    };
}

#endif // __cplusplus

#endif // !GWC_COLOR_HPP
