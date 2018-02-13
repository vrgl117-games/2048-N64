/* rdp.c -- rpd helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>
#include <math.h>

#include "rdp.h"

void rdp_attach(display_context_t disp)
{
    rdp_attach_display(disp);
    rdp_sync(SYNC_PIPE);
    rdp_set_clipping(0, 0, 640, 480);
}

void rdp_draw_filled_rectangle_size(int x, int y, int width, int height, uint32_t color)
{
    rdp_enable_primitive_fill();
    rdp_set_fill_color((color & 0xFF000000) >> 24, (color & 0x00FF0000) >> 16, (color & 0x0000FF00) >> 8, 0x55);
    rdp_draw_filled_rectangle(x, y, x + width, y + height);
}

void rdp_draw_filled_rectangle_with_border_size(int x, int y, int width, int height, uint32_t color, uint32_t border_color)
{
    rdp_enable_primitive_fill();
    rdp_set_fill_color((border_color & 0xFF000000) >> 24, (border_color & 0x00FF0000) >> 16, (border_color & 0x0000FF00) >> 8, (border_color & 0x000000FF));
    rdp_draw_filled_rectangle(x, y, x + width, y + height);
    rdp_set_fill_color((color & 0xFF000000) >> 24, (color & 0x00FF0000) >> 16, (color & 0x0000FF00) >> 8, (color & 0x000000FF));
    rdp_draw_filled_rectangle(x + 2, y + 2, x + width - 2, y + height - 2);
}
