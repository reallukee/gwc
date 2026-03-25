//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Window.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_HPP
#define GWC_WINDOW_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "Color.hpp"

#define _WINDOW void*

namespace gwc
{
    class GWC_CPP_API Window sealed
    {

    private:

        _WINDOW window;

    public:

        Window (int width, int height);
        Window ();
        ~Window();

        bool isInitialized();

        bool open    ();
        bool shutdown();

        bool isOpen    ();
        bool isShutdown();

        Color getBorderColor();
        void  setBorderColor(Color color);
        Color getFillColor  ();
        void  setFillColor  (Color color);

        bool drawBorderSquare   (int x, int y, int side);
        bool drawFillSquare     (int x, int y, int side);
        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
