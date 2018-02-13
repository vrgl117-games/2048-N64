/* menus.c -- menus helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdio.h>
#include <malloc.h>

#include "colors.h"
#include "dfs.h"
#include "menus.h"
#include "rdp.h"

void menu_draw(display_context_t disp, menu_t *menu)
{
    if (!menu->visible)
    {
        return;
    }

    int w = 200;
    int h = 80 + 30 * menu->options_size;

    rdp_draw_filled_rectangle_with_border_size(320 - w / 2, 240 - h / 2, w, h, COLOR_GRID_BG, COLOR_CELL_MORE_BG);

    if (menu->title != NULL)
    {
        sprite_t *title = dfs_loadf("/gfx/%s.sprite", menu->title);
        graphics_draw_sprite_trans(disp, 320 - title->width / 2, 240 - h / 2 + 10, title);
        free(title);
    }
    for (int i = 0; i < menu->options_size; i++)
    {
        sprite_t *option = dfs_loadf((i == menu->selected_option ? "/gfx/%s_selec.sprite" : "/gfx/%s.sprite"), menu->options[i]);
        graphics_draw_sprite_trans(disp, 320 - option->width / 2, 240 - h / 2 + 75 + 30 * i, option);
        free(option);
    }
}

int menu_press(menu_t *menu, control_t keys)
{
    if (IS_DOWN(keys.start) || IS_DOWN(keys.B))
    {
        menu->selected_option = 0;
        menu->visible = false;
        return menu->default_option;
    }
    if (IS_DOWN(keys.up) && menu->selected_option != 0)
    {
        menu->selected_option--;
    }
    if (IS_DOWN(keys.down) && menu->selected_option != menu->options_size - 1)
    {
        menu->selected_option++;
    }
    if (IS_DOWN(keys.A))
    {
        int selected = menu->selected_option;
        menu->selected_option = 0;
        menu->visible = false;
        return selected;
    }
    return -1;
}