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

#define FREQUENCY_11KHZ 11025
#define FREQUENCY_44KHZ 44100
#define NUM_BGMS 3

void bgm_init();
void bgm_start();
void bgm_stop();
int bgm_toggle(int);
void bgm_play_pause();
void bgm_update();

#endif //__BGM_H__