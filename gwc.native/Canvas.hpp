//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_HPP
#define GWC_CANVAS_HPP

#ifdef  __cplusplus

#include "header.hpp"
#include "types.hpp"
#include "Color.hpp"

namespace gwc
{
    class GWC_CPP_API Canvas sealed
    {

    public:

        Canvas (int width, int height);
        Canvas ();
        ~Canvas();

        bool isInitialized();

        Color getBorderColor();
        void  setBorderColor(Color color);
        Color getFillColor  ();
        void  setFillColor  (Color color);

        int getWidth ();
        int getHeight();

        bool drawBorderSquare(int x, int y, int side);
        bool drawFillSquare  (int x, int y, int side);

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

    private:

        CLRCanvas canvas;

    };
}

#endif //  __cplusplus

#endif // !GWC_CANVAS_HPP
