/* lang.c -- lang helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "lang.h"

static char *langs[3] = {"en", "es", "fr"};
static int selected_lang = 0;

bool lang_press(control_t keys)
{
    if (keys.direction == d_up)
    {
        selected_lang--;
        if (selected_lang == -1)
            selected_lang = 2;
    }
    if (keys.direction == d_down)
        selected_lang = (selected_lang + 1) % 3;

    if (keys.A || keys.start)
        return true;

    return false;
}

int lang_selected()
{
    return selected_lang;
}

char *lang_selected_str()
{
    return langs[selected_lang];
}
