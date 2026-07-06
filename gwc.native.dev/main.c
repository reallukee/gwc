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

int loop(WINDOW* window);

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

    int result = loop(window);

    if (window_isOpen(window))
    {
        window_close(window);
    }

    window_delete(window);

    render_shutdown();

    return result == EXIT_FAILURE ? result : EXIT_SUCCESS;
}

int x = 0;
int y = 0;
int vx = 15;
int vy = 10;
int r = 50;

void update()
{
    x = x + vx;
    y = y + vy;

    if (x < 0)
    {
        x = 0;
        vx = -vx;
    }

    if (x + 2 * r > 800)
    {
        x = 800 - 2 * r;
        vx = -vx;
    }

    if (y < 0)
    {
        y = 0;
        vy = -vy;
    }

    if (y + 2 * r > 600)
    {
        y = 600 - 2 * r;
        vy = -vy;
    }
}

float cr = 255;
float cg = 0;
float cb = 0;

float cvr = 1.2f;
float cvg = 0.8f;
float cvb = 1.6f;

void render(CANVAS* canvas, WINDOW* window)
{
    gCOLOR* color = NULL;

    color = color_new(255, 0, 0, 0);
    canvas_clear(canvas, color);
    color_delete(color);

    cr += cvr;
    cg += cvg;
    cb += cvb;

    if (cr > 255 || cr < 0)
    {
        cvr = -cvr;
    }

    if (cg > 255 || cg < 0)
    {
        cvg = -cvg;
    }

    if (cb > 255 || cb < 0)
    {
        cvb = -cvb;
    }

    if (cr < 0) cr = 0; if (cr > 255) cr = 255;
    if (cg < 0) cg = 0; if (cg > 255) cg = 255;
    if (cb < 0) cb = 0; if (cb > 255) cb = 255;

    color = color_new(255, (int)cr, (int)cg, (int)cb);
    canvas_setFillColor(canvas, color);
    color_delete(color);
    color = color_new(255, (int)cr, (int)cg, (int)cb);
    canvas_setBorderColor(canvas, color);
    color_delete(color);

    canvas_drawFillCircle(canvas, r, r, r);

    canvas_render(canvas);

    color = color_new(255, 0, 0, 0);
    window_clear(window, color);
    color_delete(color);

    window_drawCanvas(window, x, y, canvas);
}

int loop(WINDOW* window)
{
    CANVAS* canvas = canvas_new(r * 2, r * 2);

    if (!canvas_isInitialized(canvas))
    {
        canvas_delete(canvas);

        return EXIT_FAILURE;
    }

    bool loop = true;

    while (window_isOpen(window) && loop)
    {
        gKEYS modifiers = gKEYS_NONE;
        gKEYS key = gKEYS_NONE;

        bool keyDown = window_consumeKeyDown(
            window,
            &modifiers,
            &key
        );

        if (keyDown)
        {
            if (key == gKEYS_ESCAPE)
            {
                loop = false;

                continue;
            }
        }

        bool exit = window_isKeyDownInBuffer(
            window,
            gKEYS_NONE,
            gKEYS_ESCAPE
        );

        if (exit)
        {
            loop = false;

            continue;
        }

        update();

        render(canvas, window);

        window_wait(window, 16);
    }

    canvas_delete(canvas);

    return EXIT_SUCCESS;
}

*/
