/* colors.h -- colors helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __COLORS_H__
#define __COLORS_H__

#include <libdragon.h>

typedef enum
{
    COLOR_CELL_EMPTY_BG,
    COLOR_CELL_2_BG,
    COLOR_CELL_4_BG,
    COLOR_CELL_8_BG,
    COLOR_CELL_16_BG,
    COLOR_CELL_32_BG,
    COLOR_CELL_64_BG,
    COLOR_CELL_128_BG,
    COLOR_CELL_256_BG,
    COLOR_CELL_512_BG,
    COLOR_CELL_1024_BG,
    COLOR_CELL_2048_BG,
    COLOR_CELL_MORE_BG,
    COLOR_BG,
    COLOR_FONT,
    COLOR_GRID_BG,
    COLOR_BLACK,
    COLOR_WHITE,
} colors_name_t;

void colors_init();

#endif //__COLORS_H__
