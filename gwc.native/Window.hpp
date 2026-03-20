//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  Window.hpp
//

#pragma once

#ifndef GWC_WINDOW_HPP
#define GWC_WINDOW_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API Window
    {

    private:

        void* window;

    public:

        Window ();
        ~Window();

        bool open    ();
        bool shutdown();

        bool isOpen    ();
        bool isShutdown();

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle  (int x, int y, int width, int height);

    };
}

#endif // __cplusplus

#endif // !GWC_WINDOW_HPP
