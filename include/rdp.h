/* rdp.h -- rdp helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __RDP_H__
#define __RDP_H__

#include <libdragon.h>

#include "dfs.h"

void rdp_attach(display_context_t disp);
int rdp_draw_int_map(int x, int y, map_t *font, int n);
void rdp_draw_filled_fullscreen(uint32_t color);
void rdp_draw_filled_rectangle_size(int x, int y, int width, int height, uint32_t color);
void rdp_draw_filled_rectangle_with_border_size(int x, int y, int width, int height, uint32_t color, uint32_t border_color);
void rdp_draw_sprite_with_texture(sprite_t *sp, int x, int y);
void rdp_draw_sprite_with_texture_map(map_t *map, int x, int y);

#endif //__RDP_H__
