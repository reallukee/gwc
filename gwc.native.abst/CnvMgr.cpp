/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native Abst
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : CnvMgr.cpp
 *
 * Titolo    : CNVMGR
 * Sommario  : CnvMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#include "CnvMgr.hpp"
#include "CnvMgrHelper.hpp"

#include "SriMgrHelper.hpp"

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

    gColor CnvMgr::getBackColor()
    {
        CCI_GET_COLOR_CPP(getBackColor());
    }

    void CnvMgr::setBackColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setBackColor(color));
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



    bool CnvMgr::clear()
    {
        CCI_BOOL_CPP(clear());
    }

    bool CnvMgr::clearArea(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(clearArea(x, y, width, height));
    }

    bool CnvMgr::clearF()
    {
        CCI_BOOL_CPP(clearF());
    }

    bool CnvMgr::clearAreaF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(clearAreaF(x, y, width, height));
    }



    bool CnvMgr::drawCanvas(int x, int y, CnvId canvasId)
    {
        Canvas* canvas = CnvMgrHelper::get(canvasId);

        CCI_BOOL_CPP(drawCanvas(x, y, canvas));
    }

    bool CnvMgr::drawCanvasF(float x, float y, CnvId canvasId)
    {
        Canvas* canvas = CnvMgrHelper::get(canvasId);

        CCI_BOOL_CPP(drawCanvasF(x, y, canvas));
    }



    bool CnvMgr::drawSprite(int x, int y, SriId spriteId)
    {
        Sprite* sprite = SriMgrHelper::get(spriteId);

        CCI_BOOL_CPP(drawSprite(x, y, sprite));
    }

    bool CnvMgr::drawSpriteF(float x, float y, SriId spriteId)
    {
        Sprite* sprite = SriMgrHelper::get(spriteId);

        CCI_BOOL_CPP(drawSpriteF(x, y, sprite));
    }



    bool CnvMgr::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawBorderSquare(x, y, side));
    }

    bool CnvMgr::drawBorderSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(drawBorderSquareF(x, y, side));
    }

    bool CnvMgr::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawFillSquare(x, y, side));
    }

    bool CnvMgr::drawFillSquareF(float x, float y, float side)
    {
        CCI_BOOL_CPP(drawFillSquareF(x, y, side));
    }



    bool CnvMgr::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderRectangle(x, y, width, height));
    }

    bool CnvMgr::drawBorderRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(drawBorderRectangleF(x, y, width, height));
    }

    bool CnvMgr::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillRectangle(x, y, width, height));
    }

    bool CnvMgr::drawFillRectangleF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(drawFillRectangleF(x, y, width, height));
    }



    bool CnvMgr::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawBorderCircle(x, y, radius));
    }

    bool CnvMgr::drawBorderCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(drawBorderCircleF(x, y, radius));
    }

    bool CnvMgr::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawFillCircle(x, y, radius));
    }

    bool CnvMgr::drawFillCircleF(float x, float y, float radius)
    {
        CCI_BOOL_CPP(drawFillCircleF(x, y, radius));
    }



    bool CnvMgr::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderEllipse(x, y, width, height));
    }

    bool CnvMgr::drawBorderEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(drawBorderEllipseF(x, y, width, height));
    }

    bool CnvMgr::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillEllipse(x, y, width, height));
    }

    bool CnvMgr::drawFillEllipseF(float x, float y, float width, float height)
    {
        CCI_BOOL_CPP(drawFillEllipseF(x, y, width, height));
    }



    bool CnvMgr::drawImage(int x, int y, const gImage& image)
    {
        CCI_BOOL_CPP(drawImage(x, y, image));
    }

    bool CnvMgr::drawImageF(float x, float y, const gImage& image)
    {
        CCI_BOOL_CPP(drawImageF(x, y, image));
    }

    bool CnvMgr::drawIcon(int x, int y, const gIcon& icon)
    {
        CCI_BOOL_CPP(drawIcon(x, y, icon));
    }

    bool CnvMgr::drawIconF(float x, float y, const gIcon& icon)
    {
        CCI_BOOL_CPP(drawIconF(x, y, icon));
    }



    void CnvMgr::render()
    {
        CCI_VOID_CPP(render());
    }



    Canvas* CnvMgrHelper::get(CanvasId id)
    {
        if (!ready)
        {
            return nullptr;
        }

        if (id < 0 || id > MAX_ITEMS_COUNT - 1)
        {
            return nullptr;
        }

        if (items[id] == nullptr)
        {
            return nullptr;
        }

        return items[id];
    }
}

#endif // __cplusplus
