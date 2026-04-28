//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Point.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_POINT_HPP
#define GWC_POINT_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API gPoint sealed
    {

    public:

        gPoint (int x, int y);
        ~gPoint();

        int  getX() const;
        void setX(int value);
        int  getY() const;
        void setY(int value);

        bool operator==(const gPoint& other) const;
        bool operator!=(const gPoint& other) const;

    private:

        int x;
        int y;

    };
}

#endif // __cplusplus

#endif // !GWC_POINT_HPP
