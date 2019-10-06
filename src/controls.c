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
    struct SI_condat down = get_keys_down().c[0];

    control_t keys = {0};
    memset(&keys, 0, sizeof(control_t));

    if (!(get_controllers_present() & CONTROLLER_1_INSERTED))
        return keys;

    keys.plugged = true;

    struct controller_data output;
    get_accessories_present(&output);

    if (identify_accessory(0) == ACCESSORY_RUMBLEPAK)
        keys.rumble = true;

    if (down.Z)
    {
        keys.Z = true;
        keys.pressed = true;
    }

    if (down.A)
    {
        keys.A = true;
        keys.pressed = true;
    }

    if (down.B)
    {
        keys.B = true;
        keys.pressed = true;
    }

    if (down.up)
    {
        keys.direction = d_up;
        keys.pressed = true;
    }

    if (down.down)
    {
        keys.direction = d_down;
        keys.pressed = true;
    }

    if (down.left)
    {
        keys.direction = d_left;
        keys.pressed = true;
    }

    if (down.right)
    {
        keys.direction = d_right;
        keys.pressed = true;
    }

    if (down.start)
    {
        keys.start = true;
        keys.pressed = true;
    }

    if (down.L)
    {
        keys.L = true;
        keys.pressed = true;
    }

    if (down.R)
    {
        keys.R = true;
        keys.pressed = true;
    }

    return keys;
}
