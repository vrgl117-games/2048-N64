/* menus.h -- menus helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __MENUS_H__
#define __MENUS_H__

#include <libdragon.h>

#include "controls.h"

typedef struct menu
{
    bool visible;

    char *title;
    char *text;
    char *options[3];
    int options_size;

    int selected_option;

    int current_y;
} menu_t;

void menu_draw(display_context_t disp, menu_t *menu);
int menu_press(menu_t *menu, control_t keys);

#endif //__MENUS_H__
