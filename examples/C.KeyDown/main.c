// C.KeyDown
//  GWC.Native >=0.3.0

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

    Keys modifiers = KEYS_NONE;
    Keys key = KEYS_NONE;

    while (window_isOpen(window) && loop)
    {
        bool keyDown = window_consumeKeyDown(window, &modifiers, &key);

        if (keyDown)
        {
            printf("Modifiers : %d\n", modifiers);
            printf("Key       : %d\n", key);
            printf("\n");

            if (modifiers == KEYS_CONTROL && key == KEYS_Q)
            {
                loop = false;
            }
        }

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
