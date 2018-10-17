/* debug.h -- debug helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <libdragon.h>

void debug_clear();
void debug_draw(display_context_t disp);
void debug_setf(const char *const format, ...);

#endif // __DEBUG_H__
