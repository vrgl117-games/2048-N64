/* game.h -- game header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __GAME_H__
#define __GAME_H__

#include <libdragon.h>

#define EXTRA_FRAMES 4

typedef struct game
{
    int cells[16];

    uint16_t score;
    uint16_t best;
} game_t;

typedef enum direction { d_none,
                         d_up,
                         d_down,
                         d_left,
                         d_right } direction_t;

int game_best();
void game_init();
bool game_play(direction_t direction);
void game_draw(display_context_t disp, int grid_x, int grid_y);
int game_score();
void game_reset();

#endif //__GAME_H__