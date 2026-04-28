//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
    class GWC_CPP_API gColor sealed
    {

    public:

        gColor (int alpha, int red, int green, int blue);
        ~gColor();

        int  getAlpha() const;
        void setAlpha(int value);
        int  getRed  () const;
        void setRed  (int value);
        int  getGreen() const;
        void setGreen(int value);
        int  getBlue () const;
        void setBlue (int value);

        bool operator==(const gColor& other) const;
        bool operator!=(const gColor& other) const;

    private:

        int alpha;
        int red;
        int green;
        int blue;

    };
}

#endif // __cplusplus

#endif // !GWC_COLOR_HPP
