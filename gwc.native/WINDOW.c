/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : WINDOW.c
 *
 * Titolo    : WINDOW
 * Sommario  : Window
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#include "gwc.clr.hpp"

#include "WINDOW.h"
#include "macros.h"

#include "ICONHELPER.h"
#include "IMAGEHELPER.h"

#include "SPRITEHELPER.h"
#include "CANVASHELPER.h"

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

bool window_isKeyUpAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyUpAvailable);
}

void window_flushKeyDown(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushKeyDown());
}

void window_flushKeyUp(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushKeyUp());
}

bool window_consumeKeyDown(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_BOOL_C(WindowHost, window);

    if (key == NULL)
    {
        return false;
    }

    System::Windows::Forms::Keys managedModifiers;
    System::Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyDown(
        managedModifiers, managedKey
    );

    int rawModifiers = static_cast<int>(managedModifiers);
    int rawKey       = static_cast<int>(managedKey);

    *modifiers = static_cast<gKEYS>(rawModifiers);
    *key       = static_cast<gKEYS>(rawKey);

    return result;
}

bool window_consumeKeyUp(const WINDOW* window, gKEYS* modifiers, gKEYS* key)
{
    CC_BOOL_C(WindowHost, window);

    if (key == NULL)
    {
        return false;
    }

    System::Windows::Forms::Keys managedModifiers;
    System::Windows::Forms::Keys managedKey;

    bool result = _host->invoke()->ConsumeKeyUp(
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

bool window_discardKeyUp(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardKeyUp());
}

bool window_isKeyDownInBuffer(const WINDOW* window, gKEYS modifiers, gKEYS key)
{
    CC_BOOL_C(WindowHost, window);

    System::Windows::Forms::Keys managedModifiers;
    System::Windows::Forms::Keys managedKey;

    managedModifiers = safe_cast<System::Windows::Forms::Keys>(modifiers);
    managedKey       = safe_cast<System::Windows::Forms::Keys>(key);

    return _host->invoke()->IsKeyDownInBuffer(
        managedModifiers, managedKey
    );
}

bool window_isKeyUpInBuffer(const WINDOW* window, gKEYS modifiers, gKEYS key)
{
    CC_BOOL_C(WindowHost, window);

    System::Windows::Forms::Keys managedModifiers;
    System::Windows::Forms::Keys managedKey;

    managedModifiers = safe_cast<System::Windows::Forms::Keys>(modifiers);
    managedKey       = safe_cast<System::Windows::Forms::Keys>(key);

    return _host->invoke()->IsKeyUpInBuffer(
        managedModifiers, managedKey
    );
}

bool window_isKeyDownLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyDownLost);
}

bool window_isKeyUpLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsKeyUpLost);
}

int window_keyDownBufferLength(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, KeyDownBufferLength);
}

int window_keyUpBufferLength(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, KeyUpBufferLength);
}



bool window_isMouseDownAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseDownAvailable);
}

bool window_isMouseUpAvailable(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseUpAvailable);
}

void window_flushMouseDown(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushMouseDown());
}

void window_flushMouseUp(const WINDOW* window)
{
    CCI_VOID_C(WindowHost, window, FlushMouseUp());
}

bool window_consumeMouseDown(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_BOOL_C(WindowHost, window);

    System::Drawing::Point               managedLocation;
    System::Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseDown(
        managedLocation, managedButton
    );

    int rawButton = static_cast<int>(managedButton);

    *location = point_new(managedLocation.X, managedLocation.Y);
    *button   = static_cast<gMOUSEBUTTONS>(rawButton);

    return result;
}

bool window_consumeMouseUp(const WINDOW* window, gPOINT** location, gMOUSEBUTTONS* button)
{
    CC_BOOL_C(WindowHost, window);

    System::Drawing::Point               managedLocation;
    System::Windows::Forms::MouseButtons managedButton;

    bool result = _host->invoke()->ConsumeMouseUp(
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

bool window_discardMouseUp(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, DiscardMouseUp());
}

bool window_isMouseDownInBuffer(const WINDOW* window, gPOINT* location, gMOUSEBUTTONS button)
{
    CC_BOOL_C(WindowHost, window);

    System::Drawing::Point               managedLocation;
    System::Windows::Forms::MouseButtons managedButton;

    managedLocation = System::Drawing::Point(point_getX(location), point_getY(location));
    managedButton   = safe_cast<System::Windows::Forms::MouseButtons>(button);

    return _host->invoke()->IsMouseDownInBuffer(
        managedLocation, managedButton
    );
}

bool window_isMouseUpInBuffer(const WINDOW* window, gPOINT* location, gMOUSEBUTTONS button)
{
    CC_BOOL_C(WindowHost, window);

    System::Drawing::Point               managedLocation;
    System::Windows::Forms::MouseButtons managedButton;

    managedLocation = System::Drawing::Point(point_getX(location), point_getY(location));
    managedButton   = safe_cast<System::Windows::Forms::MouseButtons>(button);

    return _host->invoke()->IsMouseUpInBuffer(
        managedLocation, managedButton
    );
}

bool window_isMouseDownLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseDownLost);
}

bool window_isMouseUpLost(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, IsMouseUpLost);
}

int window_mouseDownBufferLength(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, MouseDownBufferLength);
}

int window_mouseUpBufferLength(const WINDOW* window)
{
    CCI_INT_C(WindowHost, window, MouseUpBufferLength);
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

gCOLOR* window_getBackColor(const WINDOW* window)
{
    CCI_GET_COLOR_C(WindowHost, window, BackColor);
}

void window_setBackColor(const WINDOW* window, const gCOLOR* color)
{
    CCI_SET_COLOR_C(WindowHost, window, BackColor, color);
}



bool window_clear(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, Clear());
}

bool window_clearArea(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, ClearArea(x, y, width, height));
}

bool window_clearF(const WINDOW* window)
{
    CCI_BOOL_C(WindowHost, window, ClearF());
}

bool window_clearAreaF(const WINDOW* window, float x, float y, float width, float height)
{
    CCI_BOOL_C(WindowHost, window, ClearAreaF(x, y, width, height));
}



bool window_drawCanvas(const WINDOW* window, int x, int y, const CANVAS* canvas)
{
    CanvasHost* canvasHost = canvasHelper_get(canvas);

    GWC::Canvas^ managedCanvas = canvasHost->invoke();

    CCI_BOOL_C(WindowHost, window, DrawCanvas(x, y, managedCanvas));
}

bool window_drawCanvasF(const WINDOW* window, float x, float y, const CANVAS* canvas)
{
    CanvasHost* canvasHost = canvasHelper_get(canvas);

    GWC::Canvas^ managedCanvas = canvasHost->invoke();

    CCI_BOOL_C(WindowHost, window, DrawCanvasF(x, y, managedCanvas));
}



bool window_drawSprite(const WINDOW* window, int x, int y, const SPRITE* sprite)
{
    SpriteHost* spriteHost = spriteHelper_get(sprite);

    GWC::Sprite^ managedSprite = spriteHost->invoke();

    CCI_BOOL_C(WindowHost, window, DrawSprite(x, y, managedSprite));
}

bool window_drawSpriteF(const WINDOW* window, float x, float y, const SPRITE* sprite)
{
    SpriteHost* spriteHost = spriteHelper_get(sprite);

    GWC::Sprite^ managedSprite = spriteHost->invoke();

    CCI_BOOL_C(WindowHost, window, DrawSpriteF(x, y, managedSprite));
}



bool window_drawBorderSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderSquare(x, y, side));
}

bool window_drawBorderSquareF(const WINDOW* window, float x, float y, float side)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderSquareF(x, y, side));
}

bool window_drawFillSquare(const WINDOW* window, int x, int y, int side)
{
    CCI_BOOL_C(WindowHost, window, DrawFillSquare(x, y, side));
}

bool window_drawFillSquareF(const WINDOW* window, float x, float y, float side)
{
    CCI_BOOL_C(WindowHost, window, DrawFillSquareF(x, y, side));
}



bool window_drawBorderRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderRectangle(x, y, width, height));
}

bool window_drawBorderRectangleF(const WINDOW* window, float x, float y, float width, float height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderRectangleF(x, y, width, height));
}

bool window_drawFillRectangle(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillRectangle(x, y, width, height));
}

bool window_drawFillRectangleF(const WINDOW* window, float x, float y, float width, float height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillRectangleF(x, y, width, height));
}



bool window_drawBorderCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderCircle(x, y, radius));
}

bool window_drawBorderCircleF(const WINDOW* window, float x, float y, float radius)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderCircleF(x, y, radius));
}

bool window_drawFillCircle(const WINDOW* window, int x, int y, int radius)
{
    CCI_BOOL_C(WindowHost, window, DrawFillCircle(x, y, radius));
}

bool window_drawFillCircleF(const WINDOW* window, float x, float y, float radius)
{
    CCI_BOOL_C(WindowHost, window, DrawFillCircleF(x, y, radius));
}



bool window_drawBorderEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderEllipse(x, y, width, height));
}

bool window_drawBorderEllipseF(const WINDOW* window, float x, float y, float width, float height)
{
    CCI_BOOL_C(WindowHost, window, DrawBorderEllipseF(x, y, width, height));
}

bool window_drawFillEllipse(const WINDOW* window, int x, int y, int width, int height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillEllipse(x, y, width, height));
}

bool window_drawFillEllipseF(const WINDOW* window, float x, float y, float width, float height)
{
    CCI_BOOL_C(WindowHost, window, DrawFillEllipseF(x, y, width, height));
}



static System::Drawing::Bitmap^ toManagedBitmap(Gdiplus::Bitmap* nativeBitmap)
{
    if (!nativeBitmap)
    {
        return nullptr;
    }

    UINT width  = nativeBitmap->GetWidth();
    UINT height = nativeBitmap->GetHeight();

    Gdiplus::Rect nativeRect(
        0,
        0,
        width,
        height
    );

    Gdiplus::BitmapData nativeBitmapData;

    bool result = nativeBitmap->LockBits(
        &nativeRect,
        Gdiplus::ImageLockModeRead,
        PixelFormat32bppPARGB,
        &nativeBitmapData
    );

    if (result != Gdiplus::Status::Ok)
    {
        return nullptr;
    }

    System::Drawing::Bitmap^ managedBitmap = nullptr;

    try
    {
        managedBitmap = gcnew System::Drawing::Bitmap(
            width,
            height,
            nativeBitmapData.Stride,
            System::Drawing::Imaging::PixelFormat::Format32bppPArgb,
            (IntPtr)nativeBitmapData.Scan0
        );

        System::Drawing::Rectangle managedRectangle(
            0,
            0,
            width,
            height
        );

        System::Drawing::Bitmap^ copy = managedBitmap->Clone(
            managedRectangle,
            System::Drawing::Imaging::PixelFormat::Format32bppPArgb
        );

        delete managedBitmap;

        managedBitmap = copy;
    }
    finally
    {
        nativeBitmap->UnlockBits(&nativeBitmapData);
    }

    return managedBitmap;
}

static Bitmap* getNativeImage(const gIMAGE* image)
{
    if (!image_isLoaded(image))
    {
        return false;
    }

    Bitmap* nativeImage = imageHelper_get(image);

    if (nativeImage == nullptr)
    {
        return false;
    }

    return nativeImage;
}

static HICON getNativeIcon(const gICON* icon)
{
    if (!icon_isLoaded(icon))
    {
        return false;
    }

    HICON nativeIcon = iconHelper_get(icon);

    if (nativeIcon == nullptr)
    {
        return false;
    }

    return nativeIcon;
}



bool window_drawImage(const WINDOW* window, int x, int y, gIMAGE* image)
{
    CC_BOOL_C(WindowHost, window);

    Bitmap* nativeImage = getNativeImage(image);

    System::Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        managedImage = toManagedBitmap(nativeImage);

        result = _host->invoke()->DrawImage(x, y, managedImage);
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

bool window_drawImageF(const WINDOW* window, float x, float y, gIMAGE* image)
{
    CC_BOOL_C(WindowHost, window);

    Bitmap* nativeImage = getNativeImage(image);

    System::Drawing::Image^ managedImage = nullptr;

    bool result = false;

    try
    {
        managedImage = toManagedBitmap(nativeImage);

        result = _host->invoke()->DrawImageF(x, y, managedImage);
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

    HICON nativeIcon = getNativeIcon(icon);

    System::Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = System::Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIcon(x, y, managedIcon);
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

bool window_drawIconF(const WINDOW* window, float x, float y, gICON* icon)
{
    CC_BOOL_C(WindowHost, window);

    HICON nativeIcon = getNativeIcon(icon);

    System::Drawing::Icon^ managedIcon = nullptr;

    bool result = false;

    try
    {
        IntPtr iconHandle = IntPtr(nativeIcon);

        managedIcon = System::Drawing::Icon::FromHandle(iconHandle);

        result = _host->invoke()->DrawIconF(x, y, managedIcon);
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
