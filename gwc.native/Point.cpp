//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Point.cpp
//  Licenza MIT
//

#include "Point.hpp"

#ifdef __cplusplus

namespace gwc
{
    Point::Point(int x, int y)
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

    Point::~Point() { }



    int Point::getX() const
    {
        return x;
    }

    void Point::setX(int value)
    {
        if (value < 0)
        {
            return;
        }

        x = value;
    }

    int Point::getY() const
    {
        return y;
    }

    void Point::setY(int value)
    {
        if (value < 0)
        {
            return;
        }

        y = value;
    }



    bool Point::operator==(const Point& other) const
    {
        return x == other.x &&
               y == other.y;
    }

    bool Point::operator!=(const Point& other) const
    {
        return x != other.x &&
               y != other.y;
    }
}

#endif // __cplusplus
