/* main.c -- main implementation
 *
 * Copyright (C) 2018-2025 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>
#include "bgm.h"
#include "colors.h"
#include "controls.h"
#include "fps.h"
#include "font.h"
#include "game.h"
#include "konami.h"
#include "lang.h"
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
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE_ANTIALIAS);
    colors_init();
    dfs_init(DFS_DEFAULT_LOCATION);
    rdpq_init();
    font_init();
    joypad_init();
    timer_init();
    bgm_init();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    new_timer(TIMER_TICKS(50000), TF_CONTINUOUS, screen_timer_title);
    surface_t *disp = NULL;

    while (true)
    {
        // get the keys pressed.
        control_t keys = controls_get_keys();

        // display/hide the FPS count.
        fps_check(keys);

        // stop rumble if needed.
        if (keys.rumble && game_stop_rumble())
            joypad_set_rumble_active(JOYPAD_PORT_1, false);

        // wait for the screen to be availalble.
        while (!(disp = display_try_get()))
            ;
        // display no controller screen is there are node plugged in.
        if (!keys.plugged)
            screen_no_controller(disp);
        else
        {
            switch (screen) // state machine for the screens. intro -> lang -> title -> game.
            {
            case intro: // n64 logo and vrgl117 logo.
                if (screen_intro(disp))
                    screen = lang;
                break;
            case lang: // flags.
                if (lang_press(keys))
                {
                    screen_init();
                    game_init();
                    game_random();
                    screen = title;
                    bgm_start();
                    break;
                }
                screen_lang(disp);
                break;
            case title: // press start.
                if (menu.visible)
                {
                    if (menu_press(&menu, keys))
                    {
                        game_reset();
                        screen = game;
                        break;
                    }
                }
                else if (keys.start)
                    menu = menu_new_game;

                // check for konami code.
                konami_check(keys);
                screen_title(disp, !menu.visible);
                break;
            case game: // actual game.
                if (menu.visible)
                    menu_press(&menu, keys);
                else if (keys.start)
                {
                    bgm_pause();
                    menu = menu_pause;
                }
                else
                {
                    status_t status = game_play(keys);
                    if (status == game_win)
                        menu = menu_you_win;
                    else if (status == game_over)
                        menu = menu_game_over;
                }

                screen_game(disp);
                break;
            }

            // display menu
            menu_draw(disp, &menu);

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
    // audio_close();
    timer_close();
    rdpq_close();
    display_close();
    return 0;
}
