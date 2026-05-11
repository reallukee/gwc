//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Image.cpp
//  Licenza MIT
//

#include "Image.hpp"

#ifdef __cplusplus

namespace gwc
{
    static const wchar_t* strToWStr(const char* str)
    {
        int size = MultiByteToWideChar(
            CP_UTF8,
            0,
            str,
            -1,
            nullptr,
            0
        );

        if (size <= 0)
        {
            return nullptr;
        }

        wchar_t* wstr = new(nothrow) wchar_t[size];

        if (wstr == nullptr)
        {
            return nullptr;
        }

        MultiByteToWideChar(
            CP_UTF8,
            0,
            str,
            -1,
            &wstr[0],
            size
        );

        return wstr;
    }



    gImage::gImage(const char* path)
    {
        load(path);
    }

    gImage::gImage(string path)
    {
        load(path);
    }

    gImage::gImage() { }

    gImage::~gImage()
    {
        if (image != nullptr)
        {
            DeleteObject(image);
        }
    }



    gImage::gImage(gImage&& other) noexcept
    {
        image = other.image;

        other.image = nullptr;
    }

    gImage& gImage::operator=(gImage&& other) noexcept
    {
        if (this != &other)
        {
            if (image != nullptr)
            {
                DeleteObject(image);
            }

            image = other.image;

            other.image = nullptr;
        }

        return *this;
    }



    bool gImage::load(const char* path)
    {
        const wchar_t* wpath = strToWStr(path);

        if (wpath == nullptr)
        {
            image = nullptr;

            return false;
        }

        image = (HBITMAP)LoadImageW(
            nullptr,
            wpath,
            IMAGE_BITMAP,
            0,
            0,
            LR_LOADFROMFILE | LR_CREATEDIBSECTION
        );

        delete[] wpath;

        return true;
    }

    bool gImage::load(string path)
    {
        return load(path.c_str());
    }

    void gImage::unload()
    {
        if (!isLoaded())
        {
            return;
        }

        DeleteObject(image);
    }



    bool gImage::isLoaded() const
    {
        return image != nullptr;
    }

    bool gImage::isUnloaded() const
    {
        return image == nullptr;
    }



    HBITMAP gImage::get() const
    {
        return image;
    }
}

#endif // __cplusplus
