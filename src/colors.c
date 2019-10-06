/* colors.c -- colors helpers implementation
 *
 * Copyright (C) 2019 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "colors.h"

uint32_t colors[18];

void colors_init()
{
    colors[COLOR_BG] = graphics_make_color(0xfa, 0xf8, 0xef, 0xff);
    colors[COLOR_FONT] = graphics_make_color(0x77, 0x6e, 0x65, 0xff);
    colors[COLOR_GRID_BG] = graphics_make_color(0xbb, 0xad, 0xa0, 0xff);
    colors[COLOR_CELL_EMPTY_BG] = graphics_make_color(0xCD, 0xC1, 0xB4, 0xff);
    colors[COLOR_CELL_2_BG] = graphics_make_color(0xEE, 0xE4, 0xDA, 0xff);
    colors[COLOR_CELL_4_BG] = graphics_make_color(0xED, 0xE0, 0xC8, 0xff);
    colors[COLOR_CELL_8_BG] = graphics_make_color(0xF2, 0xB1, 0x79, 0xff);
    colors[COLOR_CELL_16_BG] = graphics_make_color(0xF5, 0x95, 0x63, 0xff);
    colors[COLOR_CELL_32_BG] = graphics_make_color(0xF6, 0x7C, 0x5F, 0xff);
    colors[COLOR_CELL_64_BG] = graphics_make_color(0xF4, 0x5E, 0x43, 0xff);
    colors[COLOR_CELL_128_BG] = graphics_make_color(0xEC, 0xCE, 0x78, 0xff);
    colors[COLOR_CELL_256_BG] = graphics_make_color(0xEC, 0xCB, 0x69, 0xff);
    colors[COLOR_CELL_512_BG] = graphics_make_color(0xEC, 0xC7, 0x5A, 0xff);
    colors[COLOR_CELL_1024_BG] = graphics_make_color(0xEC, 0xC4, 0x4C, 0xff);
    colors[COLOR_CELL_2048_BG] = graphics_make_color(0xED, 0xC2, 0x2E, 0xff);
    colors[COLOR_CELL_MORE_BG] = graphics_make_color(0x3C, 0x3A, 0x33, 0xff);
    colors[COLOR_BLACK] = graphics_make_color(0x00, 0x00, 0x00, 0xff);
    colors[COLOR_WHITE] = graphics_make_color(0xff, 0xff, 0xff, 0xff);
}