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
#include "menus.h"
#include "screens.h"

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
    screen_t screen = intro;

    menu_t menu;

    while (true)
    {

        rumble_stop(0);

        if (!(get_controllers_present() & CONTROLLER_1_INSERTED))
            screen_no_controller(disp);
        else
        {
            control_t keys = controls_get_keys();
            if (IS_DOWN(keys.Z) && IS_DOWN(keys.L) && IS_DOWN(keys.R))
                fps_switch();

            while (!(disp = display_lock()))
                ;

            switch (screen)
            {
            case intro:
                if (screen_intro(disp))
                    screen = title;
                break;
            case title:
                screen_title(disp, &menu);
                if (menu.visible)
                {
                    int pressed = menu_press(&menu, keys);
                    if (pressed != -1)
                    {
                        if (strcmp(menu.options[pressed], "easy") == 0)
                            game_set_difficulty(game_easy);

                        if (strcmp(menu.options[pressed], "normal") == 0)
                            game_set_difficulty(game_normal);

                        if (strcmp(menu.options[pressed], "hard") == 0)
                            game_set_difficulty(game_hard);

                        screen = game;
                        game_reset();
                    }
                }
                else if (IS_DOWN(keys.start))
                {
                    menu.title = "title_difficulty";
                    menu.text = NULL;
                    menu.options_size = 3;
                    menu.options[0] = "easy";
                    menu.options[1] = "normal";
                    menu.options[2] = "hard";
                    menu.selected_option = 1;
                    menu.visible = true;
                    menu.width = 0;
                    menu.height = 0;
                }
                break;
            case game:
                if (menu.visible)
                {
                    int pressed = menu_press(&menu, keys);
                    if (pressed != -1)
                    {
                        if (strcmp(menu.options[pressed], "restart") == 0)
                            game_reset();

                        if (strcmp(menu.options[pressed], "about") == 0)
                        {
                            menu.title = "title_about";
                            menu.text = "text_about";
                            menu.options_size = 1;
                            menu.options[0] = "back";
                            menu.selected_option = 0;
                        }

                        if (strcmp(menu.options[pressed], "back") == 0)
                        {
                            menu.title = "title_pause";
                            menu.text = NULL;
                            menu.options_size = 3;
                            menu.options[0] = "continue";
                            menu.options[1] = "restart";
                            menu.options[2] = "about";
                            menu.selected_option = 2;
                        }
                    }
                }
                else if (IS_DOWN(keys.start))
                {
                    menu.title = "title_pause";
                    menu.text = NULL;
                    menu.options_size = 3;
                    menu.options[0] = "continue";
                    menu.options[1] = "restart";
                    menu.options[2] = "about";
                    menu.selected_option = 0;
                    menu.visible = true;
                    menu.width = 0;
                    menu.height = 0;
                }
                else if (keys.direction != d_none)
                {
                    switch (game_play(keys.direction))
                    {
                    case game_win:
                        menu.title = "title_you_win";
                        menu.text = NULL;
                        menu.options_size = 2;
                        menu.options[0] = "continue";
                        menu.options[1] = "restart";
                        menu.selected_option = 0;
                        menu.visible = true;
                        menu.width = 0;
                        menu.height = 0;
                        break;
                    case game_over:
                        menu.title = "title_game_over";
                        menu.text = NULL;
                        menu.options_size = 1;
                        menu.options[0] = "restart";
                        menu.selected_option = 0;
                        menu.visible = true;
                        menu.width = 0;
                        menu.height = 0;
                        break;
                    case game_none:
                        break;
                    }
                }

                screen_game(disp, &menu);
                break;
            }

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
