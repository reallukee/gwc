// C.MultiWindow
//  GWC.Native >=0.4.0

#include <stdio.h>

#include <gwc.h>

#include <conio.h>

int main(int argc, const char* argv[])
{
    WINDOW* window_1 = window_new(800, 600);
    WINDOW* window_2 = window_new(800, 600);
    WINDOW* window_3 = window_new(800, 600);

    window_open(window_1);
    window_open(window_2);
    window_open(window_3);

    if (!window_isInitialized(window_1) ||
        !window_isInitialized(window_2) ||
        !window_isInitialized(window_3))
    {
        window_delete(window_1);
        window_delete(window_2);
        window_delete(window_3);

        return 1;
    }

    _getch();

    window_close(window_1);
    window_close(window_2);
    window_close(window_3);

    window_delete(window_1);
    window_delete(window_2);
    window_delete(window_3);

    exit(0);

    return 0;
}
