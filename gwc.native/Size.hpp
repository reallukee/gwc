//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Size.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SIZE_HPP
#define GWC_SIZE_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API gSize sealed
    {

    public:

        gSize (int width, int height);
        ~gSize();

        int  getWidth () const;
        void setWidth (int value);
        int  getHeight() const;
        void setHeight(int value);

        bool operator==(const gSize& other) const;
        bool operator!=(const gSize& other) const;

    private:

        int width;
        int height;

    };
}

#endif // __cplusplus

#endif // !GWC_SIZE_HPP
