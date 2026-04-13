// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

Color* generateRandomColor();

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
        Keys modifiers = KEYS_NONE;
        Keys key = KEYS_NONE;

        bool keyDown = window_consumeKeyDown(window, &modifiers, &key);

        if (keyDown)
        {
            if (key == KEYS_ESCAPE)
            {
                loop = false;

                continue;
            }

            printf("Pressed: %d, %d\n", modifiers, key);

            Color* bordercolor = generateRandomColor();
            Color* fillColor = generateRandomColor();

            window_setBorderColor(window, bordercolor);
            window_setFillColor(window, fillColor);

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

Color* generateRandomColor()
{
    srand((unsigned int)time(NULL));

    int alpha = rand() % 100 + 1;
    int red   = rand() % 255 + 1;
    int blue  = rand() % 255 + 1;
    int green = rand() % 255 + 1;

    Color* color = color_new(alpha, red, green, blue);

    return color;
}
