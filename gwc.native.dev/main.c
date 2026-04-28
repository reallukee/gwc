//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

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

    while (window_isOpen(window) && loop)
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
