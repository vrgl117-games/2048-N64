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
#include "menus.h"
#include "rdp.h"

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
        if (menu->width < MAX_WIDTH)
        {
            menu->width += w_step;
            if (menu->width > MAX_WIDTH)
                menu->width = MAX_WIDTH;
        }
        if (menu->width > MAX_WIDTH)
            menu->width -= w_step;

        if (menu->height < MAX_HEIGHT)
        {
            menu->height += h_step;
            if (menu->height > MAX_HEIGHT)
                menu->height = MAX_HEIGHT;
        }
        if (menu->height > MAX_HEIGHT)
            menu->height -= h_step;
    }
    rdp_draw_filled_rectangle_with_border_size(320 - menu->width / 2, 240 - menu->height / 2, menu->width, menu->height, COLOR_GRID_BG, COLOR_CELL_MORE_BG);

    if (menu->width >= MAX_WIDTH && menu->height >= MAX_HEIGHT)
    {
        if (menu->title != NULL)
        {
            sprite_t *title = dfs_loadf("/gfx/32/%s.sprite", menu->title);
            graphics_draw_sprite_trans(disp, 320 - title->width / 2, 240 - menu->height / 2 + 10, title);
            free(title);
        }

        if (menu->text != NULL)
        {
            sprite_t *text = dfs_loadf("/gfx/32/%s.sprite", menu->text);
            graphics_draw_sprite_trans(disp, 320 - text->width / 2, 240 - menu->height / 2 + 75, text);
            free(text);
        }

        for (int i = 0; i < menu->options_size; i++)
        {
            sprite_t *option = dfs_loadf((i == menu->selected_option ? "/gfx/32/%s_selec.sprite" : "/gfx/32/%s.sprite"), menu->options[i]);
            graphics_draw_sprite_trans(disp, 320 - option->width / 2, 240 - menu->height / 2 + (menu->text != NULL ? 100 : 0) + 75 + 30 * i, option);
            free(option);
        }
    }
}

int menu_press(menu_t *menu, control_t keys)
{
    if (IS_DOWN(keys.start) || IS_DOWN(keys.B))
    {
        menu->selected_option = 0;
        menu->closing = true;
        return 0;
    }
    if (IS_DOWN(keys.up))
        menu->selected_option = (menu->selected_option - 1) % menu->options_size;
    if (IS_DOWN(keys.down))
        menu->selected_option = (menu->selected_option + 1) % menu->options_size;
    if (IS_DOWN(keys.A))
    {
        int selected = menu->selected_option;
        if (strcmp(menu->options[selected], "about") != 0 && strcmp(menu->options[selected], "back") != 0)
            menu->closing = true;
        return selected;
    }
    return -1;
}