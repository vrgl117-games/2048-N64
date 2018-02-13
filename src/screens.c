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

static volatile uint8_t tick = 0;
static sprite_t *font;
static sprite_t *logo;
static sprite_t *best;
static sprite_t *score;

void screen_timer_title()
{
    tick++;
}

void screen_init()
{
    logo = dfs_load("/gfx/logo.sprite");
    best = dfs_load("/gfx/best.sprite");
    score = dfs_load("/gfx/score.sprite");
    font = dfs_load("/gfx/font.sprite");
}

static inline void screen_common(display_context_t disp)
{
    rdp_attach(disp);

    // background
    rdp_draw_filled_rectangle_size(0, 0, 640, 480, COLOR_BG);

    // logo
    graphics_draw_sprite_trans(disp, 140, 18, logo);
}

// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    if (tick > 0 && tick <= 9)
    {
        sprite_t *intro = dfs_loadf("/gfx/vrgl117_%d.sprite", tick);
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }
    else if (tick == 10)
    {
        sprite_t *intro = dfs_load("/gfx/vrgl117.sprite");
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }
    else if (tick > 10 && tick <= 19)
    {
        sprite_t *intro = dfs_loadf("/gfx/vrgl117_%d.sprite", 19 - tick);
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }

    return (tick == 20);
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
    graphics_draw_sprite_trans(disp, 300 + 6, 30, best);
    graphics_draw_int_with_font(disp, 300 + 6, 46, font, game_best());

    rdp_draw_filled_rectangle_with_border_size(410, 30, 90, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    graphics_draw_sprite_trans(disp, 410 + 6, 30, score);
    graphics_draw_int_with_font(disp, 410 + 6, 46, font, game_score());

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

    // press start
    if (tick % 2 == 0)
    {
        sprite_t *press_start = dfs_load("/gfx/press_start.sprite");
        graphics_draw_sprite_trans(disp, 320 - press_start->width / 2, 330, press_start);
        free(press_start);
    }

    rdp_detach_display();
}
