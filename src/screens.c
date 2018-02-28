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
#include "konami.h"
#include "rdp.h"
#include "screens.h"

static volatile int tick = 0;
static map_t *font;
static map_t *logo;
static sprite_t *best;
static sprite_t *score;

void screen_timer_title()
{
    tick++;
}

void screen_init()
{
    logo = dfs_load_map("/gfx/16/logo-%02d.sprite", 6, 2);
    best = dfs_load("/gfx/16/best.sprite");
    score = dfs_load("/gfx/16/score.sprite");
    font = dfs_load_map("/gfx/16/font%d.sprite", 10, 1);
}

// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BLACK);

    rdp_detach_display();
    sprite_t *intro = NULL;

    switch (tick)
    {
    case 1 ... 9:
        intro = dfs_loadf("/gfx/32/vrgl117_%d.sprite", tick);
        break;
    case 10 ... 30:
        intro = dfs_load("/gfx/32/vrgl117.sprite");
        break;
    case 31 ... 39:
        intro = dfs_loadf("/gfx/32/vrgl117_%d.sprite", 40 - tick);
        break;
    }

    if (intro != NULL)
    {
        graphics_draw_sprite(disp, 320 - intro->width / 2, 240 - intro->height / 2, intro);
        free(intro);
    }

    return (tick >= 42);
}

void screen_no_controller(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BLACK);

    rdp_detach_display();

    sprite_t *no_controller = dfs_load("/gfx/32/no_controller.sprite");
    graphics_draw_sprite(disp, 320 - no_controller->width / 2, 240 - no_controller->height / 2, intro);
    free(no_controller);
}

void screen_game(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BG);

    rdp_draw_sprite_with_texture_map(logo, 140, 18, (konami_enabled() ? 3 : 0));

    rdp_draw_filled_rectangle_with_border_size(300, 30, 90, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(best, 306, 30, (konami_enabled() ? 3 : 0));
    rdp_draw_int_map(306, 46, font, game_best(), (konami_enabled() ? 3 : 0));

    rdp_draw_filled_rectangle_with_border_size(410, 30, 90, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(score, 416, 30, (konami_enabled() ? 3 : 0));
    rdp_draw_int_map(416, 46, font, game_score(), (konami_enabled() ? 3 : 0));

    game_draw(disp, 140, 90);

    rdp_detach_display();
}

void screen_title(display_context_t disp, bool press_start)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BG);

    rdp_draw_sprite_with_texture_map(logo, 140, 18, (konami_enabled() ? 3 : 0));

    if (tick % 17 == 0)
    {
        game_random();
        tick++;
    }

    if (press_start && tick % 14 > 7)
    {
        map_t *press_start = dfs_load_map("/gfx/16/press_start-%02d.sprite", 6, 3);
        rdp_draw_sprite_with_texture_map(press_start, 318, 26, (konami_enabled() ? 3 : 0));
        dfs_free_map(press_start);
    }

    game_draw(disp, 140, 90);

    rdp_detach_display();

    if (press_start)
    {
        sprite_t *version = dfs_load("/gfx/32/version.sprite");
        graphics_draw_sprite_trans(disp, 640 - version->width - 6, 480 - version->height - 6, version);
        free(version);
    }
}
