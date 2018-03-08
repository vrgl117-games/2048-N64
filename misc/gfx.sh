#!/bin/env bash

font='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'
fontr='misc/font/clearsans-1.00/TTF/ClearSans-Regular.ttf'

#UI
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:2048 -crop 64x32 resources/gfx/maps/logo-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Press Start" -crop 64x32 resources/gfx/maps/press_start-%02d.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:SCORE resources/gfx/sprites/score.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:BEST resources/gfx/sprites/best.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 10 label:"version: 0.9" resources/gfx/sprites/version.png

#menu
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Game Over" resources/gfx/sprites/title_game_over.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"You Win!" resources/gfx/sprites/title_you_win.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Pause" resources/gfx/sprites/title_pause.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Difficulty" resources/gfx/sprites/title_difficulty.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"About" resources/gfx/sprites/title_about.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continue" resources/gfx/sprites/continue.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Continue" resources/gfx/sprites/continue_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Restart" resources/gfx/sprites/restart.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Restart" resources/gfx/sprites/restart_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"About" resources/gfx/sprites/about.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"About" resources/gfx/sprites/about_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Back" resources/gfx/sprites/back.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Back" resources/gfx/sprites/back_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Easy" resources/gfx/sprites/easy.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Easy" resources/gfx/sprites/easy_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Normal" resources/gfx/sprites/normal.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Normal" resources/gfx/sprites/normal_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Hard" resources/gfx/sprites/hard.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Hard" resources/gfx/sprites/hard_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Original game created\nby Gabriele Cirulli,\nN64 version by vrgl117." resources/gfx/sprites/text_about.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Join the numbers\nand get to the\n2048 tile!" resources/gfx/sprites/text_help.png

#screen
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:"NO CONTROLLER INSERTED ON PORT #1" resources/gfx/sprites/no_controller.png

#grid
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:2 -crop 64x32 resources/gfx/maps/2-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:4 -crop 64x32 resources/gfx/maps/4-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:8 -crop 64x32 resources/gfx/maps/8-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:16 -crop 64x32 resources/gfx/maps/16-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:32 -crop 64x32 resources/gfx/maps/32-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:64 -crop 64x32 resources/gfx/maps/64-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:128 -crop 64x32 resources/gfx/maps/128-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:256 -crop 64x32 resources/gfx/maps/256-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:512 -crop 64x32 resources/gfx/maps/512-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:1024 -crop 64x32 resources/gfx/maps/1024-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:2048 -crop 64x32 resources/gfx/maps/2048-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:4096 -crop 64x32 resources/gfx/maps/4096-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:8192 -crop 64x32 resources/gfx/maps/8192-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:16384 -crop 64x32 resources/gfx/maps/16384-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:32768 -crop 64x32 resources/gfx/maps/32768-%02d.png

#font
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0 resources/gfx/maps/font0.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:1 resources/gfx/maps/font1.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:2 resources/gfx/maps/font2.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:3 resources/gfx/maps/font3.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:4 resources/gfx/maps/font4.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:5 resources/gfx/maps/font5.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:6 resources/gfx/maps/font6.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:7 resources/gfx/maps/font7.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:8 resources/gfx/maps/font8.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:9 resources/gfx/maps/font9.png

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