//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// WndMgr.cpp
//  Licenza MIT
//

#include "WndMgr.hpp"

#include <Window.hpp>

#include "macros.hpp"

#include "SriMgrHelper.hpp"
#include "CnvMgrHelper.hpp"

#ifdef __cplusplus

namespace gwc_abst
{
    static const int MAX_ITEMS_COUNT = 10;

    static bool ready = false;

    static Window* items[MAX_ITEMS_COUNT] = { nullptr };
    static int     currentItem            = NO_ITEM;

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



    bool WndMgr::setCurrent(WndId id)
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

    WndId WndMgr::getCurrent()
    {
        if (!ready)
        {
            return NO_ITEM;
        }

        return currentItem;
    }



    WndId WndMgr::alloc(int width, int height, bool select)
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

    WndId WndMgr::alloc(bool select)
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
        CCI_BOOL_CPP(isInitialized());
    }



    bool WndMgr::open()
    {
        CCI_BOOL_CPP(open());
    }

    bool WndMgr::close()
    {
        CCI_BOOL_CPP(close());
    }



    bool WndMgr::isOpen()
    {
        CCI_BOOL_CPP(isOpen());
    }

    bool WndMgr::isClose()
    {
        CCI_BOOL_CPP(isClose());
    }



    bool WndMgr::suspend()
    {
        CCI_BOOL_CPP(suspend())
    }

    bool WndMgr::resume()
    {
        CCI_BOOL_CPP(resume())
    }



    bool WndMgr::isSuspend()
    {
        CCI_BOOL_CPP(isSuspend());
    }

    bool WndMgr::isResume()
    {
        CCI_BOOL_CPP(isResume());
    }



    void WndMgr::wait(int milliseconds)
    {
        CCI_VOID_CPP(wait(milliseconds));
    }

    void WndMgr::skip(int frames)
    {
        CCI_VOID_CPP(skip(frames));
    }



    bool WndMgr::show()
    {
        CCI_BOOL_CPP(show());
    }

    bool WndMgr::hide()
    {
        CCI_BOOL_CPP(hide());
    }



    int WndMgr::getWindowWidth()
    {
        CCI_INT_CPP(getWindowWidth());
    }

    int WndMgr::getWindowHeight()
    {
        CCI_INT_CPP(getWindowHeight());
    }

    int WndMgr::getRenderWidth()
    {
        CCI_INT_CPP(getRenderWidth());
    }

    int WndMgr::getRenderHeight()
    {
        CCI_INT_CPP(getRenderHeight());
    }



    bool WndMgr::isKeyDownAvailable()
    {
        CCI_BOOL_CPP(isKeyDownAvailable());
    }

    bool WndMgr::isKeyUpAvailable()
    {
        CCI_BOOL_CPP(isKeyUpAvailable());
    }

    void WndMgr::flushKeyDown()
    {
        CCI_VOID_CPP(flushKeyDown());
    }

    void WndMgr::flushKeyUp()
    {
        CCI_VOID_CPP(flushKeyUp());
    }

    bool WndMgr::consumeKeyDown(gKeys& modifiers, gKeys& key)
    {
        CCI_BOOL_CPP(consumeKeyDown(modifiers, key));
    }

    bool WndMgr::consumeKeyUp(gKeys& modifiers, gKeys& key)
    {
        CCI_BOOL_CPP(consumeKeyUp(modifiers, key));
    }

    bool WndMgr::discardKeyDown()
    {
        CCI_BOOL_CPP(discardKeyDown());
    }

    bool WndMgr::discardKeyUp()
    {
        CCI_BOOL_CPP(discardKeyUp());
    }

    bool WndMgr::isKeyDownInBuffer(gKeys modifiers, gKeys key)
    {
        CCI_BOOL_CPP(isKeyDownInBuffer(modifiers, key));
    }

    bool WndMgr::isKeyUpInBuffer(gKeys modifiers, gKeys key)
    {
        CCI_BOOL_CPP(isKeyUpInBuffer(modifiers, key));
    }

    bool WndMgr::isKeyDownLost()
    {
        CCI_BOOL_CPP(isKeyDownLost());
    }

    bool WndMgr::isKeyUpLost()
    {
        CCI_BOOL_CPP(isKeyUpLost());
    }

    int WndMgr::keyDownBufferLength()
    {
        CCI_INT_CPP(keyDownBufferLength());
    }

    int WndMgr::keyUpBufferLength()
    {
        CCI_INT_CPP(keyUpBufferLength());
    }



    bool WndMgr::isMouseDownAvailable()
    {
        CCI_BOOL_CPP(isMouseDownAvailable());
    }

    bool WndMgr::isMouseUpAvailable()
    {
        CCI_BOOL_CPP(isMouseUpAvailable());
    }

    void WndMgr::flushMouseDown()
    {
        CCI_VOID_CPP(flushMouseDown());
    }

    void WndMgr::flushMouseUp()
    {
        CCI_VOID_CPP(flushMouseUp());
    }

    bool WndMgr::consumeMouseDown(gPoint& location, gMouseButtons& button)
    {
        CCI_BOOL_CPP(consumeMouseDown(location, button));
    }

    bool WndMgr::consumeMouseUp(gPoint& location, gMouseButtons& button)
    {
        CCI_BOOL_CPP(consumeMouseUp(location, button));
    }

    bool WndMgr::discardMouseDown()
    {
        CCI_BOOL_CPP(discardMouseDown());
    }

    bool WndMgr::discardMouseUp()
    {
        CCI_BOOL_CPP(discardMouseUp());
    }

    bool WndMgr::isMouseDownInBuffer(gPoint& location, gMouseButtons button)
    {
        CCI_BOOL_CPP(isMouseDownInBuffer(location, button));
    }

    bool WndMgr::isMouseUpInBuffer(gPoint& location, gMouseButtons button)
    {
        CCI_BOOL_CPP(isMouseUpInBuffer(location, button));
    }

    bool WndMgr::isMouseDownLost()
    {
        CCI_BOOL_CPP(isMouseDownLost());
    }

    bool WndMgr::isMouseUpLost()
    {
        CCI_BOOL_CPP(isMouseUpLost());
    }

    int WndMgr::mouseDownBufferLength()
    {
        CCI_INT_CPP(mouseDownBufferLength());
    }

    int WndMgr::mouseUpBufferLength()
    {
        CCI_INT_CPP(mouseUpBufferLength());
    }



    int WndMgr::getCanvasWidth()
    {
        CCI_INT_CPP(getCanvasWidth());
    }

    int WndMgr::getCanvasHeight()
    {
        CCI_INT_CPP(getCanvasHeight());
    }



    gColor WndMgr::getBorderColor()
    {
        CCI_GET_COLOR_CPP(getBorderColor());
    }

    void WndMgr::setBorderColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setBorderColor(color));
    }

    gColor WndMgr::getFillColor()
    {
        CCI_GET_COLOR_CPP(getFillColor());
    }

    void WndMgr::setFillColor(gColor color)
    {
        CCI_SET_COLOR_CPP(setFillColor(color));
    }



    bool WndMgr::clear(gColor color)
    {
        CCI_BOOL_CPP(clear(color));
    }



    bool WndMgr::drawCanvas(int x, int y, CnvId canvasId)
    {
        Canvas* canvas = CnvMgrHelper::get(canvasId);

        CCI_BOOL_CPP(drawCanvas(x, y, canvas));
    }

    bool WndMgr::drawSprite(int x, int y, SriId spriteId)
    {
        Sprite* sprite = SriMgrHelper::get(spriteId);

        CCI_BOOL_CPP(drawSprite(x, y, sprite));
    }



    bool WndMgr::drawBorderSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawBorderSquare(x, y, side));
    }

    bool WndMgr::drawFillSquare(int x, int y, int side)
    {
        CCI_BOOL_CPP(drawFillSquare(x, y, side));
    }



    bool WndMgr::drawBorderRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderRectangle(x, y, width, height));
    }

    bool WndMgr::drawFillRectangle(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillRectangle(x, y, width, height));
    }



    bool WndMgr::drawBorderCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawBorderCircle(x, y, radius));
    }

    bool WndMgr::drawFillCircle(int x, int y, int radius)
    {
        CCI_BOOL_CPP(drawFillCircle(x, y, radius));
    }



    bool WndMgr::drawBorderEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawBorderEllipse(x, y, width, height));
    }

    bool WndMgr::drawFillEllipse(int x, int y, int width, int height)
    {
        CCI_BOOL_CPP(drawFillEllipse(x, y, width, height));
    }



    bool WndMgr::drawImage(int x, int y, const gImage& image)
    {
        CCI_BOOL_CPP(drawImage(x, y, image));
    }

    bool WndMgr::drawIcon(int x, int y, const gIcon& icon)
    {
        CCI_BOOL_CPP(drawIcon(x, y, icon));
    }
}

#endif // __cplusplus
