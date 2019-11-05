/* bgm.c -- bgm helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>
#include <strings.h>

#include "bgm.h"
#include "dfs.h"

#include "debug.h"

#define DR_MP3_IMPLEMENTATION
#include "dr_mp3.h"

static signed short *buffer;
static drmp3 mp3;
// current bgm playing 0: not playing; 1,2,3:bgms
static int current_bgm;
static bool paused = false;

static char *files[] = {"rom://sfx/bgms/bgm1.mp3", "rom://sfx/bgms/bgm2.mp3", "rom://sfx/bgms/bgm3.mp3"};

void bgm_init()
{
    audio_init(FREQUENCY_44KHZ, 8);
    buffer = malloc(sizeof(signed short) * audio_get_buffer_length() * 2);
    current_bgm = 0;
}

void bgm_start()
{
    current_bgm = 1 + rand() % (NUM_BGMS - 1);

    drmp3_init_file(&mp3, files[current_bgm - 1], NULL, NULL);
    paused = false;
}

void bgm_stop()
{
    current_bgm = 0;
    drmp3_uninit(&mp3);
    free(buffer);
    audio_close();
}

int bgm_toggle(int change)
{
    if (change != 0)
    {
        // if a bgm is already playing, close it
        if (current_bgm != 0)
            drmp3_uninit(&mp3);

        // change bgm
        current_bgm += change;

        // handle overflow
        if (current_bgm < 0)
            current_bgm = NUM_BGMS;
        else if (current_bgm > NUM_BGMS)
            current_bgm = 0;

        if (current_bgm != 0)
            drmp3_init_file(&mp3, files[current_bgm - 1], NULL, NULL);
    }
    return current_bgm;
}

void bgm_play_pause()
{
    paused = !paused;
}

void bgm_update()
{
    if (!paused && current_bgm != 0 && audio_can_write())
    {
        drmp3_uint64 framesToReadRightNow = audio_get_buffer_length();
        drmp3_uint64 framesJustRead = drmp3_read_pcm_frames_s16(&mp3, framesToReadRightNow, buffer);
        if (framesJustRead == 0)
        {
            return;
        }
        // |a|b|c|d|.|.|.|.|.|.| -> |a|a|b|b|c|c|d|d|.|.|
        for (int i = framesJustRead - 1; i >= 0; i--)
        {
            buffer[(i * 2) + 1] = buffer[i];
            buffer[i * 2] = buffer[i];
        }

        audio_write(buffer);
        // debug_setf("size: %d read: %d", audio_get_buffer_length(), did_read);
    }
}
