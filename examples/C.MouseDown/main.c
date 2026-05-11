// C.KeyDown
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

    bool loop = true;

    gPOINT* location;
    gMOUSEBUTTONS button = gMOUSEBUTTONS_NONE;

    while (window_isOpen(window) && loop)
    {
        bool mouseDown = window_consumeMouseDown(window, &location, &button);

        if (mouseDown)
        {
            int x = point_getX(location);
            int y = point_getY(location);

            printf("Location : %d, %d\n", x, y);
            printf("Button   : %d\n", button);
            printf("\n");

            if (button== gMOUSEBUTTONS_MIDDLE)
            {
                loop = false;
            }
        }

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
