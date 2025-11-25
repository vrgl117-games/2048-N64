/* menus.c -- menus helpers implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "bgm.h"
#include "colors.h"
#include "game.h"
#include "lang.h"
#include "menus.h"
#include "rdpq.h"
#include "sprite.h"

extern menu_t menu;

/* menus */
menu_t menu_credits;

menu_t menu_pause = {
    .title = "title_pause",
    .max_width = 260,
    .max_height = 80 + 30 * 4,
    .options_size = 4,
    .options = {{.text = "continue", .action = bgm_play, .close = true}, {.text = "restart", .action = game_reset, .close = true}, {.text = "music", .toggle = bgm_toggle, .close = false}, {.text = "credits", .next = &menu_credits, .close = false}},
    .visible = true,
};

menu_t menu_credits = {
    .title = "title_credits",
    .text = "text_credits",
    .max_width = 380,
    .max_height = 80 + 30 + 220,
    .options_size = 1,
    .options = {{.text = "back", .next = &menu_pause, .close = false}},
    .visible = true,
};

menu_t menu_you_win = {
    .title = "title_you_win",
    .max_width = 240,
    .max_height = 80 + 30 * 2,
    .options_size = 2,
    .options = {{.text = "continue", .action = bgm_play, .close = true}, {.text = "restart", .action = game_reset, .close = true}},
    .visible = true,
};

menu_t menu_game_over = {
    .title = "title_game_over",
    .max_width = 240,
    .max_height = 80 + 30,
    .options_size = 1,
    .options = {{.text = "restart", .action = game_reset, .close = true}},
    .visible = true,
};

menu_t menu_new_game = {
    .title = "title_new_game",
    .text = "text_help",
    .max_width = 440,
    .max_height = 80 + 30 + 140,
    .options_size = 1,
    .options = {{.text = "continue", .action = NULL, .close = true}},
    .visible = true,
};

void menu_draw(display_context_t disp, menu_t *menu)
{
    char *lang = lang_selected_str();

    if (!menu->visible)
        return;

    int w_step = 24;
    int h_step = 24;

    if (menu->closing)
    {
        menu->width -= w_step;
        menu->height -= h_step;

        if (menu->width <= 0 && menu->height <= 0)
        {
            menu->closing = false;
            menu->visible = false;
            return;
        }
    }
    else
    {
        if (menu->width < menu->max_width)
        {
            menu->width += w_step;
            if (menu->width > menu->max_width)
                menu->width = menu->max_width;
        }
        if (menu->width > menu->max_width)
            menu->width -= w_step;

        if (menu->height < menu->max_height)
        {
            menu->height += h_step;
            if (menu->height > menu->max_height)
                menu->height = menu->max_height;
        }
        if (menu->height > menu->max_height)
            menu->height -= h_step;
    }

    sprite_t *title = NULL;
    sprite_t *text = NULL;
    sprite_t *options[menu->options_size];

    if (menu->width >= menu->max_width && menu->height >= menu->max_height)
    {

        if (menu->title != NULL)
            title = sprite_loadf("rom:/gfx/sprites/%s/%s.rgba16.sprite", lang, menu->title);

        if (menu->text != NULL)
            text = sprite_loadf("rom:/gfx/sprites/%s/%s.rgba16.sprite", lang, menu->text);

        for (int i = 0; i < menu->options_size; i++)
        {
            if (menu->options[i].toggle != NULL)
                options[i] = sprite_loadf((i == menu->selected_option ? "rom:/gfx/sprites/%s/%s_%d_selec.rgba16.sprite" : "rom:/gfx/sprites/%s/%s_%d.rgba16.sprite"), lang, menu->options[i].text, menu->options[i].toggle(0));
            else
                options[i] = sprite_loadf((i == menu->selected_option ? "rom:/gfx/sprites/%s/%s_selec.rgba16.sprite" : "rom:/gfx/sprites/%s/%s.rgba16.sprite"), lang, menu->options[i].text);
        }
    }

    rdpq_attach(disp, NULL);
    rdpq_draw_filled_rectangle_with_border_size(320 - menu->width / 2, 240 - menu->height / 2, menu->width, menu->height, colors[COLOR_GRID_BG], colors[COLOR_CELL_MORE_BG]);

    if (menu->width >= menu->max_width && menu->height >= menu->max_height)
    {

        if (menu->title != NULL)
            rdpq_draw_sprite(title, 320 - title->width / 2, 240 - menu->height / 2 + 10, 0);

        if (menu->text != NULL)
            rdpq_draw_sprite(text, 320 - text->width / 2, 240 - menu->height / 2 + 75, 0);

        for (int i = 0; i < menu->options_size; i++)
            rdpq_draw_sprite(options[i], 320 - options[i]->width / 2, 240 + menu->height / 2 - 35 - 30 * (menu->options_size - 1 - i), 0);
    }

    rdpq_detach();

    if (title != NULL)
        sprite_free(title);
    if (text != NULL)
        sprite_free(text);
    if (menu->width >= menu->max_width && menu->height >= menu->max_height)
    {
        for (int i = 0; i < menu->options_size; i++)
        {
            if (options[i] != NULL)
                sprite_free(options[i]);
        }
    }
}

bool menu_press(menu_t *m, control_t keys)
{
    if (keys.start)
    {
        m->closing = true;

        if (m->options[0].next != NULL && m->options[0].next->options[0].action != NULL)
            m->options[0].next->options[0].action();
        if (m->options[0].action != NULL)
            m->options[0].action();
        return true;
    }

    if (keys.direction == d_up)
    {
        m->selected_option--;
        if (m->selected_option == -1)
            m->selected_option = m->options_size - 1;
    }
    if (keys.direction == d_down)
        m->selected_option = (m->selected_option + 1) % m->options_size;

    if (keys.direction == d_left && m->options[m->selected_option].toggle != NULL)
        m->options[m->selected_option].toggle(-1);

    if (keys.direction == d_right && m->options[m->selected_option].toggle != NULL)
        m->options[m->selected_option].toggle(1);

    if (keys.A || keys.B)
    {
        int opt = (keys.A ? m->selected_option : 0);
        m->closing = m->options[opt].close;

        if (m->options[opt].action != NULL)
            m->options[opt].action();
        else if (m->options[opt].toggle != NULL)
            m->options[opt].toggle(1);
        else if (m->options[opt].next != NULL)
        {
            int w = menu.width;
            int h = menu.height;
            menu = *m->options[opt].next;
            menu.width = w;
            menu.height = h;
            menu.selected_option = menu.options_size - 1;
        }
        return true;
    }

    return false;
}
