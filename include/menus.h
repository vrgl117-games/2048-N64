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

typedef void (*action_t)(void);
typedef int (*toggle_t)(int);
typedef struct menu menu_t;

typedef struct option
{
    char *text;
    action_t action;
    toggle_t toggle;
    menu_t *next;
    bool close;

} option_t;

struct menu
{
    bool visible;
    bool closing;

    char *title;
    char *text;
    option_t options[4];
    int options_size;

    int selected_option;

    int width;
    int max_width;
    int height;
    int max_height;
};

void menu_draw(display_context_t disp, menu_t *menu);
bool menu_press(menu_t *m, control_t keys);

#endif //__MENUS_H__
