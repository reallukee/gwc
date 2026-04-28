//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Rectangle.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_RECTANGLE_HPP
#define GWC_RECTANGLE_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API gRectangle sealed
    {

    public:

        gRectangle (int x, int y, int width, int height);
        ~gRectangle();

        int  getX     () const;
        void setX     (int value);
        int  getY     () const;
        void setY     (int value);
        int  getWidth () const;
        void setWidth (int value);
        int  getHeight() const;
        void setHeight(int value);

        bool operator==(const gRectangle& other) const;
        bool operator!=(const gRectangle& other) const;

    private:

        int x;
        int y;
        int width;
        int height;

    };
}

#endif // __cplusplus

#endif // !GWC_RECTANGLE_HPP
