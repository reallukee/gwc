//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// WndMgr.cpp
//  Licenza MIT
//

#include "WndMgr.hpp"

#include <Window.hpp>

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;
    static const int NO_ITEM         = -1;

    static bool ready = false;

    static Window* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

    #define ITEM items[currentItem]

    void WndMgr::init()
    {
        if (ready)
        {
            return;
        }

        for (int i = 0; i < MAX_ITEMS_COUNT; i++)
        {
            items[i] = nullptr;
        }

        currentItem = NO_ITEM;

        ready = true;
    }

    void WndMgr::shutdown()
    {
        if (!ready)
        {
            return;
        }

        ready = false;

        for (int i = 0; i < MAX_ITEMS_COUNT; i++)
        {
            if (items[i] != nullptr)
            {
                delete items[i];

                items[i] = nullptr;
            }
        }
    }



    bool WndMgr::setCurrent(int id)
    {
        if (!ready)
        {
            return false;
        }

        if (id < 0 || id > MAX_ITEMS_COUNT - 1)
        {
            return false;
        }

        if (items[id] == nullptr)
        {
            return false;
        }

        currentItem = id;

        return true;
    }

    int WndMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    int WndMgr::alloc(int width, int height, bool select)
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        int nextItem = NO_ITEM;

        for (int i = 0; i < MAX_ITEMS_COUNT && nextItem == NO_ITEM; i++)
        {
            if (items[i] == nullptr)
            {
                nextItem = i;
            }
        }

        if (nextItem == NO_ITEM)
        {
            return NO_ITEM;
        }

        Window* window = new(nothrow) Window(width, height);

        if (window == nullptr)
        {
            return NO_ITEM;
        }

        items[nextItem] = window;

        if (select)
        {
            currentItem = nextItem;
        }

        return nextItem;
    }

    int WndMgr::alloc(bool select)
    {
        return alloc(800, 600, select);
    }

    void WndMgr::free()
    {
        if (!ready)
        {
            return;
        }

        if (currentItem < 0 || currentItem > MAX_ITEMS_COUNT - 1)
        {
            return;
        }

        if (items[currentItem] == nullptr)
        {
            return;
        }

        delete items[currentItem];

        items[currentItem] = nullptr;
    }



    bool WndMgr::isInitialized()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->isInitialized();
    }



    bool WndMgr::open()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->open();
    }

    bool WndMgr::close()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->close();
    }



    bool WndMgr::isOpen()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->isOpen();
    }

    bool WndMgr::isClose()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->isClose();
    }



    void WndMgr::wait(int milliseconds)
    {
        if (!ready)
        {
            return;
        }

        ITEM->wait(milliseconds);
    }



    WndMgr::WndMgr() { }

    WndMgr::~WndMgr() { }
}

#endif // __cplusplus
