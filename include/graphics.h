/* graphics.h -- graphics helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <stdio.h>
#include <libdragon.h>

void graphics_draw_text_center(display_context_t disp, int x, int y, const char *const msg);
void graphics_draw_textf_with_background(display_context_t disp, int x, int y, const char *const format, ...);

#endif //__GRAPHICS_H__