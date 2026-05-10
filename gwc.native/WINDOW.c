//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WINDOW.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "WINDOW.h"
#include "macros.h"

typedef struct WINDOW {
    CLRWindowHost window;
} WINDOW;



WINDOW* window_new(int width, int height)
{
    WINDOW* window = (WINDOW*)calloc(1, sizeof(WINDOW));

    if (window == NULL)
    {
        return NULL;
    }

    WindowHost* host = new WindowHost(width, height);

    window->window = static_cast<CLRWindowHost>(host);

    return window;
}

void window_delete(WINDOW* window)
{
    if (window == NULL)
    {
        return;
    }

    WindowHost* host = static_cast<WindowHost*>(window->window);

    delete host;

    free(window);
}



bool window_isInitialized(const WINDOW* window)
{
    if (window == NULL)
    {
        return false;
    }

    WindowHost* host = static_cast<WindowHost*>(window->window);

    if (host == NULL)
    {
        return false;
    }

    return !host->isNull();
}



bool window_open(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Open());
}

bool window_close(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Close());
}



bool window_isOpen(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsOpen);
}

bool window_isClose(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsClose);
}



bool window_suspend(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Suspend());
}

bool window_resume(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Resume());
}



bool window_isSuspend(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsSuspend);
}

bool window_isResume(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsResume);
}



void window_wait(const WINDOW* window, int milliseconds)
{
    CCI_VOID_C(WindowHost, window, Wait(milliseconds));
}

void window_skip(const WINDOW* window, int frames)
{
    CCI_VOID_C(WindowHost, window, Skip(frames));
}



bool window_show(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Show());
}

bool window_hide(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Hide());
}



int window_getWindowWidth(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, WindowWidth);
}

int window_getWindowHeight(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, WindowHeight);
}

int window_getRenderWidth(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, RenderWidth);
}

int window_getRenderHeight(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, RenderHeight);
}



bool window_isKeyDownAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyDownAvailable);
}

void window_flushKeyDown(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushKeyDown());
}

bool window_consumeKeyDown(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_BOOL_C(WindowHost, window);

    if (key == NULL)
    {
        return false;
    }

    Windows::Forms::Keys managedModifiers;
    Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyDown(
        managedModifiers, managedKey
    );

    int rawModifiers = static_cast<int>(managedModifiers);
    int rawKey       = static_cast<int>(managedKey);

    *modifiers = static_cast<gKEYS>(rawModifiers);
    *key       = static_cast<gKEYS>(rawKey);

    return result;
}

bool window_discardKeyDown(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardKeyDown());
}

bool window_isKeyDownLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyDownLost);
}

bool window_isKeyDownBufferFull(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyDownBufferFull);
}



bool window_isKeyUpAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyUpAvailable);
}

void window_flushKeyUp(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushKeyUp());
}

bool window_consumeKeyUp(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_BOOL_C(WindowHost, window);

    if (key == NULL)
    {
        return false;
    }

    Windows::Forms::Keys managedModifiers;
    Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyUp(
        managedModifiers, managedKey
    );

    int rawModifiers = static_cast<int>(managedModifiers);
    int rawKey       = static_cast<int>(managedKey);

    *modifiers = static_cast<gKEYS>(rawModifiers);
    *key       = static_cast<gKEYS>(rawKey);

    return result;
}

bool window_discardKeyUp(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardKeyUp());
}

bool window_isKeyUpLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyUpLost);
}

bool window_isKeyUpBufferFull(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyUpBufferFull);
}



bool window_isMouseDownAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseDownAvailable);
}

void window_flushMouseDown(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushMouseDown());
}

bool window_consumeMouseDown(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_BOOL_C(WindowHost, window);

    Drawing::Point               managedLocation;
    Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseDown(
        managedLocation, managedButton
    );

    int rawButton = static_cast<int>(managedButton);

    *location = point_new(managedLocation.X, managedLocation.Y);
    *button   = static_cast<gMOUSEBUTTONS>(rawButton);

    return result;
}

bool window_discardMouseDown(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardMouseDown());
}

bool window_isMouseDownLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseDownLost);
}

bool window_isMouseDownBufferFull(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseDownBufferFull);
}



bool window_isMouseUpAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseUpAvailable);
}

void window_flushMouseUp(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushMouseUp());
}

bool window_consumeMouseUp(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_BOOL_C(WindowHost, window);

    Drawing::Point               managedLocation;
    Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseUp(
        managedLocation, managedButton
    );

    int rawButton = static_cast<int>(managedButton);

    *location = point_new(managedLocation.X, managedLocation.Y);
    *button   = static_cast<gMOUSEBUTTONS>(rawButton);

    return result;
}

bool window_discardMouseUp(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardMouseUp());
}

bool window_isMouseUpLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseUpLost);
}

bool window_isMouseUpBufferFull(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseUpBufferFull);
}



int window_getCanvasWidth(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, CanvasWidth);
}

int window_getCanvasHeight(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, CanvasHeight);
}



gCOLOR* window_getBorderColor(const WINDOW* window)
{
    CCI_GET_COLOR_C(WindowHost, window, BorderColor);
}

void window_setBorderColor(const WINDOW* window, const gCOLOR* color)
{
    CCI_SET_COLOR_C(WindowHost, window, BorderColor, color);
}

gCOLOR* window_getFillColor(const WINDOW* window)
{
    CCI_GET_COLOR_C(WindowHost, window, FillColor);
}

void window_setFillColor(const WINDOW* window, const gCOLOR* color)
{
    CCI_SET_COLOR_C(WindowHost, window, FillColor, color);
}



bool window_drawBorderSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderSquare(x, y, side));
}

bool window_drawFillSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_BOOL_C(WindowHost, window, DrawFillSquare(x, y, side));
}



bool window_drawBorderRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawFillRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillRectangle(x, y, width, height));
}



bool window_drawBorderCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderCircle(x, y, radius));
}

bool window_drawFillCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_BOOL_C(WindowHost, window, DrawFillCircle(x, y, radius));
}



bool window_drawBorderEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderEllipse(x, y, width, height));
}

bool window_drawFillEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillEllipse(x, y, width, height));
}



bool window_drawImage(const WINDOW* window, int x, int y, gIMAGE* image)
{
    CC_BOOL_C(WindowHost, window);

    if (image == NULL)
    {
        return false;
    }

    if (!image_isLoaded(image))
    {
        return false;
    }

    HBITMAP nativeImage = image_get(image);

    Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        IntPtr imageHandle = IntPtr(nativeImage);

        managedImage = Drawing::Image::FromHbitmap(imageHandle);

        result = _host->invoke()->DrawImage(x, y, managedImage);
    }
    catch (Exception^ ex)
    {
        Windows::Forms::MessageBox::Show(ex->Message);
    }
    finally
    {
        if (managedImage)
        {
            delete managedImage;
        }
    }

    return result;
}

bool window_drawIcon(const WINDOW* window, int x, int y, gICON* icon)
{
    CC_BOOL_C(WindowHost, window);

    if (icon == NULL)
    {
        return false;
    }

    if (!icon_isLoaded(icon))
    {
        return false;
    }

    HICON nativeIcon = icon_get(icon);

    Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIcon(x, y, managedIcon);
    }
    catch (Exception^ ex)
    {
        Windows::Forms::MessageBox::Show(ex->Message);
    }
    finally
    {
        if (managedIcon)
        {
            delete managedIcon;
        }
    }

    return result;
}
