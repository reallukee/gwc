//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

/*

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop(WINDOW* window);

int main(int argc, const char* argv[])
{
    render_init();

    WINDOW* window = window_new(800, 600);

    window_open(window);

    if (!window_isInitialized(window))
    {
        window_delete(window);

        render_shutdown();

        return EXIT_FAILURE;
    }

    loop(window);

    if (window_isOpen(window))
    {
        window_close(window);
    }

    window_delete(window);

    render_shutdown();

    return EXIT_SUCCESS;
}

void loop(WINDOW* window)
{
    bool loop = true;

    while (window_isOpen(window) && loop)
    {
        gKEYS modifiers = gKEYS_NONE;
        gKEYS key = gKEYS_NONE;

        bool keyDown = window_consumeKeyDown(window, &modifiers, &key);

        if (keyDown)
        {
            if (key == gKEYS_ESCAPE)
            {
                loop = false;

                continue;
            }
        }

        bool exit = window_isKeyDownInBuffer(window, gKEYS_NONE, gKEYS_ESCAPE);

        if (exit)
        {
            loop = false;

            continue;
        }

        window_wait(window, 16);
    }
}

*/
