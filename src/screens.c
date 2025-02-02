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
#include "lang.h"
#include "rdp.h"
#include "screens.h"

extern uint32_t colors[];

static volatile int tick = 0;
static map_t *font;
static map_t *logo;
static sprite_t *best;
static sprite_t *score;

void screen_timer_title()
{
    tick++;
}

// load a few sprites in memory
void screen_init()
{
    logo = dfs_load_map("/gfx/maps/logo-%d_%d.sprite", NULL);
    best = dfs_load_spritef("/gfx/sprites/%s/best.sprite", lang_selected_str());
    score = dfs_load_spritef("/gfx/sprites/%s/score.sprite", lang_selected_str());
    font = dfs_load_map("/gfx/maps/font%d_%d.sprite", NULL);
}

// display the n64 logo and then the vrgl117 games logo.
// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    static int anim = 0;

    rdp_attach(disp);

    rdp_draw_filled_fullscreen(colors[COLOR_BLACK]);

    rdp_detach_display();
    sprite_t *intro = NULL;

    switch (anim)
    {
    case 1 ... 9:
        intro = dfs_load_spritef("/gfx/sprites/n64_%d.sprite", anim);
        break;
    case 10 ... 30:
        intro = dfs_load_sprite("/gfx/sprites/n64.sprite");
        break;
    case 31 ... 39:
        intro = dfs_load_spritef("/gfx/sprites/n64_%d.sprite", 40 - anim);
        break;
    case 41 ... 49:
        intro = dfs_load_spritef("/gfx/sprites/intro_%d.sprite", anim - 40);
        break;
    case 50 ... 70:
        intro = dfs_load_sprite("/gfx/sprites/intro.sprite");
        break;
    case 71 ... 79:
        intro = dfs_load_spritef("/gfx/sprites/intro_%d.sprite", 80 - anim);
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

// display the flags to select the lang.
void screen_lang(display_context_t disp)
{
    int selected_lang = lang_selected();

    rdp_attach(disp);

    rdp_draw_filled_fullscreen(colors[COLOR_BLACK]);

    // display the white border around the selected flag.
    rdp_draw_filled_rectangle_with_border_size(220 - 4, 45 + 45 * selected_lang + 100 * selected_lang - 4, 208, 108, colors[COLOR_BLACK], colors[COLOR_WHITE]);

    rdp_detach_display();

    sprite_t *en = dfs_load_sprite("/gfx/sprites/en_flag.sprite");
    graphics_draw_sprite(disp, 220, 45, en);
    free(en);

    sprite_t *es = dfs_load_sprite("/gfx/sprites/es_flag.sprite");
    graphics_draw_sprite(disp, 220, 190, es);
    free(es);

    sprite_t *fr = dfs_load_sprite("/gfx/sprites/fr_flag.sprite");
    graphics_draw_sprite(disp, 220, 335, fr);
    free(fr);
}

// display a simple text when no controller is connected.
void screen_no_controller(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(colors[COLOR_BLACK]);

    map_t *no_controller = dfs_load_map("/gfx/maps/%s/no_controller-%d_%d.sprite", lang_selected_str());
    rdp_draw_sprite_with_texture_map(no_controller, 320 - no_controller->width / 2, 240 - no_controller->height / 2, (konami_enabled() ? MIRROR_XY : 0));
    dfs_free_map(no_controller);

    rdp_detach_display();
}

// display the board and scores.
void screen_game(display_context_t disp)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(colors[COLOR_BG]);

    rdp_draw_sprite_with_texture_map(logo, 140, 18, (konami_enabled() ? MIRROR_XY : 0));

    // draw best.
    rdp_draw_filled_rectangle_with_border_size(320, 30, 80, 40, colors[COLOR_CELL_EMPTY_BG], colors[COLOR_GRID_BG]);
    rdp_draw_sprite_with_texture(best, 326, 26, (konami_enabled() ? MIRROR_XY : 0));
    rdp_draw_int_map(326, 47, font, game_best(), (konami_enabled() ? MIRROR_XY : 0));

    // draw score.
    rdp_draw_filled_rectangle_with_border_size(420, 30, 80, 40, colors[COLOR_CELL_EMPTY_BG], colors[COLOR_GRID_BG]);
    rdp_draw_sprite_with_texture(score, 426, 26, (konami_enabled() ? MIRROR_XY : 0));
    rdp_draw_int_map(426, 47, font, game_score(), (konami_enabled() ? MIRROR_XY : 0));

    // draw the board.
    game_draw(disp, 140, 90);

    rdp_detach_display();
}

// display the title screen, with press start blinking.
void screen_title(display_context_t disp, bool waiting)
{
    rdp_attach(disp);

    rdp_draw_filled_fullscreen(colors[COLOR_BG]);

    rdp_draw_sprite_with_texture_map(logo, 140, 18, (konami_enabled() ? MIRROR_XY : 0));

    // pick a new random cell.
    if (tick % 17 == 0)
    {
        game_random();
        tick++;
    }

    // draw only press start half of the time (blink).
    if (waiting && tick % 14 > 7)
    {
        map_t *press_start = dfs_load_map("/gfx/maps/%s/press_start-%d_%d.sprite", lang_selected_str());
        rdp_draw_sprite_with_texture_map(press_start, 318, 26, (konami_enabled() ? MIRROR_XY : 0));
        dfs_free_map(press_start);
    }

    // draw the board.
    game_draw(disp, 140, 90);

    // draw the version if start was not pressed.
    if (waiting)
    {
        sprite_t *version = dfs_load_sprite("/gfx/sprites/version.sprite");
        rdp_draw_sprite_with_texture(version, 640 - version->width - 6, 480 - version->height - 6, 0);
        free(version);
    }

    rdp_detach_display();
}
