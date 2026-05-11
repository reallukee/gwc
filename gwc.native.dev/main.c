//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

/*
int main(int argc, const char* argv[])
{
    render_init();

    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        render_shutdown();

        return 1;
    }

    gIMAGE* myBitmap1 = image_new("..\\assets\\playground\\albert_the_rock.bmp");
    gIMAGE* myBitmap2 = image_new("..\\assets\\playground\\albert_the_rock_with_cacatus.bmp");
    gIMAGE* myBitmap3 = image_new("..\\assets\\playground\\albert_the_rock_nostalgia.bmp");

    window_drawImage(window, 100, 100, myBitmap1);
    window_drawImage(window, 200, 100, myBitmap2);
    window_drawImage(window, 300, 100, myBitmap3);

    image_delete(myBitmap1);
    image_delete(myBitmap2);
    image_delete(myBitmap3);

    bool loop = true;

    while (window_isOpen(window) && loop)
    {
        window_wait(window, 100);
    }

    if (window_isOpen(window))
    {
        window_close(window);
    }

    window_delete(window);

    render_shutdown();

    exit(0);

    return 0;
}
*/
