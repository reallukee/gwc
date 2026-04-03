//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

#include <stdlib.h>

/*
void showInfo(const WINDOW* window);

int main(int argc, const char* argv[])
{
    render_setDefaultRefreshRate();
    render_setDefaultDutyCycle();

    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        return 1;
    }

    bool loop = true;

    printf("Press \"ESC\" to exit...\n");

    while (window_isOpen(window) && loop)
    {
        int key = -1;

        bool keyDown = window_consumeKeyDown(window, &key);

        if (keyDown)
        {
            if (key == 27)
            {
                loop = false;

                continue;
            }

            if (key == 73)
            {
                showInfo(window);

                continue;
            }

            printf("Pressed: %d\n", key);

            COLOR* fillColor   = color_new(100, 0, 255, 0);
            COLOR* bordercolor = color_new(100, 0, 128, 0);

            window_setFillColor  (window, fillColor);
            window_setBorderColor(window, bordercolor);

            color_delete(fillColor);
            color_delete(bordercolor);

            window_drawFillRectangle  (window, 50, 50, 100, 100);
            window_drawBorderRectangle(window, 50, 50, 100, 100);
        }

        window_wait(window, 100);
    }

    if (window_isOpen(window))
    {
        window_shutdown(window);
    }

    window_delete(window);

    return 0;
}

void showInfo(WINDOW* window)
{
    printf("Window Width  : %d", window_getWindowWidth(window));
    printf("Window Height : %d", window_getCanvasHeight(window));
    printf("Render Width  : %d", window_getRenderWidth(window));
    printf("Render Height : %d", window_getRenderHeight(window));
    printf("Canvas Width  : %d", window_getCanvasWidth(window));
    printf("Canvas Height : %d", window_getCanvasHeight(window));
}
*/
