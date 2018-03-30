#!/usr/bin/env bash

fontb='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'
fontr='misc/font/clearsans-1.00/TTF/ClearSans-Regular.ttf'

#UI
convert resources/gfx/sprites/logo.png -crop 64x32 resources/gfx/maps/logo-%02d.png
convert -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Press Start" -crop 64x32 resources/gfx/maps/press_start-%02d.png
convert -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:SCORE -shave 0x1 resources/gfx/sprites/score.png
convert -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:BEST -shave 0x1 resources/gfx/sprites/best.png
convert -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 10 label:"version: 0.9" resources/gfx/sprites/version.png

#menu
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Game Over" resources/gfx/sprites/title_game_over.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"You Win!" resources/gfx/sprites/title_you_win.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pause" resources/gfx/sprites/title_pause.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"New Game" resources/gfx/sprites/title_new_game.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"About" resources/gfx/sprites/title_about.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continue" resources/gfx/sprites/continue.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continue" resources/gfx/sprites/continue_selec.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Restart" resources/gfx/sprites/restart.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Restart" resources/gfx/sprites/restart_selec.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"About" resources/gfx/sprites/about.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"About" resources/gfx/sprites/about_selec.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Back" resources/gfx/sprites/back.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Back" resources/gfx/sprites/back_selec.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Original game created\nby Gabriele Cirulli,\nN64 version by vrgl117." resources/gfx/sprites/text_about.png
convert -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Join the numbers and get to the 2048 tile!\n\n\nThis game is Rumble Pak compatible. Please insert\nyour Rumble Pak now if you wish to play with it." resources/gfx/sprites/text_help.png

#screen
convert -background "#faf8efff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:"NO CONTROLLER INSERTED ON PORT #1" resources/gfx/sprites/no_controller.png

#grid
convert -background "#EEE4DAff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:2 -crop 64x32 resources/gfx/maps/2-%02d.png
convert -background "#EDE0C8ff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:4 -crop 64x32 resources/gfx/maps/4-%02d.png
convert -background "#F2B179ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:8 -crop 64x32 resources/gfx/maps/8-%02d.png
convert -background "#F59563ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:16 -crop 64x32 resources/gfx/maps/16-%02d.png
convert -background "#F67C5Fff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:32 -crop 64x32 resources/gfx/maps/32-%02d.png
convert -background "#F45E43ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:64 -crop 64x32 resources/gfx/maps/64-%02d.png
convert -background "#ECCE78ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:128 -crop 64x32 resources/gfx/maps/128-%02d.png
convert -background "#ECCB69ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:256 -crop 64x32 resources/gfx/maps/256-%02d.png
convert -background "#ECC75Aff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:512 -crop 64x32 resources/gfx/maps/512-%02d.png
convert -background "#ECC44Cff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:1024 -crop 64x32 resources/gfx/maps/1024-%02d.png
convert -background "#EDC22Eff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:2048 -crop 64x32 resources/gfx/maps/2048-%02d.png
convert -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:4096 -crop 64x32 resources/gfx/maps/4096-%02d.png
convert -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:8192 -crop 64x32 resources/gfx/maps/8192-%02d.png
convert -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:16384 -crop 64x32 resources/gfx/maps/16384-%02d.png
convert -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:32768 -crop 64x32 resources/gfx/maps/32768-%02d.png

#font
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:0 -shave 0x4 resources/gfx/maps/font0.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:1 -shave 0x4 resources/gfx/maps/font1.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:2 -shave 0x4 resources/gfx/maps/font2.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:3 -shave 0x4 resources/gfx/maps/font3.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:4 -shave 0x4 resources/gfx/maps/font4.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:5 -shave 0x4 resources/gfx/maps/font5.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:6 -shave 0x4 resources/gfx/maps/font6.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:7 -shave 0x4 resources/gfx/maps/font7.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:8 -shave 0x4 resources/gfx/maps/font8.png
convert -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:9 -shave 0x4 resources/gfx/maps/font9.png

#logo
convert -brightness-contrast -10 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_9.png
convert -brightness-contrast -20 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_8.png
convert -brightness-contrast -30 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_7.png
convert -brightness-contrast -40 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_6.png
convert -brightness-contrast -50 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_5.png
convert -brightness-contrast -60 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_4.png
convert -brightness-contrast -70 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_3.png
convert -brightness-contrast -80 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_2.png
convert -brightness-contrast -90 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_1.png


convert -brightness-contrast -10 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_9.png
convert -brightness-contrast -20 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_8.png
convert -brightness-contrast -30 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_7.png
convert -brightness-contrast -40 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_6.png
convert -brightness-contrast -50 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_5.png
convert -brightness-contrast -60 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_4.png
convert -brightness-contrast -70 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_3.png
convert -brightness-contrast -80 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_2.png
convert -brightness-contrast -90 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_1.png