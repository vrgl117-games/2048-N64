/* game.h -- game header
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __GAME_H__
#define __GAME_H__

#include <libdragon.h>

#include "controls.h"

#define POP 4
#define MERGE 9

typedef struct game
{
    int cells[16];

    uint16_t score;
    uint16_t best;

    char score_str[8];
    char best_str[8];

    bool won;

    uint8_t rumble;
} game_t;

typedef enum status
{
    game_none,
    game_over,
    game_win
} status_t;

const char *game_best();
void game_draw(display_context_t disp, int grid_x, int grid_y);
void game_init();
status_t game_play(control_t keys);
void game_random();
void game_reset();
const char *game_score();
void game_set_best(uint16_t best);
void game_set_score(uint16_t score);
bool game_stop_rumble();

#endif //__GAME_H__
