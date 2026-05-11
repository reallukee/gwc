//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
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
int main(int argc, const char* argv[])
{
    render_init();
    wndmgr_init();

    wndmgr_alloc(800, 600, true);

    wndmgr_open();

    if (!wndmgr_isInitialized())
    {
        render_shutdown();
        wndmgr_shutdown();

        return 1;
    }

    bool loop = true;

    while (wndmgr_isOpen() && loop)
    {
        wndmgr_wait(100);
    }

    if (wndmgr_isOpen())
    {
        wndmgr_close();
    }

    render_shutdown();
    wndmgr_shutdown();

    exit(0);

    return 0;
}
*/
