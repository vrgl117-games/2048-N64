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
    struct SI_condat pressed = get_keys_pressed().c[0];

    control_t keys = {0};
    memset(&keys, 0, sizeof(control_t));

    if (!(get_controllers_present() & CONTROLLER_1_INSERTED))
        return keys;

    keys.plugged = true;

    struct controller_data output;
    get_accessories_present(&output);

    if (identify_accessory(0) == ACCESSORY_RUMBLEPAK)
        keys.rumble = true;

    keys.pressed = true;

    if (down.A)
        keys.A = true;
    else if (down.B)
        keys.B = true;
    else if (down.up)
        keys.direction = d_up;
    else if (down.down)
        keys.direction = d_down;
    else if (down.left)
        keys.direction = d_left;
    else if (down.right)
        keys.direction = d_right;
    else if (down.start)
        keys.start = true;
    else if (down.L && down.R)
        keys.fps = true;
    else if (down.L && pressed.R)
        keys.fps = true;
    else if (pressed.L && down.R)
        keys.fps = true;
    else
        keys.pressed = false;

    return keys;
}
