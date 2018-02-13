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
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);

    rdp_init();
    dfs_init(DFS_DEFAULT_LOCATION);
    controller_init();
    timer_init();
    screen_init();
    game_init();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    timer_link_t *timer_press_start = new_timer(TIMER_TICKS(50000), TF_CONTINUOUS, screen_timer_title);
    display_context_t disp = 0;
    screen_t screen = title;
    bool show_fps = false;

    menu_t menu;

    rdp_set_texture_flush(FLUSH_STRATEGY_NONE);

    while (true)
    {
        rumble_stop(0);

        if (!(get_controllers_present() & CONTROLLER_1_INSERTED))
        {
            screen_no_controller(disp);
        }
        else
        {
            control_t keys = controls_get_keys();
            if (IS_DOWN(keys.Z))
            {
                show_fps = !show_fps;
            }

            while (!(disp = display_lock()))
                ;

            switch (screen)
            {
            case title:
                screen_title(disp);
                if (IS_DOWN(keys.start))
                {
                    delete_timer(timer_press_start);
                    screen = game;
                }
                break;
            case game:
                if (menu.visible)
                {
                    int pressed = menu_press(&menu, keys);
                    if (pressed != -1 && strcmp(menu.options[pressed], "restart") == 0)
                    {
                        game_reset();
                    }
                }
                else if (IS_DOWN(keys.start))
                {
                    menu.title = "pause";
                    menu.options_size = 2;
                    menu.options[0] = "continue";
                    menu.options[1] = "restart";
                    menu.default_option = 0;
                    menu.visible = true;
                }
                else if (keys.direction != d_none)
                {
                    if (game_play(keys.direction))
                    {
                        menu.title = "game_over";
                        menu.options_size = 1;
                        menu.options[0] = "restart";
                        menu.default_option = 0;
                        menu.visible = true;
                    }
                }

                screen_game(disp, &menu);
                break;
            }

            fps_frame();
            if (show_fps)
            {
                graphics_draw_textf_with_background(disp, 4, 4, "FPS: %d", fps_get());
            }
        }
        display_show(disp);
    }

    timer_close();
    rdp_close();
    display_close();
    return 0;
}