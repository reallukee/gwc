//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Image.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_IMAGE_HPP
#define GWC_IMAGE_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API gImage sealed
    {

    public:

        gImage (const char* path);
        gImage (string path);
        ~gImage();

        gImage(gImage&& other) noexcept;
        gImage& operator=(gImage&& other) noexcept;

        gImage(const gImage&) = delete;
        gImage& operator=(const gImage&) = delete;

        bool    isLoaded() const;
        void    release();
        HBITMAP get() const;

    private:

        HBITMAP image;

    };
}

#endif // __cplusplus

#endif // !GWC_IMAGE_HPP
