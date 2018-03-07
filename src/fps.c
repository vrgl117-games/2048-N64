/* fps.c -- fps helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "fps.h"
#include "graphics.h"

static volatile bool fps_refresh = false;
static volatile uint8_t fps;
static bool show = false;

void fps_check(control_t keys)
{
    if (keys.L && keys.R)
        show = !show;
}
void fps_draw(display_context_t disp)
{
    if (show)
        graphics_draw_textf_with_background(disp, 4, 4, "FPS: %d", fps);
}

inline void fps_frame()
{
    static uint8_t frame_count = 0;

    frame_count++;
    if (fps_refresh)
    {
        fps = frame_count;
        frame_count = 0;
        fps_refresh = false;
    }
}

void fps_timer()
{
    fps_refresh = true;
}
