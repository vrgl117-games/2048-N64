/* bgm.h -- bgm helpers header
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#ifndef __BGM_H__
#define __BGM_H__

#include <libdragon.h>

void bgm_init();
void bgm_start();
void bgm_stop();
void bgm_update();

#endif //__BGM_H__