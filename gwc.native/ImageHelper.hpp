//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// ImageHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_IMAGEHELPER_HPP
#define GWC_IMAGEHELPDER_HPP

#ifdef __cplusplus

#include "Image.hpp"

namespace gwc
{
    class ImageHelper sealed
    {

    public:

        static HBITMAP get(const gImage& image);

    private:

        ImageHelper () = default;
        ~ImageHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_IMAGEHELPER_HPP
