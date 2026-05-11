//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SriMgr.cpp
//  Licenza MIT
//

#include "SriMgr.hpp"

#include <Sprite.hpp>

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;
    static const int NO_ITEM         = -1;

    static bool ready = false;

    static Sprite* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

    #define ITEM items[currentItem]

    void SriMgr::init()
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

    void SriMgr::shutdown()
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



    bool SriMgr::setCurrent(int id)
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

    int SriMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    int SriMgr::alloc(int width, int height, bool select)
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

        Sprite* sprite = new(nothrow) Sprite(width, height);

        if (sprite == nullptr)
        {
            return NO_ITEM;
        }

        items[nextItem] = sprite;

        if (select)
        {
            currentItem = nextItem;
        }

        return nextItem;
    }

    int SriMgr::alloc(bool select)
    {
        return alloc(800, 600, select);
    }

    void SriMgr::free()
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



    bool SriMgr::isInitialized()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->isInitialized();
    }



    SriMgr::SriMgr() {}

    SriMgr::~SriMgr() {}
}

#endif // __cplusplus
