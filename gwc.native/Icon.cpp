//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Icon.cpp
//  Licenza MIT
//

#include "Icon.hpp"
#include "IconHelper.hpp"

#include <gdiplus.h>

using namespace Gdiplus;

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



    gIcon::gIcon(const char* path)
    {
        load(path);
    }

    gIcon::gIcon(const wchar_t* path)
    {
        load(path);
    }

    gIcon::gIcon(const string& path)
    {
        load(path);
    }

    gIcon::gIcon(const wstring& path)
    {
        load(path);
    }

    gIcon::gIcon()
    {
        this->icon = nullptr;
    }

    gIcon::~gIcon()
    {
        unload();
    }



    static HICON loadIcon(const wchar_t* path)
    {
        if (path == nullptr)
        {
            return nullptr;
        }

        HICON icon = (HICON)LoadImageW(
            nullptr,
            path,
            IMAGE_ICON,
            0,
            0,
            LR_LOADFROMFILE
        );

        return icon;
    }

    static NativeIcon shareIcon(HICON icon)
    {
        auto destructor = [](HICON icon)
        {
            if (icon)
            {
                DestroyIcon(icon);
            }
        };

        NativeIcon _icon(icon, destructor);

        return _icon;
    }



    bool gIcon::load(const char* path)
    {
        const wchar_t* wpath = strToWStr(path);

        bool result = load(wpath);

        delete[] wpath;

        return result;
    }

    bool gIcon::load(const wchar_t* path)
    {
        if (isLoaded())
        {
            return false;
        }

        HICON _icon = loadIcon(path);

        if (_icon == nullptr)
        {
            return false;
        }

        icon = shareIcon(_icon);

        return true;
    }

    bool gIcon::load(const string& path)
    {
        return load(path.c_str());
    }

    bool gIcon::load(const wstring& path)
    {
        return load(path.c_str());
    }

    void gIcon::unload()
    {
        if (!isLoaded())
        {
            return;
        }

        icon.reset();
    }



    bool gIcon::isLoaded() const
    {
        return icon != nullptr;
    }

    bool gIcon::isUnloaded() const
    {
        return icon == nullptr;
    }



    HICON IconHelper::get(const gIcon& icon)
    {
        HICON _icon = static_cast<HICON>(icon.icon.get());

        return _icon;
    }
}

#endif // __cplusplus
