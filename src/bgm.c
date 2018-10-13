/* bgm.c -- bgm helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <mikmod.h>
#include "bgm.h"

static MODULE *bgm;

void bgm_init()
{
    audio_init(44100, 2);
    
    /* register all the drivers */
    MikMod_RegisterAllDrivers();
    MikMod_RegisterAllLoaders();

    /* initialize the library */
    md_mode = 0;
    md_mode |= DMODE_16BITS;
    md_mode |= DMODE_SOFT_MUSIC;
    md_mode |= DMODE_SOFT_SNDFX;
    md_mode |= DMODE_INTERP;

    md_mixfreq = audio_get_frequency();

    MikMod_Init("");

    /* reserve 2 voices for sound effects */
    MikMod_SetNumVoices(-1, 2);

    /* get ready to play */
    MikMod_EnableOutput();

    bgm = Player_Load("rom://sfx/bgms/bgm.xm", 14, 0);
}

void bgm_start()
{
    Player_Start(bgm);
}

void bgm_stop()
{
    Player_Stop();
    Player_Free(bgm);
    bgm = NULL;
}

bool bgm_toggle(bool change)
{
    static bool mode = true;

    if (change) {
        Player_TogglePause();
        mode = !mode;
    }
    return mode;
}

void bgm_update()
{
    MikMod_Update();
}