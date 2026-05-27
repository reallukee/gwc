//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

#include <gwc_abst.h>

/*

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop();

int main(int argc, const char* argv[])
{
    render_init();
    wndmgr_init();

    WINDOW_ID window = wndmgr_alloc(800, 600, true);

    wndmgr_open();

    if (!wndmgr_isInitialized())
    {
        render_shutdown();
        wndmgr_shutdown();

        return EXIT_FAILURE;
    }

    loop();

    if (wndmgr_isOpen())
    {
        wndmgr_close();
    }

    render_shutdown();
    wndmgr_shutdown();

    return EXIT_SUCCESS;
}

void loop()
{
    bool loop = true;

    while (wndmgr_isOpen() && loop)
    {
        gKEYS modifiers = gKEYS_NONE;
        gKEYS key = gKEYS_NONE;

        bool keyDown = wndmgr_consumeKeyDown(&modifiers, &key);

        if (keyDown)
        {
            if (key == gKEYS_ESCAPE)
            {
                loop = false;

                continue;
            }
        }

        bool exit = wndmgr_isKeyDownInBuffer(gKEYS_NONE, gKEYS_ESCAPE);

        if (exit)
        {
            loop = false;

            continue;
        }

        wndmgr_wait(100);
    }
}

*/
