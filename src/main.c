/* main.c -- main implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>
#include <string.h>

#include "bgm.h"
#include "colors.h"
#include "controls.h"
#include "dfs.h"
#include "fps.h"
#include "game.h"
#include "graphics.h"
#include "konami.h"
#include "menus.h"
#include "screens.h"

screen_t screen = intro;
menu_t menu;
extern menu_t menu_new_game;
extern menu_t menu_game_over;
extern menu_t menu_pause;
extern menu_t menu_you_win;

int main()
{
    init_interrupts();
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);

    dfs_init(DFS_DEFAULT_LOCATION);
    rdp_init();
    controller_init();
    timer_init();
    bgm_init();
    screen_init("fr");
    game_init();
    game_random();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    new_timer(TIMER_TICKS(50000), TF_CONTINUOUS, screen_timer_title);
    display_context_t disp = 0;

    while (true)
    {
        control_t keys = controls_get_keys();
        fps_check(keys);

        if (keys.rumble && game_stop_rumble())
            rumble_stop(0);

        while (!(disp = display_lock()))
            ;

        if (!keys.plugged)
            screen_no_controller(disp);
        else
        {
            switch (screen)
            {
            case intro:
                if (screen_intro(disp))
                {
                    bgm_start();
                    screen = title;
                }
                break;
            case title:
                if (menu.visible)
                {
                    if (menu_press(&menu, keys))
                    {
                        game_reset();
                        screen = game;
                    }
                }
                else if (keys.start)
                    menu = menu_new_game;

                konami_check(keys);
                screen_title(disp, !menu.visible, "fr");
                break;
            case game:
                if (menu.visible)
                    menu_press(&menu, keys);
                else if (keys.start)
                {
                    bgm_toggle();
                    menu = menu_pause;
                }
                else
                {
                    status_t status = game_play(keys);
                    if (status == game_win)
                        menu = menu_you_win;
                    if (status == game_over)
                        menu = menu_game_over;
                }

                screen_game(disp);
                break;
            }

            // display menu
            menu_draw(disp, &menu, "fr");

            // increment fps counter
            fps_frame();

            // display fps
            fps_draw(disp);
        }
        display_show(disp);
        bgm_update();
    }

    // cleanup, never called
    bgm_stop();
    audio_close();
    timer_close();
    rdp_close();
    display_close();
    return 0;
}
