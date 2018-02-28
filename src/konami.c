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

    switch (KONAMI_CODE[i])
    {
    case 'u':
        if (IS_DOWN(keys.up))
            i++;
    case 'd':
        if (IS_DOWN(keys.down))
            i++;
    case 'l':
        if (IS_DOWN(keys.left))
            i++;
    case 'r':
        if (IS_DOWN(keys.right))
            i++;
    case 'b':
        if (IS_DOWN(keys.B))
            i++;
    case 'a':
        if (IS_DOWN(keys.A))
            i++;
    }

    if (i == 10)
    {
        konami = !konami;
        i = 0;
    }
}

bool konami_enabled()
{
    return konami;
}