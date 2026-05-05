// C.Draw
//  GWC.Native >=0.4.0

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

    gCOLOR* fillColor1 = color_new(100, 255, 255, 0);
    window_setFillColor(window, fillColor1);
    window_drawFillSquare(window, 100, 100, 100);
    color_delete(fillColor1);

    gCOLOR* fillColor2 = color_new(100, 255, 255, 0);
    window_setFillColor(window, fillColor2);
    window_drawFillCircle(window, 150, 150, 50);
    color_delete(fillColor2);

    while (window_isOpen(window) && !window_isKeyDownAvailable(window))
    {
        window_wait(window, 100);
    }

    if (window_isOpen(window))
    {
        window_close(window);
    }

    window_delete(window);

    exit(0);

    return 0;
}
