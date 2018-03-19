/* controls.h -- controls helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include <libdragon.h>

typedef enum direction {
    d_none,
    d_up,
    d_down,
    d_left,
    d_right
} direction_t;

typedef struct
{
    bool Z;
    bool A;
    bool B;
    bool start;
    bool L;
    bool R;

    bool pressed;
    bool plugged;
    bool rumble;

    direction_t direction;

} control_t;

control_t controls_get_keys();

#endif //__CONTROLS_H__