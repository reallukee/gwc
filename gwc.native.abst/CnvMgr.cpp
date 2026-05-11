//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CnvMgr.cpp
//  Licenza MIT
//

#include "CnvMgr.hpp"

#include <Canvas.hpp>

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;
    static const int NO_ITEM         = -1;

    static bool ready = false;

    static Canvas* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

    #define ITEM items[currentItem]

    void CnvMgr::init()
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

    void CnvMgr::shutdown()
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



    bool CnvMgr::setCurrent(int id)
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

    int CnvMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    int CnvMgr::alloc(int width, int height, bool select)
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

        Canvas* canvas = new(nothrow) Canvas(width, height);

        if (canvas == nullptr)
        {
            return NO_ITEM;
        }

        items[nextItem] = canvas;

        if (select)
        {
            currentItem = nextItem;
        }

        return nextItem;
    }

    int CnvMgr::alloc(bool select)
    {
        return alloc(800, 600, select);
    }

    void CnvMgr::free()
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



    bool CnvMgr::isInitialized()
    {
        if (!ready)
        {
            return false;
        }

        return ITEM->isInitialized();
    }



    CnvMgr::CnvMgr() {}

    CnvMgr::~CnvMgr() {}
}

#endif // __cplusplus
