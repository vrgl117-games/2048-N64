/* screens.c -- screens helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>

#include "colors.h"
#include "controls.h"
#include "dfs.h"
#include "fps.h"
#include "game.h"
#include "graphics.h"
#include "rdp.h"
#include "screens.h"

static volatile int tick = 0;
static map_t *font;
static map_t *logo;
static sprite_t *best;
static sprite_t *score;
static map_t *press_start;

void screen_timer_title()
{
    tick++;
}

void screen_init()
{
    logo = dfs_load_map("/gfx/logo-%02d.sprite", 6, 2);
    best = dfs_load("/gfx/best.sprite");
    score = dfs_load("/gfx/score.sprite");
    font = dfs_load_map("/gfx/font%d.sprite", 10, 1);
    press_start = dfs_load_map("/gfx/press_start-%02d.sprite", 6, 3);
}

static inline void screen_common(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_rectangle_size(0, 0, 640, 480, COLOR_BG);

    rdp_draw_sprite_with_texture_map(logo, 140, 18);
}

// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_rectangle_size(0, 0, 640, 480, COLOR_BLACK);

    rdp_detach_display();

    if (tick > 0 && tick <= 9)
    {
        sprite_t *intro = dfs_loadf("/gfx/vrgl117_%d.sprite", tick);
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }
    else if (tick >= 10 && tick <= 30)
    {
        sprite_t *intro = dfs_load("/gfx/vrgl117.sprite");
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }
    else if (tick > 30 && tick < 39)
    {
        sprite_t *intro = dfs_loadf("/gfx/vrgl117_%d.sprite", 39 - tick);
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }

    return (tick >= 42);
}

void screen_no_controller(display_context_t disp)
{
    screen_common(disp);

    rdp_detach_display();

    graphics_draw_text_center(disp, 320, 230, "NO CONTROLLER INSERTED ON PORT #1");
}

void screen_game(display_context_t disp, menu_t *menu)
{
    screen_common(disp);

    rdp_draw_filled_rectangle_with_border_size(300, 30, 90, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(best, 306, 30);
    rdp_draw_int_map(306, 46, font, game_best());

    rdp_draw_filled_rectangle_with_border_size(410, 30, 90, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(score, 416, 30);
    rdp_draw_int_map(416, 46, font, game_score());

    game_draw(disp, 140, 90);
    if (menu != NULL)
    {
        menu_draw(disp, menu);
    }

    rdp_detach_display();
}

void screen_title(display_context_t disp)
{
    screen_common(disp);

    if (tick % 17 == 0)
    {
        game_random();
        tick++;
    }
    // press start
    if (tick % 14 > 7)
    {
        rdp_draw_sprite_with_texture_map(press_start, 306, 30);
    }
    game_draw(disp, 140, 90);

    rdp_detach_display();
}
