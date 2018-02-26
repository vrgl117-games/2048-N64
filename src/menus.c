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
        return;

    int w = 240;
    int h = 80 + 30 * menu->options_size + (menu->text != NULL ? 100 : 0);

    rdp_draw_filled_rectangle_with_border_size(320 - w / 2, menu->current_y, w, h, COLOR_GRID_BG, COLOR_CELL_MORE_BG);

    if (menu->title != NULL)
    {
        sprite_t *title = dfs_loadf("/gfx/32/%s.sprite", menu->title);
        graphics_draw_sprite_trans(disp, 320 - title->width / 2, menu->current_y + 10, title);
        free(title);
    }

    if (menu->text != NULL)
    {
        sprite_t *text = dfs_loadf("/gfx/32/%s.sprite", menu->text);
        graphics_draw_sprite_trans(disp, 320 - text->width / 2, menu->current_y + 75, text);
        free(text);
    }

    for (int i = 0; i < menu->options_size; i++)
    {
        sprite_t *option = dfs_loadf((i == menu->selected_option ? "/gfx/32/%s_selec.sprite" : "/gfx/32/%s.sprite"), menu->options[i]);
        graphics_draw_sprite_trans(disp, 320 - option->width / 2, menu->current_y + (menu->text != NULL ? 100 : 0) + 75 + 30 * i, option);
        free(option);
    }

    if (menu->current_y != 240 - h / 2)
        menu->current_y += 15;

    if (menu->current_y >= 480)
        menu->visible = false;
}

int menu_press(menu_t *menu, control_t keys)
{
    if (IS_DOWN(keys.start) || IS_DOWN(keys.B))
    {
        menu->selected_option = 0;
        menu->current_y++;
        return 0;
    }
    if (IS_DOWN(keys.up))
        menu->selected_option = (menu->selected_option - 1) % menu->options_size;
    if (IS_DOWN(keys.down))
        menu->selected_option = (menu->selected_option + 1) % menu->options_size;
    if (IS_DOWN(keys.A))
    {
        int selected = menu->selected_option;
        menu->current_y++;
        return selected;
    }
    return -1;
}