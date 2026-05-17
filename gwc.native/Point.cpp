//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Point.cpp
//  Licenza MIT
//

#include "Point.hpp"

#pragma unmanaged

#ifdef __cplusplus

namespace gwc
{
    gPoint::gPoint(int x, int y)
    {
        if (x < 0)
        {
            x = 0;
        }

        if (y < 0)
        {
            y = 0;
        }

        this->x = x;
        this->y = y;
    }

    gPoint::gPoint() : gPoint(0, 0) { }

    gPoint::~gPoint() { }



    int gPoint::getX() const
    {
        return x;
    }

    void gPoint::setX(int value)
    {
        if (value < 0)
        {
            return;
        }

        x = value;
    }

    int gPoint::getY() const
    {
        return y;
    }

    void gPoint::setY(int value)
    {
        if (value < 0)
        {
            return;
        }

        y = value;
    }



    bool gPoint::operator==(const gPoint& other) const
    {
        return x == other.x &&
               y == other.y;
    }

    bool gPoint::operator!=(const gPoint& other) const
    {
        return x != other.x &&
               y != other.y;
    }
}

#endif // __cplusplus
