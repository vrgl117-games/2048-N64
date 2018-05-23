/* game.c -- game helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "dfs.h"
#include "game.h"
#include "konami.h"
#include "rdp.h"

static game_t game = {0};
static map_t *maps[16];
static uint32_t colors[16];

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
  maps[1] = dfs_load_map("/gfx/maps/2-%02d.sprite", 1, NULL);
  maps[2] = dfs_load_map("/gfx/maps/4-%02d.sprite", 1, NULL);
  maps[3] = dfs_load_map("/gfx/maps/8-%02d.sprite", 1, NULL);
  maps[4] = dfs_load_map("/gfx/maps/16-%02d.sprite", 1, NULL);
  maps[5] = dfs_load_map("/gfx/maps/32-%02d.sprite", 1, NULL);
  maps[6] = dfs_load_map("/gfx/maps/64-%02d.sprite", 1, NULL);
  maps[7] = dfs_load_map("/gfx/maps/128-%02d.sprite", 1, NULL);
  maps[8] = dfs_load_map("/gfx/maps/256-%02d.sprite", 1, NULL);
  maps[9] = dfs_load_map("/gfx/maps/512-%02d.sprite", 1, NULL);
  maps[10] = dfs_load_map("/gfx/maps/1024-%02d.sprite", 2, NULL);
  maps[11] = dfs_load_map("/gfx/maps/2048-%02d.sprite", 2, NULL);
  maps[12] = dfs_load_map("/gfx/maps/4096-%02d.sprite", 2, NULL);
  maps[13] = dfs_load_map("/gfx/maps/8192-%02d.sprite", 2, NULL);
  maps[14] = dfs_load_map("/gfx/maps/16384-%02d.sprite", 2, NULL);
  maps[15] = dfs_load_map("/gfx/maps/32768-%02d.sprite", 2, NULL);

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
  game.won = false;

  // init start position
  int r1 = rand() % 16;
  int r2 = -1;
  do
  {
    r2 = rand() % 16;
  } while (r1 == r2);
  game.cells[r1] = game_new_cell();
  game.cells[r2] = game_new_cell();
  game.score = game.cells[r1] / 10 + game.cells[r2] / 10;
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
    if (i < 12 && game.cells[i] == game.cells[i + 4])
      return false;

    // (left 3 columns) can merge with right one ?
    if (i % 4 != 3 && game.cells[i] == game.cells[i + 1])
      return false;
  }
  return true;
}

status_t game_play(control_t keys)
{
  status_t status = game_none;
  uint8_t move = 10;

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
      rumble_start(0);
      game.rumble = 4;
    }
    return status;
  }

  int nbEmpty = 0;
  int empty[16] = {0};

  // compute score
  game.score = 0;
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
    game.score += score;
  }

  int new = game_new_cell();
  game.cells[empty[rand() % (nbEmpty)]] = new;
  game.score += new / 10;

  if (game.score > game.best)
    game.best = game.score;

  // if there was only 1 empty cell, the grid is now full, is it game over ?
  if (nbEmpty == 1 && is_gameover())
    status = game_over;

  return status;
}

// return current score
int game_score() { return game.score; }

// return best score
int game_best() { return game.best; }

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
  int flags = (konami_enabled() ? 3 : 0);
  rdp_draw_filled_rectangle_size(grid_x, grid_y, 360, 360, COLOR_GRID_BG);
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
        rdp_draw_filled_rectangle_size(xx, yy, 80, 80, colors[score]);
        break;
      case 1 ... 4:
        rdp_draw_filled_rectangle_size(xx + diff * 4, yy + diff * 4,
                                       80 - diff * 8, 80 - diff * 8,
                                       colors[score]);
        game.cells[x + y * 4] -= 1;
        score = 0;
        break;
      case 6 ... 9:
        rdp_draw_filled_rectangle_size(xx - diff, yy - diff, 80 + diff * 2,
                                       80 + diff * 2, colors[score]);
        game.cells[x + y * 4] -= 1;
        break;
      }

      map_t *map = maps[score];
      if (map != NULL)
        rdp_draw_sprite_with_texture_map(map, xx + 40 - map->width / 2,
                                         yy + 40 - map->height / 2, flags);
    }
  }
}