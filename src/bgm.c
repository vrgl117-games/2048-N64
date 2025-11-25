/* bgm.c -- bgm helpers implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bgm.h"

#define BGM_CHANNEL 0
#define GAME_VOLUME 1.0f
#define PAUSE_VOLUME 0.33f

static wav64_t bgm_wav;
// current bgm playing 0: not playing; 1,2,3:bgms
static int current_bgm = 0;

void bgm_init()
{
    audio_init(48000, 4);
    mixer_init(8);

    wav64_init_compression(3);
}

static void bgm_open_track(int track)
{
    char path[64];

    if (current_bgm != 0)
    {
        mixer_ch_stop(BGM_CHANNEL);
        wav64_close(&bgm_wav);
    }

    snprintf(path, sizeof(path), "rom:/sfx/bgms/bgm%d.wav64", track);
    wav64_open(&bgm_wav, path);
    wav64_set_loop(&bgm_wav, false);
    wav64_play(&bgm_wav, BGM_CHANNEL);
}

void bgm_pause()
{
    if (current_bgm == 0)
        return;

    mixer_ch_set_vol(BGM_CHANNEL, PAUSE_VOLUME, PAUSE_VOLUME);
}

void bgm_play()
{
    if (current_bgm == 0)
        return;

    mixer_ch_set_vol(BGM_CHANNEL, GAME_VOLUME, GAME_VOLUME);
}

void bgm_start()
{
    current_bgm = 1 + rand() % (NUM_BGMS - 1);

    bgm_open_track(current_bgm);
}

void bgm_stop()
{
    mixer_ch_stop(BGM_CHANNEL);
    wav64_close(&bgm_wav);

    current_bgm = 0;

    mixer_close();
    audio_close();
}

int bgm_toggle(int change)
{
    if (change != 0)
    {
        // if a bgm is already playing, close it
        if (current_bgm != 0)
        {
            mixer_ch_stop(BGM_CHANNEL);
            wav64_close(&bgm_wav);
        }

        // change bgm
        current_bgm += change;

        // handle overflow
        if (current_bgm < 0)
            current_bgm = NUM_BGMS;
        else if (current_bgm > NUM_BGMS)
            current_bgm = 0;

        if (current_bgm != 0)
            bgm_open_track(current_bgm);
    }

    return current_bgm;
}

void bgm_update()
{
    if (audio_can_write())
    {
        int16_t *buf = audio_write_begin();
        mixer_poll(buf, audio_get_buffer_length());
        audio_write_end();
    }

    // Auto-advance when track finishes
    if (current_bgm != 0 && !mixer_ch_playing(BGM_CHANNEL))
    {
        int change = (current_bgm == NUM_BGMS) ? 2 : 1;
        bgm_toggle(change);
    }
}
