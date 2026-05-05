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

    gKEYS modifiers = gKEYS_NONE;
    gKEYS key = gKEYS_NONE;

    while (window_isOpen(window) && loop)
    {
        bool keyDown = window_consumeKeyDown(window, &modifiers, &key);

        if (keyDown)
        {
            printf("Modifiers : %d\n", modifiers);
            printf("Key       : %d\n", key);
            printf("\n");

            if (modifiers == gKEYS_CONTROL && key == gKEYS_Q)
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
