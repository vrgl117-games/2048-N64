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
#include "debug.h"
#include "dfs.h"

static signed short *buffer;
static int fp;
// current bgm playing 0: not playing; 1,2,3:bgms
static int current_bgm;

void bgm_init()
{
    audio_init(FREQUENCY_44KHZ, 4);
    buffer = malloc(sizeof(signed short) * audio_get_buffer_length() * 2);
    current_bgm = 0;
}

void bgm_start()
{
    current_bgm = 1; // + rand() % (NUM_BGMS - 1);
    fp = dfs_openf("/sfx/bgms/bgm%d.raw", current_bgm);
}

void bgm_stop()
{
    current_bgm = 0;
    dfs_close(fp);
    fp = 0;
    free(buffer);
    audio_close();
}

int bgm_toggle(int change)
{
    if (change != 0)
    {
        // if a bgm is already playing, close it
        if (current_bgm != 0)
            dfs_close(fp);

        // change bgm
        current_bgm += change;

        // handle overflow
        if (current_bgm < 0)
            current_bgm = NUM_BGMS;
        else if (current_bgm > NUM_BGMS)
            current_bgm = 0;

        if (current_bgm != 0)
            fp = dfs_openf("/sfx/bgms/bgm%d.raw", current_bgm);
    }
    return current_bgm;
}

void bgm_update()
{
    if (current_bgm != 0 && audio_can_write())
    {
        int did_read = dfs_read(buffer, sizeof(signed short), audio_get_buffer_length(), fp);
        did_read = did_read / sizeof(signed short);
        //debug_setf("DID_READ: %d BUFF_LEN %d", did_read, audio_get_buffer_length());
        if (dfs_eof(fp))
            bgm_toggle(current_bgm == NUM_BGMS ? 2 : 1);
        // dfs_seek(fp, 0, 0 /*SEEK_SET*/);
        // |a|b|c|d|.|.|.|.|.|.| -> |a|a|b|b|c|c|d|d|.|.|
        for (int i = did_read - 1; i >= 0; i--)
        {
            buffer[(i * 2) + 1] = buffer[i];
            buffer[i * 2] = buffer[i];
        }
        // |a|a|b|b|c|c|d|d|.|.| -> |a|a|b|b|c|c|d|d|0|0|
        //for (int i = did_read; i < buffer_length * 2; i++)
        //    buffer[i] = 0;
        audio_write(buffer);
    }
}
