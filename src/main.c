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

static screen_t screen = intro;
static menu_t menu;

static inline void option_easy()
{
    game_set_difficulty(game_easy);
    game_reset();
    screen = game;
}

static inline void option_normal()
{
    game_set_difficulty(game_normal);
    game_reset();
    screen = game;
}

static inline void option_hard()
{
    game_set_difficulty(game_hard);
    game_reset();
    screen = game;
}
static inline void option_about();
static inline void option_back()
{
    menu.title = "title_pause";
    menu.text = NULL;
    menu.options_size = 3;
    menu.options[0] = (option_t){.text = "continue", .action = NULL, .close = true};
    menu.options[1] = (option_t){.text = "restart", .action = game_reset, .close = true};
    menu.options[2] = (option_t){.text = "about", .action = option_about, .close = false};
    menu.selected_option = 2;
}

static inline void option_about()
{
    menu.title = "title_about";
    menu.text = "text_about";
    menu.options_size = 1;
    menu.options[0] = (option_t){.text = "back", .action = option_back, .close = false};
    menu.selected_option = 0;
}

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
                    menu_press(&menu, keys);
                else if (IS_DOWN(keys.start))
                {
                    menu.title = "title_difficulty";
                    menu.text = NULL;
                    menu.options_size = 3;
                    menu.options[0] = (option_t){.text = "easy", .action = option_easy, .close = true};
                    menu.options[1] = (option_t){.text = "normal", .action = option_normal, .close = true};
                    menu.options[2] = (option_t){.text = "hard", .action = option_hard, .close = true};
                    menu.selected_option = 1;
                    menu.visible = true;
                    menu.width = 0;
                    menu.height = 0;
                }
                screen_title(disp, !menu.visible);
                break;
            case game:
                if (menu.visible)
                    menu_press(&menu, keys);
                else if (IS_DOWN(keys.start))
                {
                    menu.title = "title_pause";
                    menu.text = NULL;
                    menu.options_size = 3;
                    menu.options[0] = (option_t){.text = "continue", .action = NULL, .close = true};
                    menu.options[1] = (option_t){.text = "restart", .action = game_reset, .close = true};
                    menu.options[2] = (option_t){.text = "about", .action = option_about, .close = true};
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
                        menu.options[0] = (option_t){.text = "continue", .action = NULL, .close = true};
                        menu.options[1] = (option_t){.text = "restart", .action = game_reset, .close = true};
                        menu.selected_option = 0;
                        menu.visible = true;
                        menu.width = 0;
                        menu.height = 0;
                        break;
                    case game_over:
                        menu.title = "title_game_over";
                        menu.text = NULL;
                        menu.options_size = 1;
                        menu.options[0] = (option_t){.text = "restart", .action = game_reset, .close = true};
                        menu.selected_option = 0;
                        menu.visible = true;
                        menu.width = 0;
                        menu.height = 0;
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
