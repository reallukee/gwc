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

#include "macros.hpp"

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;

    static bool ready = false;

    static Sprite* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

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



    bool SriMgr::setCurrent(SriId id)
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

    SriId SriMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    SriId SriMgr::alloc(int width, int height, bool select)
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

    SriId SriMgr::alloc(bool select)
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
        CCI_BOOL_CPP(isInitialized());
    }



    gColor SriMgr::getBorderColor()
    {
        CCI_GET_COLOR_CPP(getBorderColor());
    }

    void SriMgr::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setBorderColor(color));
    }

    gColor SriMgr::getFillColor()
    {
        CCI_GET_COLOR_CPP(getFillColor());
    }

    void SriMgr::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setFillColor(color));
    }



    gRectangle SriMgr::bounds()
    {
        CCI_GET_RECTANGLE_CPP(bounds());
    }

    gSize SriMgr::size()
    {
        CCI_GET_SIZE_CPP(size());
    }

    gPoint SriMgr::location()
    {
        CCI_GET_POINT_CPP(location());
    }



    int SriMgr::getWidth()
    {
        CCI_INT_CPP(getWidth());
    }

    int SriMgr::getHeight()
    {
        CCI_INT_CPP(getHeight());
    }



    bool SriMgr::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawBorderSquare(x, y, side));
    }

    bool SriMgr::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawFillSquare(x, y, side));
    }



    bool SriMgr::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderRectangle(x, y, width, height));
    }

    bool SriMgr::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillRectangle(x, y, width, height));
    }



    bool SriMgr::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawBorderCircle(x, y, radius));
    }

    bool SriMgr::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawFillCircle(x, y, radius));
    }



    bool SriMgr::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderEllipse(x, y, width, height));
    }

    bool SriMgr::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillEllipse(x, y, width, height));
    }



    bool SriMgr::drawImage(int x, int y, const gImage& image)
    {
        CCI_BOOL_CPP(drawImage(x, y, image));
    }

    bool SriMgr::drawIcon(int x, int y, const gIcon& icon)
    {
        CCI_BOOL_CPP(drawIcon(x, y, icon));
    }



    void SriMgr::render()
    {
        CCI_VOID_CPP(render());
    }



    SriMgr::SriMgr() {}

    SriMgr::~SriMgr() {}
}

#endif // __cplusplus
