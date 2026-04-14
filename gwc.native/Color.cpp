//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
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
    Color::Color(int alpha, int red, int green, int blue)
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

    Color::~Color() { }



    int Color::getAlpha() const
    {
        return alpha;
    }

    void Color::setAlpha(int value)
    {
        if (value < 0 || value > 100)
        {
            return;
        }

        alpha = value;
    }

    int Color::getRed() const
    {
        return red;
    }

    void Color::setRed(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        red = value;
    }

    int Color::getGreen() const
    {
        return green;
    }

    void Color::setGreen(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        green = value;
    }

    int Color::getBlue() const
    {
        return blue;
    }

    void Color::setBlue(int value)
    {
        if (value < 0 || value > 255)
        {
            return;
        }

        blue = value;
    }



    bool Color::operator==(const Color& other) const
    {
        return alpha == other.alpha &&
               red   == other.red   &&
               green == other.green &&
               blue  == other.blue;
    }

    bool Color::operator!=(const Color& other) const
    {
        return alpha != other.alpha &&
               red   != other.red   &&
               green != other.green &&
               blue  != other.blue;
    }
}

#endif // __cplusplus
