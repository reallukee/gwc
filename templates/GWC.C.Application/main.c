// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.h>

#include <stdlib.h>

int main(int argc, const char* argv[])
{
    printf("Welcome in $projectname$!\n");
    printf("Using GWC v%s\n", GWC_VERSION);
    printf("\n");

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

            printf("Pressed: %d\n", key);

            COLOR* fillColor   = color_new(100, 0, 255, 0);
            COLOR* bordercolor = color_new(100, 0, 128, 0);

            window_setFillColor(window, fillColor);
            window_setBorderColor(window, bordercolor);

            color_delete(fillColor);
            color_delete(bordercolor);

            window_drawFillRectangle(window, 50, 50, 100, 100);
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
