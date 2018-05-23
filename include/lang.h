/* lang.h -- lang helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __LANG_H__
#define __LANG_H__

#include <libdragon.h>

#include "controls.h"

bool lang_press(control_t keys);
int lang_selected();
char *lang_selected_str();

#endif // __LANG_H__
