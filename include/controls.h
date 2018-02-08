/* controls.h -- controls helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include <libdragon.h>
#include "game.h"

typedef struct
{
    uint8_t Z;
    uint8_t A;
    uint8_t B;
    uint8_t up;
    uint8_t down;
    uint8_t left;
    uint8_t right;
    uint8_t start;

    direction_t direction;

} control_t;

#define HELD 1
#define DOWN 2
#define UP 3

#define IS_HELD(K) (K == HELD)
#define IS_DOWN(K) (K == DOWN)
#define IS_UP(K) (K == UP)
#define IS_PRESSED(K) (IS_HELD(K) || IS_DOWN(K))

control_t controls_get_keys();

#endif //__CONTROLS_H__