/* game.c -- game helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <string.h>
#include <stdlib.h>

#include "colors.h"
#include "dfs.h"
#include "game.h"
#include "rdp.h"

static game_t game;
static sprite_t *sprites[16];
static uint32_t colors[16];

void game_init()
{

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

    game_reset();
    game.best = game.score;
}

void game_reset()
{
    memset(game.cells, 0, sizeof(int) * 16);

    // init start position
    int r1 = rand() % 15;
    int r2 = -1;
    do
    {
        r2 = rand() % 15;
    } while (r1 == r2);
    game.cells[r1] = (rand() % 15 == 0) ? 4 : 2;
    game.cells[r2] = (rand() % 15 == 0) ? 4 : 2;
    game.score = game.cells[r1] + game.cells[r2];

    /*game.cells[0] = 4;
    game.cells[4] = 4;
    game.cells[8] = 4;
    game.cells[12] = 4;

    game.cells[1] = 0;
    game.cells[5] = 0;
    game.cells[9] = 4;
    game.cells[13] = 4;

    game.cells[2] = 0;
    game.cells[6] = 4;
    game.cells[10] = 0;
    game.cells[14] = 4;*/
}

static inline uint8_t move_vertical(int x, int dir, int from)
{
    uint8_t move = 0;

    for (int i = 0, y = from, yy = from; i < 4; i++)
    {
        if (game.cells[x + y * 4] != 0)
        {
            if (y != yy)
            {
                game.cells[x + yy * 4] = game.cells[x + y * 4];
                game.cells[x + y * 4] = 0;
                move = 1;
            }
            yy += dir;
        }
        y += dir;
    }
    return move;
}

static inline uint8_t game_play_vertical(int dir)
{
    int from = (dir == 1 ? 0 : 3);
    uint8_t move = 0;

    for (int x = 0; x < 4; x++)
    {
        // move
        move += move_vertical(x, dir, from);

        // merge adjacent cells
        for (int i = 0, y = from; i < 3; i++)
        {
            if (game.cells[x + y * 4] != 0 && game.cells[x + y * 4] == game.cells[x + (y + dir) * 4])
            {
                game.cells[x + y * 4] *= 2;
                game.cells[x + (y + dir) * 4] = 0;
                move = 2;
            }
            y += dir;
        }

        // if we did merge, we might need to move again
        if (move == 2)
        {
            move_vertical(x, dir, from);
        }
    }

    return move;
}

static inline uint8_t move_horiz(int y, int dir, int from)
{
    uint8_t move = 0;

    for (int i = 0, x = from, xx = from; i < 4; i++)
    {
        if (game.cells[x + y * 4] != 0)
        {
            if (x != xx)
            {
                game.cells[xx + y * 4] = game.cells[x + y * 4];
                game.cells[x + y * 4] = 0;
                move = 1;
            }
            xx += dir;
        }
        x += dir;
    }
    return move;
}

static inline uint8_t game_play_horiz(int dir)
{
    int from = (dir == 1 ? 0 : 3);
    uint8_t move = 0;

    for (int y = 0; y < 4; y++)
    {
        // move up
        move += move_horiz(y, dir, from);

        // merge adjacent cells
        for (int i = 0, x = from; i < 3; i++)
        {
            if (game.cells[x + y * 4] != 0 && game.cells[x + y * 4] == game.cells[(x + dir) + y * 4])
            {
                game.cells[x + y * 4] *= 2;
                game.cells[(x + dir) + y * 4] = 0;
                move = 2;
            }
            x += dir;
        }

        // if we did merge, we might need to move up again
        if (move == 2)
        {
            move_horiz(y, dir, from);
        }
    }

    return move;
}

// TODO implement
bool is_gameover()
{
    return false;
}

bool game_play(direction_t direction)
{
    uint8_t move = 10;

    if (direction == d_up)
    {
        move = game_play_vertical(1);
    }
    else if (direction == d_down)
    {
        move = game_play_vertical(-1);
    }
    else if (direction == d_left)
    {
        move = game_play_horiz(1);
    }
    else if (direction == d_right)
    {
        move = game_play_horiz(-1);
    }

    if (move == 0)
    {
        rumble_start(0);
        return false;
    }

    int nbEmpty = 0;
    int empty[16] = {0};
    // compute score
    game.score = 0;
    for (int i = 0; i < 16; i++)
    {
        if (game.cells[i] == 0)
        {
            empty[nbEmpty] = i;
            nbEmpty++;
        }
        game.score += game.cells[i];
    }

    if (game.score > game.best)
        game.best = game.score;

    game.cells[empty[rand() % (nbEmpty)]] = (rand() % 15 == 0) ? 4 : 2;

    // if there was only 1 empty cell, the grid is now full, is it game over ?
    if (nbEmpty == 1)
    {
        return is_gameover();
    }

    return false;
}

int game_score()
{
    return game.score;
}

int game_best()
{
    return game.best;
}

static inline uint8_t game_log2(int n)
{
    switch (n)
    {
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
    rdp_draw_filled_rectangle_size(grid_x, grid_y, 360, 360, COLOR_GRID_BG);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            int xx = grid_x + 8 + (x * 88);
            int yy = grid_y + 8 + (y * 88);

            int score = game_log2(game.cells[x + y * 4]);
            rdp_draw_filled_rectangle_size(xx, yy, 80, 80, colors[score]);
            sprite_t *sp = sprites[score];
            if (sp != NULL)
            {
                graphics_draw_sprite_trans(disp, xx + 40 - sp->width / 2, yy + 40 - sp->height / 2, sp);
            }
        }
    }
}
