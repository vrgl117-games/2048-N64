/* menus.c -- menus helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "colors.h"
#include "dfs.h"
#include "game.h"
#include "menus.h"
#include "rdp.h"
#include "screens.h"

extern menu_t menu;

/* menus */
menu_t menu_about;

menu_t menu_pause = {
    .title = "title_pause",
    .max_width = 200,
    .max_height = 80 + 30 * 3,
    .options_size = 3,
    .options = {{.text = "continue", .action = NULL, .close = true}, {.text = "restart", .action = game_reset, .close = true}, {.text = "about", .next = &menu_about, .close = false}},
    .visible = true,
};

menu_t menu_about = {
    .title = "title_about",
    .text = "text_about",
    .max_width = 240,
    .max_height = 80 + 30 + 100,
    .options_size = 1,
    .options = {{.text = "back", .next = &menu_pause, .close = false}},
    .visible = true,
};

menu_t menu_you_win = {
    .title = "title_you_win",
    .max_width = 240,
    .max_height = 80 + 30 * 2,
    .options_size = 2,
    .options = {{.text = "continue", .action = NULL, .close = true}, {.text = "restart", .action = game_reset, .close = true}},
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
    rdp_attach(disp);
    rdp_draw_filled_rectangle_with_border_size(320 - menu->width / 2, 240 - menu->height / 2, menu->width, menu->height, COLOR_GRID_BG, COLOR_CELL_MORE_BG);
    rdp_detach_display();

    if (menu->width >= menu->max_width && menu->height >= menu->max_height)
    {
        if (menu->title != NULL)
        {
            sprite_t *title = dfs_loadf("/gfx/sprites/%s.sprite", menu->title);
            graphics_draw_sprite_trans(disp, 320 - title->width / 2, 240 - menu->height / 2 + 10, title);
            free(title);
        }

        if (menu->text != NULL)
        {
            sprite_t *text = dfs_loadf("/gfx/sprites/%s.sprite", menu->text);
            graphics_draw_sprite_trans(disp, 320 - text->width / 2, 240 - menu->height / 2 + 75, text);
            free(text);
        }

        for (int i = 0; i < menu->options_size; i++)
        {
            sprite_t *option = dfs_loadf((i == menu->selected_option ? "/gfx/sprites/%s_selec.sprite" : "/gfx/sprites/%s.sprite"), menu->options[i].text);
            graphics_draw_sprite_trans(disp, 320 - option->width / 2, 240 + menu->height / 2 - 35 - 30 * (menu->options_size - 1 - i), option);
            free(option);
        }
    }
}

bool menu_press(menu_t *m, control_t keys)
{
    if (keys.start || keys.B)
    {
        action_t action = m->options[0].action;
        if (action != NULL)
            action();
        else if (m->options[m->selected_option].next != NULL)
        {
            int w = menu.width;
            int h = menu.height;
            menu = *m->options[m->selected_option].next;
            menu.width = w;
            menu.height = h;
            menu.selected_option = menu.options_size - 1;
        }
        m->closing = m->options[0].close;
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

    if (keys.A)
    {
        m->closing = m->options[m->selected_option].close;

        action_t action = m->options[m->selected_option].action;
        if (action != NULL)
            action();
        else if (m->options[m->selected_option].next != NULL)
        {
            int w = menu.width;
            int h = menu.height;
            menu = *m->options[m->selected_option].next;
            menu.width = w;
            menu.height = h;
            menu.selected_option = menu.options_size - 1;
        }
        return true;
    }

    return false;
}