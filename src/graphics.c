/* graphics.c -- graphics helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <stdarg.h>
#include <string.h>
#include <malloc.h>

#include "colors.h"
#include "graphics.h"

void graphics_draw_textf_with_background(display_context_t disp, int x, int y, const char *const format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    int size = vsprintf(buffer, format, args);
    va_end(args);

    graphics_draw_box(disp, x, y, size * 8 + 1, 9, graphics_make_color(0, 0, 0, 0xff));
    graphics_draw_text(disp, x + 1, y + 1, buffer);
}

void graphics_draw_text_center(display_context_t disp, int x, int y, const char *const msg)
{
    graphics_draw_text(disp, x - strlen(msg) * 6 / 2, y, msg);
}

int graphics_draw_int_with_font(display_context_t disp, int x, int y, sprite_t *font, int n)
{
    if (n >= 10)
        x = graphics_draw_int_with_font(disp, x, y, font, n / 10);

    graphics_draw_sprite_trans_stride(disp, x, y, font, n % 10);
    return x + 11;
}
