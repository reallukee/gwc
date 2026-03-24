//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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

    private:

        int alpha;
        int red;
        int blue;
        int green;

    public:

        Color (int alpha, int red, int blue, int green);
        ~Color();

        int  getAlpha();
        void setAlpha(int value);
        int  getRed  ();
        void setRed  (int value);
        int  getBlue ();
        void setBlue (int value);
        int  getGreen();
        void setGreen(int value);

    };
}

#endif // __cplusplus

#endif // !GWC_COLOR_HPP
