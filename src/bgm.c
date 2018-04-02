/* bgm.c -- bgm helpers implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <mikmod.h>
#include "bgm.h"

static MODULE *module = NULL;

void bgm_init()
{
    audio_init(32000, 2);
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
    //MikMod_SetNumVoices(-1, 2);

    /* get ready to play */
    MikMod_EnableOutput();
}

void bgm_start()
{
    if (Player_Active())
        bgm_stop();

    module = Player_Load("rom://filesystem/sfx/bgms/bgm01.bgm", 16, 0);
    Player_Start(module);
    // Player_SetVolume(80);
}

void bgm_stop()
{
    Player_Stop();
    Player_Free(module);
    module = NULL;
}

void bgm_toggle()
{
    Player_TogglePause();
}

void bgm_update()
{
    MikMod_Update();
}