/* konami.h -- konami helpers header
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __KONAMI_H__
#define __KONAMI_H__

#include "controls.h"

void konami_check(control_t keys);
bool konami_enabled();

#endif // __KONAMI_H__
