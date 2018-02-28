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

// enable palette (tlut)
#define EN_TLUT 0x00800000000000
// enable atomic prim, 1st primitive bandwitdh save
#define ATOMIC_PRIM 0x80000000000000
// enable perspective correction
#define PERSP_TEX_EN 0x08000000000000
// select alpha dither
#define ALPHA_DITHER_SEL_PATTERN 0x00000000000000
#define ALPHA_DITHER_SEL_PATTERNB 0x00001000000000
#define ALPHA_DITHER_SEL_NOISE 0x00002000000000
#define ALPHA_DITHER_SEL_NO_DITHER 0x00003000000000
// select rgb dither
#define RGB_DITHER_SEL_MAGIC_SQUARE_MATRIX 0x00000000000000
#define RGB_DITHER_SEL_STANDARD_BAYER_MATRIX 0x00004000000000
#define RGB_DITHER_SEL_NOISE 0x00008000000000
#define RGB_DITHER_SEL_NO_DITHER 0x0000C000000000
// enable texture filtering
#define SAMPLE_TYPE 0x00200000000000

void rdp_attach(display_context_t disp);
int rdp_draw_int_map(int x, int y, map_t *font, int n, int flags);
void rdp_draw_filled_fullscreen(uint32_t color);
void rdp_draw_filled_rectangle_size(int x, int y, int width, int height, uint32_t color);
void rdp_draw_filled_rectangle_with_border_size(int x, int y, int width, int height, uint32_t color, uint32_t border_color);
void rdp_draw_sprite_with_texture(sprite_t *sp, int x, int y, int flags);
void rdp_draw_sprite_with_texture_map(map_t *map, int x, int y, int flags);
void rdp_enable_texture_copy();

#endif //__RDP_H__