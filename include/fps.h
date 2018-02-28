/* fps.h -- fps helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __FPS_H__
#define __FPS_H__

#include <libdragon.h>

#include "controls.h"

void fps_check(control_t keys);
void fps_draw(display_context_t disp);
void fps_frame();
void fps_timer();

#endif // __FPS_H__
