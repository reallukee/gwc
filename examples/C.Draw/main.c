// C.Draw
//  GWC.Native >=0.3.0

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

    Color* fillColor = NULL;

    fillColor = color_new(100, 255, 255, 0);
    window_setFillColor(window, fillColor);
    window_drawFillSquare(window, 100, 100, 100);
    color_delete(fillColor);

    fillColor = color_new(100, 255, 0, 128);
    window_setFillColor(window, fillColor);
    window_drawFillCircle(window, 150, 150, 50);
    color_delete(fillColor);

    while (window_isOpen(window) && !window_isKeyDownAvailable(window))
    {
        window_wait(window, 100);
    }

    if (window_isOpen(window))
    {
        window_shutdown(window);
    }

    window_delete(window);

    exit(0);

    return 0;
}
