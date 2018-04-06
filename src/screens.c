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

void screen_init(char *lang)
{
    logo = dfs_load_map("/gfx/maps/logo-%02d.sprite", 3);
    best = dfs_loadf("/gfx/sprites/%s/best.sprite", lang);
    score = dfs_loadf("/gfx/sprites/%s/score.sprite", lang);
    font = dfs_load_map("/gfx/maps/font%d.sprite", 1);
}

// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    static int anim = 0;

    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BLACK);

    rdp_detach_display();
    sprite_t *intro = NULL;

    switch (anim)
    {
    case 1 ... 9:
        intro = dfs_loadf("/gfx/sprites/n64_%d.sprite", anim);
        break;
    case 10 ... 30:
        intro = dfs_load("/gfx/sprites/n64.sprite");
        break;
    case 31 ... 39:
        intro = dfs_loadf("/gfx/sprites/n64_%d.sprite", 40 - anim);
        break;
    case 41 ... 49:
        intro = dfs_loadf("/gfx/sprites/intro_%d.sprite", anim - 40);
        break;
    case 50 ... 70:
        intro = dfs_load("/gfx/sprites/intro.sprite");
        break;
    case 71 ... 79:
        intro = dfs_loadf("/gfx/sprites/intro_%d.sprite", 80 - anim);
        break;
    }

    if (intro != NULL)
    {
        graphics_draw_sprite(disp, 320 - intro->width / 2, 150, intro);
        free(intro);
    }

    anim++;
    return (anim >= 82);
}

void screen_no_controller(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BLACK);

    rdp_detach_display();

    sprite_t *no_controller = dfs_load("/gfx/sprites/en/no_controller.sprite");
    graphics_draw_sprite_trans(disp, 320 - no_controller->width / 2, 240 - no_controller->height / 2, no_controller);
    free(no_controller);
}

void screen_game(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(COLOR_BG);

    rdp_draw_sprite_with_texture_map(logo, 140, 18, (konami_enabled() ? 3 : 0));

    rdp_draw_filled_rectangle_with_border_size(320, 30, 80, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(best, 326, 32, (konami_enabled() ? 3 : 0));
    rdp_draw_int_map(326, 50, font, game_best(), (konami_enabled() ? 3 : 0));

    rdp_draw_filled_rectangle_with_border_size(420, 30, 80, 40, COLOR_CELL_EMPTY_BG, COLOR_GRID_BG);
    rdp_draw_sprite_with_texture(score, 426, 32, (konami_enabled() ? 3 : 0));
    rdp_draw_int_map(426, 50, font, game_score(), (konami_enabled() ? 3 : 0));

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
        map_t *press_start = dfs_load_map("/gfx/maps/en/press_start-%02d.sprite", 3);
        rdp_draw_sprite_with_texture_map(press_start, 318, 26, (konami_enabled() ? 3 : 0));
        dfs_free_map(press_start);
    }

    game_draw(disp, 140, 90);

    rdp_detach_display();

    if (press_start)
    {
        sprite_t *version = dfs_load("/gfx/sprites/en/version.sprite");
        graphics_draw_sprite_trans(disp, 640 - version->width - 6, 480 - version->height - 6, version);
        free(version);
    }
}
