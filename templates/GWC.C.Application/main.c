// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.h>

#include <conio.h>

#include <stdlib.h>

int main(int argc, const char* argv[])
{
    printf("Welcome in $projectname$!\n");
    printf("Using $gwc_identifier$ $gwc_version$!\n");
    printf("\n");

    render_setRefreshRate(60);
    render_setDutyCycle(80);

    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        return 1;
    }

    COLOR* fillColor = color_new(100, 0, 255, 0);
    COLOR* bordercolor = color_new(100, 0, 128, 0);

    window_setFillColor(window, fillColor);
    window_setBorderColor(window, bordercolor);

    color_delete(fillColor);
    color_delete(bordercolor);

    if (window_isOpen(window))
    {
        window_drawFillRectangle(window, 50, 50, 100, 100);
        window_drawBorderRectangle(window, 50, 50, 100, 100);

        printf("Press any key to exit...\n");

        _getch();

        window_shutdown(window);
    }
    else
    {
        printf("Oh :(\n");
    }

    window_delete(window);

    return 0;
}
