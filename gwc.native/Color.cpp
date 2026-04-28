//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Color.cpp
//  Licenza MIT
//

#include "Color.hpp"

#ifdef __cplusplus

namespace gwc
{
    gColor::gColor(int alpha, int red, int green, int blue)
    {
        if (alpha < 0 || alpha > 100)
        {
            alpha = 100;
        }

        if (red < 0 || red > 255)
        {
            red = 255;
        }

        if (green < 0 || green > 255)
        {
            green = 255;
        }

        if (blue < 0 || blue > 255)
        {
            blue = 255;
        }

        this->alpha = alpha;
        this->red   = red;
        this->green = green;
        this->blue  = blue;
    }

    gColor::~gColor() { }



    int gColor::getAlpha() const
    {
        return alpha;
    }

    void gColor::setAlpha(int value)
    {
        if (value < 0 || value > 100)
        {
            return;
        }

        alpha = value;
    }

    int gColor::getRed() const
    {
        return red;
    }

    void gColor::setRed(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        red = value;
    }

    int gColor::getGreen() const
    {
        return green;
    }

    void gColor::setGreen(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        green = value;
    }

    int gColor::getBlue() const
    {
        return blue;
    }

    void gColor::setBlue(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        blue = value;
    }



    bool gColor::operator==(const gColor& other) const
    {
        return alpha == other.alpha &&
               red   == other.red   &&
               green == other.green &&
               blue  == other.blue;
    }

    bool gColor::operator!=(const gColor& other) const
    {
        return alpha != other.alpha &&
               red   != other.red   &&
               green != other.green &&
               blue  != other.blue;
    }
}

#endif // __cplusplus
