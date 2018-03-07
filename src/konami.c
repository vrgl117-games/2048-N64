/* konami.c -- konami helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include "konami.h"

static char *KONAMI_CODE = "uuddlrlrba";
static bool konami = false;

void konami_check(control_t keys)
{
    static int i = 0;

    if (keys.pressed)
    {
        if (KONAMI_CODE[i] == 'u' && keys.direction == d_up)
            i++;
        else if (KONAMI_CODE[i] == 'd' && keys.direction == d_down)
            i++;
        else if (KONAMI_CODE[i] == 'l' && keys.direction == d_left)
            i++;
        else if (KONAMI_CODE[i] == 'r' && keys.direction == d_right)
            i++;
        else if (KONAMI_CODE[i] == 'a' && keys.A)
            i++;
        else if (KONAMI_CODE[i] == 'b' && keys.B)
            i++;
        else
            i = 0;

        if (i == 10)
        {
            konami = !konami;
            i = 0;
        }
    }
}

bool konami_enabled()
{
    return konami;
}