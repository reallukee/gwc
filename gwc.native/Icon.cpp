//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Icon.cpp
//  Licenza MIT
//

#include "Icon.hpp"

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



    gIcon::gIcon(const char* path)
    {
        load(path);
    }

    gIcon::gIcon(string path)
    {
        load(path);
    }

    gIcon::gIcon() { }

    gIcon::~gIcon()
    {
        if (icon != nullptr)
        {
            DestroyIcon(icon);
        }
    }



    gIcon::gIcon(gIcon&& other) noexcept
    {
        icon = other.icon;

        other.icon = nullptr;
    }

    gIcon& gIcon::operator=(gIcon&& other) noexcept
    {
        if (this != &other)
        {
            if (icon != nullptr)
            {
                DestroyIcon(icon);
            }

            icon = other.icon;

            other.icon = nullptr;
        }

        return *this;
    }



    bool gIcon::load(const char* path)
    {
        const wchar_t* wpath = strToWStr(path);

        if (wpath == nullptr)
        {
            icon = nullptr;

            return false;
        }

        icon = (HICON)LoadImageW(
            nullptr,
            wpath,
            IMAGE_ICON,
            0,
            0,
            LR_LOADFROMFILE
        );

        delete[] wpath;

        return true;
    }

    bool gIcon::load(string path)
    {
        return load(path.c_str());
    }

    void gIcon::unload()
    {
        if (!isLoaded())
        {
            return;
        }

        DestroyIcon(icon);
    }



    bool gIcon::isLoaded() const
    {
        return icon != nullptr;
    }

    bool gIcon::isUnloaded() const
    {
        return icon == nullptr;
    }



    HICON gIcon::get() const
    {
        return icon;
    }
}

#endif // __cplusplus
