/* game.c -- game helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <stdlib.h>

#include "colors.h"
#include "dfs.h"
#include "game.h"
#include "rdp.h"

static game_t game;
static sprite_t *sprites[16];
static uint32_t colors[16];

void game_init() {

    // init sprites
    sprites[1] = dfs_load("/gfx/2.sprite");
    sprites[2] = dfs_load("/gfx/4.sprite");
    sprites[3] = dfs_load("/gfx/8.sprite");
    sprites[4] = dfs_load("/gfx/16.sprite");
    sprites[5] = dfs_load("/gfx/32.sprite");
    sprites[6] = dfs_load("/gfx/64.sprite");
    sprites[7] = dfs_load("/gfx/128.sprite");
    sprites[8] = dfs_load("/gfx/256.sprite");
    sprites[9] = dfs_load("/gfx/512.sprite");
    sprites[10] = dfs_load("/gfx/1024.sprite");
    sprites[11] = dfs_load("/gfx/2048.sprite");
    sprites[12] = dfs_load("/gfx/4096.sprite");
    sprites[13] = dfs_load("/gfx/8192.sprite");
    sprites[14] = dfs_load("/gfx/16384.sprite");
    sprites[15] = dfs_load("/gfx/32768.sprite");

     // init colors
    colors[0] = COLOR_CELL_EMPTY_BG;
    colors[1] = COLOR_CELL_2_BG;
    colors[2] = COLOR_CELL_4_BG;
    colors[3] = COLOR_CELL_8_BG;
    colors[4] = COLOR_CELL_16_BG;
    colors[5] = COLOR_CELL_32_BG;
    colors[6] = COLOR_CELL_64_BG;
    colors[7] = COLOR_CELL_128_BG;
    colors[8] = COLOR_CELL_256_BG;
    colors[9] = COLOR_CELL_512_BG;
    colors[10] = COLOR_CELL_1024_BG;
    colors[11] = COLOR_CELL_2048_BG;
    colors[12] = COLOR_CELL_MORE_BG;
    colors[13] = COLOR_CELL_MORE_BG;
    colors[14] = COLOR_CELL_MORE_BG;
    colors[15] = COLOR_CELL_MORE_BG;

    // init start position
    int r1 = rand()%15;
    int r2 = -1;
    do {
        r2 = rand()%15;
    } while (r1 == r2);
    game.cells[r1] = 2;
    game.cells[r2] = (rand()%10 == 0) ? 4: 2;
    game.score = game.best = game.cells[r1] + game.cells[r2];
}

void game_play_up() {
 for (int x = 0; x < 4; x++) {
        for (int y = 3; y > 0; y--) {
            // above is empty
            if (game.cells[x+(y-1)*4] == 0) {
                game.cells[x+(y-1)*4] = game.cells[x+y*4];
                game.cells[x+y*4] = 0;
            } else if (game.cells[x+(y-1)*4] ==  game.cells[x+y*4]) {
                game.cells[x+(y-1)*4] = game.cells[x+y*4] * 2;
                game.cells[x+y*4] = 0;
            }
        }
 }
}

void game_play_down() {
 for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 3; y++) {
            // above is empty
            if (game.cells[x+(y+1)*4] == 0) {
                game.cells[x+(y+1)*4] = game.cells[x+y*4];
                game.cells[x+y*4] = 0;
            } else if (game.cells[x+(y+1)*4] ==  game.cells[x+y*4]) {
                game.cells[x+(y+1)*4] = game.cells[x+y*4] * 2;
                game.cells[x+y*4] = 0;
            }
        }
 }
}

void game_play_left() {
 for (int x = 3; x > 0; x--) {
        for (int y = 0; y < 4; y++) {
            // left is empty
            if (game.cells[(x-1)+y*4] == 0) {
                game.cells[(x-1)+y*4] = game.cells[x+y*4];
                game.cells[x+y*4] = 0;
            } else if (game.cells[(x-1)+y*4] ==  game.cells[x+y*4]) {
                game.cells[(x-1)+y*4] = game.cells[x+y*4] * 2;
                game.cells[x+y*4] = 0;
            }
        }
    }
}

void game_play_right() {
 for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 4; y++) {
            // left is empty
            if (game.cells[(x+1)+y*4] == 0) {
                game.cells[(x+1)+y*4] = game.cells[x+y*4];
                game.cells[x+y*4] = 0;
            } else if (game.cells[(x+1)+y*4] ==  game.cells[x+y*4]) {
                game.cells[(x+1)+y*4] = game.cells[x+y*4] * 2;
                game.cells[x+y*4] = 0;
            }
        }
    }
}

void game_play(direction_t direction)
{
    if (direction == d_up) {
        game_play_up();
    } else if (direction == d_down) {
        game_play_down();
    } else if (direction == d_left) {
        game_play_left();
    } else if (direction == d_right) {
        game_play_right();
    } else {
        game.cells[direction] = (game.cells[direction] == 0 ? 2 : game.cells[direction] * 2);
    }

    game.cells[rand()%15] = 2;

    // compute score
    game.score = 0;
    for (int i = 0; i < 16; i++)
        game.score += game.cells[i];

    if (game.score > game.best)
         game.best = game.score;
}

int game_score() {
    return game.score;
}

int game_best() {
    return game.best;
}

static inline uint8_t game_log2(int n) {
    switch(n) {
        case 2:
            return 1;
        case 4:
            return 2;
        case 8:
            return 3;
        case 16:
            return 4;
        case 32:
            return 5;
        case 64:
            return 6;
        case 128:
            return 7;
        case 256:
            return 8;
        case 512:
            return 9;
        case 1024:
            return 10;
        case 2048:
            return 11;
        case 4096:
            return 12;
        case 8192:
            return 13;
        case 16384:
            return 14;
        case 32768:
            return 15;
    }
    return 0;
}

void game_draw(display_context_t disp, int grid_x, int grid_y)
{
    rdp_draw_filled_rectangle_size(grid_x, grid_y, 360 , 360, COLOR_GRID_BG);
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            int xx = grid_x + 8 + (x*88);
            int yy = grid_y + 8 + (y*88);

            int score = game_log2(game.cells[x+y*4]);
            rdp_draw_filled_rectangle_size(xx, yy, 80 , 80, colors[score]);
            sprite_t *sp = sprites[score];
            if (sp != NULL) {
                graphics_draw_sprite_trans(disp, xx + 40 - sp->width/2, yy + 40 - sp->height/2, sp);
            }
        }
    }
}


