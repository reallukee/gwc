// C.Draw
//  GWC.Native >=0.5.0

#include <stdio.h>

#include <gwc.h>

int main(int argc, const char* argv[])
{
    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        return 1;
    }

    gCOLOR* fillColor1 = color_new(255, 255, 255, 0);
    window_setFillColor(window, fillColor1);
    window_drawFillSquare(window, 100, 100, 100);
    color_delete(fillColor1);

    gCOLOR* fillColor2 = color_new(255, 255, 0, 128);
    window_setFillColor(window, fillColor2);
    window_drawFillCircle(window, 150, 150, 50);
    color_delete(fillColor2);

    gIMAGE* image = image_new("gwc.bmp");
    window_drawImage(window, 100, 300, image);
    image_delete(image);

    gICON* icon = icon_new("gwc.ico");
    window_drawIcon(window, 200, 300, icon);
    icon_delete(icon);

    while (window_isOpen(window) && !window_isKeyDownAvailable(window))
    {
        window_wait(window, 16);
    }

    if (window_isOpen(window))
    {
        window_close(window);
    }

    window_delete(window);

    return 0;
}
