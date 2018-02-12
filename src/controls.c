/* controls.c -- controls helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <string.h>

#include "controls.h"

control_t controls_get_keys()
{
    controller_scan();
    struct SI_condat held = get_keys_held().c[0];
    struct SI_condat up = get_keys_up().c[0];
    struct SI_condat down = get_keys_down().c[0];

    control_t keys;
    memset(&keys, 0, sizeof(control_t));

    if (held.Z)
    {
        keys.Z = HELD;
    }
    else if (down.Z)
    {
        keys.Z = DOWN;
    }
    else if (up.Z)
    {
        keys.Z = UP;
    }

    if (held.A)
    {
        keys.A = HELD;
    }
    else if (down.A)
    {
        keys.A = DOWN;
    }
    else if (up.A)
    {
        keys.A = UP;
    }

    if (held.B)
    {
        keys.B = HELD;
    }
    else if (down.B)
    {
        keys.B = DOWN;
    }
    else if (up.B)
    {
        keys.B = UP;
    }

    if (held.C_up || held.up || held.y > 0)
    {
        keys.up = HELD;
    }
    else if (down.C_up || down.up || down.y > 0)
    {
        keys.direction = d_up;
        keys.up = DOWN;
    }
    else if (up.C_up || up.up || up.y > 0)
    {
        keys.up = UP;
    }

    if (held.C_down || held.down || held.y < 0)
    {
        keys.down = HELD;
    }
    else if (down.C_up || down.down || down.y < 0)
    {
        keys.direction = d_down;
        keys.down = DOWN;
    }
    else if (up.C_down || up.down || down.y < 0)
    {
        keys.down = UP;
    }

    if (held.C_left || held.left || held.x < -20)
    {
        keys.left = HELD;
    }
    else if (down.C_left || down.left || down.x < -20)
    {
        keys.direction = d_left;
        keys.left = DOWN;
    }
    else if (up.C_left || up.left || down.x < -20)
    {
        keys.left = UP;
    }

    if (held.C_right || held.right || held.x > 20)
    {
        keys.right = HELD;
    }
    else if (down.C_right || down.right || down.x > 20)
    {
        keys.direction = d_right;
        keys.right = DOWN;
    }
    else if (up.C_right || up.right || down.x > 20)
    {
        keys.right = UP;
    }

    if (held.start)
    {
        keys.start = HELD;
    }
    else if (down.start)
    {
        keys.start = DOWN;
    }
    else if (down.start)
    {
        keys.start = UP;
    }

    return keys;
}
