/* main.c -- main implementation
 *
 * Copyright (C) 2018 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license. See the LICENSE file for details.
 */

#include <stdlib.h>
#include <string.h>

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
extern menu_t menu_difficulty;
extern menu_t menu_game_over;
extern menu_t menu_pause;
extern menu_t menu_you_win;

int main()
{
    init_interrupts();
    display_init(RESOLUTION_640x480, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);

    dfs_init(DFS_DEFAULT_LOCATION);
    rdp_init();
    controller_init();
    timer_init();
    screen_init();
    game_init();
    game_random();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    new_timer(TIMER_TICKS(50000), TF_CONTINUOUS, screen_timer_title);
    display_context_t disp = 0;

    while (true)
    {
        rumble_stop(0);

        if (!(get_controllers_present() & CONTROLLER_1_INSERTED))
            screen_no_controller(disp);
        else
        {

            control_t keys = controls_get_keys();
            fps_check(keys);
            konami_check(keys);

            while (!(disp = display_lock()))
                ;

            switch (screen)
            {
            case intro:
                if (screen_intro(disp))
                    screen = title;
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
                else if (IS_DOWN(keys.start))
                {
                    menu = menu_difficulty;
                }
                screen_title(disp, !menu.visible);
                break;
            case game:
                if (menu.visible)
                    menu_press(&menu, keys);
                else if (IS_DOWN(keys.start))
                {
                    menu = menu_pause;
                }
                else if (keys.direction != d_none)
                {
                    switch (game_play(keys.direction))
                    {
                    case game_win:
                        menu = menu_you_win;
                        break;
                    case game_over:
                        menu = menu_game_over;
                        break;
                    case game_none:
                        break;
                    }
                }

                screen_game(disp);
                break;
            }

            // display menu
            menu_draw(disp, &menu);

            fps_frame();
            fps_draw(disp);
        }
        display_show(disp);
    }

    timer_close();
    rdp_close();
    display_close();
    return 0;
}
