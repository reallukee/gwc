//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Size.cpp
//  Licenza MIT
//

#include "Size.hpp"

#ifdef __cplusplus

namespace gwc
{
    gSize::gSize(int width, int height)
    {
        if (width < 0)
        {
            width = 0;
        }

        if (height < 0)
        {
            height = 0;
        }

        this->width  = width;
        this->height = height;
    }

    gSize::~gSize() {}



    int gSize::getWidth() const
    {
        return width;
    }

    void gSize::setWidth(int value)
    {
        if (value < 0)
        {
            return;
        }

        width = value;
    }

    int gSize::getHeight() const
    {
        return height;
    }

    void gSize::setHeight(int value)
    {
        if (value < 0)
        {
            return;
        }

        height = value;
    }



    bool gSize::operator==(const gSize& other) const
    {
        return width  == other.width  &&
               height == other.height;
    }

    bool gSize::operator!=(const gSize& other) const
    {
        return width  != other.width  &&
               height != other.height;
    }
}

#endif // __cplusplus
