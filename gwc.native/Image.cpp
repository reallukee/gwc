//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Image.cpp
//  Licenza MIT
//

#include "Image.hpp"
#include "ImageHelper.hpp"

#ifdef __cplusplus

namespace gwc
{
    static wchar_t* strToWStr(const char* str)
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

    gImage::gImage(const wchar_t* path)
    {
        load(path);
    }

    gImage::gImage(const string& path)
    {
        load(path);
    }

    gImage::gImage(const wstring& path)
    {
        load(path);
    }

    gImage::gImage()
    {
        this->image = nullptr;
    }

    gImage::~gImage()
    {
        unload();
    }



    static Bitmap* loadImage(const wchar_t* path)
    {
        if (path == nullptr)
        {
            return nullptr;
        }

        Bitmap* image = Bitmap::FromFile(path);

        if (image->GetLastStatus() != Status::Ok)
        {
            image = nullptr;

            return nullptr;
        }

        return image;
    }

    static NativeImage shareImage(Bitmap* image)
    {
        auto destructor = [](Bitmap* image)
        {
            if (image)
            {
                delete image;
            }
        };

        NativeImage _image(image, destructor);

        return _image;
    }



    bool gImage::load(const char* path)
    {
        const wchar_t* wpath = strToWStr(path);

        bool result = load(wpath);

        delete[] wpath;

        return result;
    }

    bool gImage::load(const wchar_t* path)
    {
        if (isLoaded())
        {
            return false;
        }

        Bitmap* _image = loadImage(path);

        if (_image == nullptr)
        {
            return false;
        }

        image = shareImage(_image);

        return true;
    }

    bool gImage::load(const string& path)
    {
        return load(path.c_str());
    }

    bool gImage::load(const wstring& path)
    {
        return load(path.c_str());
    }

    void gImage::unload()
    {
        if (!isLoaded())
        {
            return;
        }

        image.reset();
    }



    bool gImage::isLoaded() const
    {
        return image != nullptr;
    }

    bool gImage::isUnloaded() const
    {
        return image == nullptr;
    }



    Bitmap* ImageHelper::get(const gImage& image)
    {
        Bitmap* _image = static_cast<Bitmap*>(image.image.get());

        return _image;
    }
}

#endif // __cplusplus
