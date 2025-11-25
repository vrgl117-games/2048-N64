/* screens.c -- screens helpers implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "colors.h"
#include "font.h"
#include "game.h"
#include "konami.h"
#include "lang.h"
#include "rdpq.h"
#include "screens.h"
#include "sprite.h"

static volatile int tick = 0;
static sprite_t *best;
static sprite_t *logo;
static sprite_t *score;

void screen_game(display_context_t disp)
{
    rdpq_attach_clear(disp, NULL);

    rdpq_draw_filled_fullscreen(colors[COLOR_BG]);

    rdpq_draw_sprite(logo, 140, 18, (konami_enabled() ? MIRROR_XY : 0));

    // draw best.
    rdpq_draw_filled_rectangle_with_border_size(320, 30, 80, 40, colors[COLOR_CELL_EMPTY_BG], colors[COLOR_GRID_BG]);
    rdpq_draw_sprite(best, 326, 32, (konami_enabled() ? MIRROR_XY : 0));
    rdpq_text_printn(NULL, (konami_enabled() ? FONT_BOLD_FLIPPED : FONT_BOLD), 326, 66, game_best(), strlen(game_best()));

    // draw score.
    rdpq_draw_filled_rectangle_with_border_size(420, 30, 80, 40, colors[COLOR_CELL_EMPTY_BG], colors[COLOR_GRID_BG]);
    rdpq_draw_sprite(score, 426, 32, (konami_enabled() ? MIRROR_XY : 0));
    rdpq_text_printn(NULL, (konami_enabled() ? FONT_BOLD_FLIPPED : FONT_BOLD), 426, 66, game_score(), strlen(game_score()));

    // draw the board.
    game_draw(disp, 140, 90);

    rdpq_detach();
}

void screen_init()
{
    logo = sprite_load("rom:/gfx/sprites/logo.rgba16.sprite");
    best = sprite_loadf("rom:/gfx/sprites/%s/best.rgba16.sprite", lang_selected_str());
    score = sprite_loadf("rom:/gfx/sprites/%s/score.rgba16.sprite", lang_selected_str());
}

// display the n64 logo and then the vrgl117 games logo.
// return true when the animation is done.
bool screen_intro(display_context_t disp)
{
    static int anim = 0;
    int alpha = 255;

    if (tick > 0)
    {
        anim++;
        tick = 0;
    }

    sprite_t *intro = NULL;

    if (anim >= 1 && anim <= 39)
    {
        intro = sprite_load("rom:/gfx/sprites/n64.rgba16.sprite");

        if (anim <= 9) // fade in
            alpha = (anim - 1) * (255 / 9.0f);
        else if (anim <= 30) // full
            alpha = 255;
        else // fade out
        {
            int a = anim - 30; // 1..9
            alpha = 255 - a * (255 / 9.0f);
        }
    }

    if (anim >= 41 && anim <= 79)
    {
        intro = sprite_load("rom:/gfx/sprites/intro.rgba16.sprite");

        if (anim <= 49) // fade in
        {
            int a = anim - 40; // 1..9
            alpha = a * (255 / 9.0f);
        }
        else if (anim <= 70) // full
            alpha = 255;
        else // fade out
        {
            int a = anim - 70; // 1..9
            alpha = 255 - a * (255 / 9.0f);
        }
    }

    if (intro != NULL)
    {
        rdpq_attach_clear(disp, NULL);
        rdpq_draw_faded_sprite(intro, 320 - intro->width / 2, 150, alpha);
        rdpq_detach();
        sprite_free(intro);
    }

    return (anim >= 82);
}

void screen_lang(display_context_t disp)
{
    int selected_lang = lang_selected();

    sprite_t *en = sprite_load("rom:/gfx/sprites/en_flag.rgba16.sprite");
    sprite_t *es = sprite_load("rom:/gfx/sprites/es_flag.rgba16.sprite");
    sprite_t *fr = sprite_load("rom:/gfx/sprites/fr_flag.rgba16.sprite");

    rdpq_attach_clear(disp, NULL);

    // display the white border around the selected flag.
    rdpq_draw_filled_rectangle_with_border_size(220 - 4, 45 + 45 * selected_lang + 100 * selected_lang - 4, 208, 108, colors[COLOR_BLACK], colors[COLOR_WHITE]);

    rdpq_draw_sprite(en, 220, 45, 0);
    rdpq_draw_sprite(es, 220, 190, 0);
    rdpq_draw_sprite(fr, 220, 335, 0);

    rdpq_detach();

    sprite_free(en);
    sprite_free(es);
    sprite_free(fr);
}

void screen_no_controller(display_context_t disp)
{
    sprite_t *no_controller = sprite_loadf("rom:/gfx/sprites/%s/no_controller.rgba16.sprite", lang_selected_str());

    rdpq_attach_clear(disp, NULL);

    rdpq_draw_sprite(no_controller, 320 - no_controller->width / 2, 240 - no_controller->height / 2, (konami_enabled() ? MIRROR_XY : 0));

    rdpq_detach();

    sprite_free(no_controller);
}

void screen_timer_title()
{
    tick++;
}

// display the title screen, with press start blinking.
void screen_title(display_context_t disp, bool waiting)
{
    sprite_t *press_start = NULL;
    // draw only press start half of the time (blink).
    if (waiting && tick % 14 > 7)
        press_start = sprite_loadf("rom:/gfx/sprites/%s/press_start.rgba16.sprite", lang_selected_str());

    // draw the version if start was not pressed.
    sprite_t *version = NULL;
    if (waiting)
        version = sprite_load("rom:/gfx/sprites/version.rgba16.sprite");

    rdpq_attach_clear(disp, NULL);

    rdpq_draw_filled_fullscreen(colors[COLOR_BG]);

    rdpq_draw_sprite(logo, 140, 18, (konami_enabled() ? MIRROR_XY : 0));

    // pick a new random cell.
    if (tick % 17 == 0)
    {
        game_random();
        tick++;
    }

    // draw only press start half of the time (blink).
    if (press_start != NULL)
        rdpq_draw_sprite(press_start, 318, 26, (konami_enabled() ? MIRROR_XY : 0));

    // draw the board.
    game_draw(disp, 140, 90);

    // draw the version if start was not pressed.
    if (version != NULL)
        rdpq_draw_sprite(version, 640 - version->width - 8, 480 - version->height - 6, 0);

    rdpq_detach();

    if (press_start != NULL)
        sprite_free(press_start);

    if (version != NULL)
        sprite_free(version);
}
