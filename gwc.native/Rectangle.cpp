//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Rectangle.cpp
//  Licenza MIT
//

#include "Rectangle.hpp"

#ifdef __cplusplus

namespace gwc
{
    gRectangle::gRectangle(int x, int y, int width, int height)
    {
        if (x < 0)
        {
            x = 0;
        }

        if (y < 0)
        {
            y = 0;
        }

        if (width < 0)
        {
            width = 0;
        }

        if (height < 0)
        {
            height = 0;
        }

        this->x      = x;
        this->y      = y;
        this->width  = width;
        this->height = height;
    }

    gRectangle::~gRectangle() {}



    int gRectangle::getX() const
    {
        return x;
    }

    void gRectangle::setX(int value)
    {
        if (value < 0)
        {
            return;
        }

        x = value;
    }

    int gRectangle::getY() const
    {
        return y;
    }

    void gRectangle::setY(int value)
    {
        if (value < 0)
        {
            return;
        }

        y = value;
    }

    int gRectangle::getWidth() const
    {
        return width;
    }

    void gRectangle::setWidth(int value)
    {
        if (value < 0)
        {
            return;
        }

        width = value;
    }

    int gRectangle::getHeight() const
    {
        return height;
    }

    void gRectangle::setHeight(int value)
    {
        if (value < 0)
        {
            return;
        }

        height = value;
    }



    bool gRectangle::operator==(const gRectangle& other) const
    {
        return x      == other.x      &&
               y      == other.y      &&
               width  == other.width  &&
               height == other.height;
    }

    bool gRectangle::operator!=(const gRectangle& other) const
    {
        return x      != other.x      &&
               y      != other.y      &&
               width  != other.width  &&
               height != other.height;
    }
}

#endif // __cplusplus
