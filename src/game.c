/* game.c -- game helpers implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bgm.h"
#include "colors.h"
#include "game.h"
#include "konami.h"
#include "rdpq.h"

static game_t game = {0};
static sprite_t *maps[16];

int game_new_cell()
{
    int r = rand() % 10;

    if (r == 0)
        return 40 + POP;
    return 20 + POP;
}

void game_init()
{
    // init sprites
    maps[1] = sprite_load("rom:/gfx/sprites/2.rgba32.sprite");
    maps[2] = sprite_load("rom:/gfx/sprites/4.rgba32.sprite");
    maps[3] = sprite_load("rom:/gfx/sprites/8.rgba32.sprite");
    maps[4] = sprite_load("rom:/gfx/sprites/16.rgba32.sprite");
    maps[5] = sprite_load("rom:/gfx/sprites/32.rgba32.sprite");
    maps[6] = sprite_load("rom:/gfx/sprites/64.rgba32.sprite");
    maps[7] = sprite_load("rom:/gfx/sprites/128.rgba32.sprite");
    maps[8] = sprite_load("rom:/gfx/sprites/256.rgba32.sprite");
    maps[9] = sprite_load("rom:/gfx/sprites/512.rgba32.sprite");
    maps[10] = sprite_load("rom:/gfx/sprites/1024.rgba32.sprite");
    maps[11] = sprite_load("rom:/gfx/sprites/2048.rgba32.sprite");
    maps[12] = sprite_load("rom:/gfx/sprites/4096.rgba32.sprite");
    maps[13] = sprite_load("rom:/gfx/sprites/8192.rgba32.sprite");
    maps[14] = sprite_load("rom:/gfx/sprites/16384.rgba32.sprite");
    maps[15] = sprite_load("rom:/gfx/sprites/32768.rgba32.sprite");
    game_reset();
    game_set_best(game.score);
}

void game_reset()
{
    bgm_play();
    memset(game.cells, 0, sizeof(int) * 16);
    game.won = false;

    /* debug
    game.cells[0] = 640;
    game.cells[1] = 640;
    game.cells[2] = 20;
    game.cells[3] = 0;
    game.cells[4] = 40;
    game.cells[5] = 80;
    game.cells[6] = 40;
    game.cells[7] = 80;
    game.cells[8] = 20;
    game.cells[9] = 40;
    game.cells[10] = 20;
    game.cells[11] = 40;
    game.cells[12] = 40;
    game.cells[13] = 80;
    game.cells[14] = 40;
    game.cells[15] = 80;
    */

    // init start position
    int r1 = rand() % 16;
    int r2 = -1;
    do
    {
        r2 = rand() % 16;
    } while (r1 == r2);
    game.cells[r1] = game_new_cell();
    game.cells[r2] = game_new_cell();
    game_set_score(game.cells[r1] / 10 + game.cells[r2] / 10);
}

void game_random()
{
    int old = -1;
    for (int i = 0; i < 16; i++)
    {
        if (game.cells[i] == 2048 * 10)
        {
            game.cells[i] = POP;
            old = i;
        }
        else
            game.cells[i] = 0;
    }

    int new = -1;
    do
    {
        new = rand() % 16;
    } while (old == new);
    game.cells[new] = 2048 * 10 + POP;
}

bool game_stop_rumble()
{
    // rumble already stopped
    if (game.rumble == 0)
        return false;

    game.rumble--;

    return (game.rumble == 0);
}

// return > 0 if player was able to move
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

// return > 0 if player was able to play (move and/or merge)
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
            if (game.cells[x + y * 4] != 0 &&
                game.cells[x + y * 4] == game.cells[x + (y + dir) * 4])
            {
                game.cells[x + y * 4] = game.cells[x + y * 4] * 2 + MERGE;
                game.cells[x + (y + dir) * 4] = 0;
                move = 2;
            }
            y += dir;
        }

        // if we did merge, we might need to move again
        if (move == 2)
            move_vertical(x, dir, from);
    }

    return move;
}

// return > 0 if player was able to move
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

// return > 0 if player was able to play (move and/or merge)
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
            if (game.cells[x + y * 4] != 0 &&
                game.cells[x + y * 4] == game.cells[(x + dir) + y * 4])
            {
                game.cells[x + y * 4] = game.cells[x + y * 4] * 2 + MERGE;
                game.cells[(x + dir) + y * 4] = 0;
                move = 2;
            }
            x += dir;
        }

        // if we did merge, we might need to move up again
        if (move == 2)
            move_horiz(y, dir, from);
    }

    return move;
}

// return true if gameover
static inline bool is_gameover()
{
    for (int i = 0; i < 16; i++)
    {
        // (top 3 row) can merge with bottom one ?
        if (i < 12 && game.cells[i] / 10 == game.cells[i + 4] / 10)
            return false;

        // (left 3 columns) can merge with right one ?
        if (i % 4 != 3 && game.cells[i] / 10 == game.cells[i + 1] / 10)
            return false;
    }
    return true;
}

status_t game_play(control_t keys)
{
    status_t status = game_none;
    uint8_t move = 10;
    uint16_t new_score = 0;

    switch (keys.direction)
    {
    case d_up:
        move = game_play_vertical(konami_enabled() ? -1 : 1);
        break;
    case d_down:
        move = game_play_vertical(konami_enabled() ? 1 : -1);
        break;
    case d_left:
        move = game_play_horiz(konami_enabled() ? -1 : 1);
        break;
    case d_right:
        move = game_play_horiz(konami_enabled() ? 1 : -1);
        break;
    default:
        return status;
    }

    if (move == 0)
    {
        if (keys.rumble)
        {
            joypad_set_rumble_active(JOYPAD_PORT_1, true);
            game.rumble = 4;
        }
        return status;
    }

    int nbEmpty = 0;
    int empty[16] = {0};

    // compute score
    for (int i = 0; i < 16; i++)
    {
        int score = game.cells[i] / 10;
        if (game.cells[i] == 0)
        {
            empty[nbEmpty] = i;
            nbEmpty++;
        }
        else if (!game.won && score == 2048)
        {
            status = game_win;
            game.won = true;
        }
        new_score += score;
    }

    int new = game_new_cell();
    game.cells[empty[rand() % (nbEmpty)]] = new;
    new_score += new / 10;

    game_set_score(new_score);

    if (game.score > game.best)
        game_set_best(game.score);

    // if there was only 1 empty cell, the grid is now full, is it game over ?
    if (nbEmpty == 1 && is_gameover())
        status = game_over;

    return status;
}

// return current score
const char *game_score() { return game.score_str; }

// return best score
const char *game_best() { return game.best_str; }

void game_set_best(uint16_t best)
{
    if (game.best == best && game.best_str[0] != '\0')
        return;

    game.best = best;
    snprintf(game.best_str, sizeof(game.best_str), "%u", game.best);
}

void game_set_score(uint16_t score)
{
    if (game.score == score && game.score_str[0] != '\0')
        return;

    game.score = score;
    snprintf(game.score_str, sizeof(game.score_str), "%u", game.score);
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
    int flags = (konami_enabled() ? MIRROR_XY : 0);
    rdpq_draw_filled_rectangle_size(grid_x, grid_y, 360, 360, colors[COLOR_GRID_BG]);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            int xx = grid_x + 8 + (x * 88);
            int yy = grid_y + 8 + (y * 88);

            // actual score to be displayed
            int value = floor(game.cells[x + y * 4] / 10);
            int score = game_log2(value);

            // diff == 0 -> no animation
            // diff < 5 -> start small and grow and hide score
            // diff == 5 -> no animation
            // diff < 9 -> start big and reduce
            int diff = game.cells[x + y * 4] - value * 10;
            switch (diff)
            {
            case 5:
                game.cells[x + y * 4] = value * 10;
            case 0:
                rdpq_draw_filled_rectangle_size(xx, yy, 80, 80, colors[(score > 12 ? 12 : score)]);
                break;
            case 1 ... 4:
                rdpq_draw_filled_rectangle_size(xx + diff * 4, yy + diff * 4,
                                                80 - diff * 8, 80 - diff * 8,
                                                colors[(score > 12 ? 12 : score)]);
                game.cells[x + y * 4] -= 1;
                score = 0;
                break;
            case 6 ... 9:
                rdpq_draw_filled_rectangle_size(xx - diff, yy - diff, 80 + diff * 2,
                                                80 + diff * 2, colors[(score > 12 ? 12 : score)]);
                game.cells[x + y * 4] -= 1;
                break;
            }

            sprite_t *map = maps[score];
            if (map != NULL)
                rdpq_draw_sprite(map, xx + 40 - map->width / 2,
                                 yy + 40 - map->height / 2, flags);
        }
    }
}
