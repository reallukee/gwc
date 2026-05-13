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

#include "macros.hpp"

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;

    static bool ready = false;

    static Canvas* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

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



    bool CnvMgr::setCurrent(CnvId id)
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

    CnvId CnvMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    CnvId CnvMgr::alloc(int width, int height, bool select)
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

    CnvId CnvMgr::alloc(bool select)
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
        CCI_BOOL_CPP(isInitialized());
    }



    gColor CnvMgr::getBorderColor()
    {
        CCI_GET_COLOR_CPP(getBorderColor());
    }

    void CnvMgr::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setBorderColor(color));
    }

    gColor CnvMgr::getFillColor()
    {
        CCI_GET_COLOR_CPP(getFillColor());
    }

    void CnvMgr::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setFillColor(color));
    }



    gRectangle CnvMgr::bounds()
    {
        CCI_GET_RECTANGLE_CPP(bounds());
    }

    gSize CnvMgr::size()
    {
        CCI_GET_SIZE_CPP(size());
    }

    gPoint CnvMgr::location()
    {
        CCI_GET_POINT_CPP(location());
    }



    int CnvMgr::getWidth()
    {
        CCI_INT_CPP(getWidth());
    }

    int CnvMgr::getHeight()
    {
        CCI_INT_CPP(getHeight());
    }



    bool CnvMgr::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawBorderSquare(x, y, side));
    }

    bool CnvMgr::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawFillSquare(x, y, side));
    }



    bool CnvMgr::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderRectangle(x, y, width, height));
    }

    bool CnvMgr::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillRectangle(x, y, width, height));
    }



    bool CnvMgr::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawBorderCircle(x, y, radius));
    }

    bool CnvMgr::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawFillCircle(x, y, radius));
    }



    bool CnvMgr::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderEllipse(x, y, width, height));
    }

    bool CnvMgr::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillEllipse(x, y, width, height));
    }



    bool CnvMgr::drawImage(int x, int y, const gImage& image)
    {
        CCI_BOOL_CPP(drawImage(x, y, image));
    }

    bool CnvMgr::drawIcon(int x, int y, const gIcon& icon)
    {
        CCI_BOOL_CPP(drawIcon(x, y, icon));
    }



    void CnvMgr::render()
    {
        CCI_VOID_CPP(render());
    }



    CnvMgr::CnvMgr() {}

    CnvMgr::~CnvMgr() {}
}

#endif // __cplusplus
