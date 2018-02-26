#!/bin/env bash

font='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'
fontr='misc/font/clearsans-1.00/TTF/ClearSans-Regular.ttf'

#UI
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:2048 -crop 64x32 resources/gfx/16/logo-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Press Start" -crop 64x32 resources/gfx/16/press_start-%02d.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:SCORE resources/gfx/16/score.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:BEST resources/gfx/16/best.png

#menu
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Game Over" resources/gfx/32/title_game_over.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"You Win!" resources/gfx/32/title_you_win.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Pause" resources/gfx/32/title_pause.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"About" resources/gfx/32/title_about.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continue" resources/gfx/32/continue.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Continue" resources/gfx/32/continue_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Restart" resources/gfx/32/restart.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Restart" resources/gfx/32/restart_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"About" resources/gfx/32/about.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"About" resources/gfx/32/about_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Back" resources/gfx/32/back.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Back" resources/gfx/32/back_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Original game created by\nGabriele Cirulli, N64\nversion by vrgl117." resources/gfx/32/text_about.png

#screen
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:"NO CONTROLLER INSERTED ON PORT #1" resources/gfx/32/no_controller.png

#grid
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:2 -crop 64x32 resources/gfx/16/2-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:4 -crop 64x32 resources/gfx/16/4-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:8 -crop 64x32 resources/gfx/16/8-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:16 -crop 64x32 resources/gfx/16/16-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:32 -crop 64x32 resources/gfx/16/32-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:64 -crop 64x32 resources/gfx/16/64-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:128 -crop 64x32 resources/gfx/16/128-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:256 -crop 64x32 resources/gfx/16/256-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:512 -crop 64x32 resources/gfx/16/512-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:1024 -crop 64x32 resources/gfx/16/1024-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:2048 -crop 64x32 resources/gfx/16/2048-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:4096 -crop 64x32 resources/gfx/16/4096-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:8192 -crop 64x32 resources/gfx/16/8192-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:16384 -crop 64x32 resources/gfx/16/16384-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:32768 -crop 64x32 resources/gfx/16/32768-%02d.png

#font
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0 resources/gfx/16/font0.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:1 resources/gfx/16/font1.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:2 resources/gfx/16/font2.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:3 resources/gfx/16/font3.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:4 resources/gfx/16/font4.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:5 resources/gfx/16/font5.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:6 resources/gfx/16/font6.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:7 resources/gfx/16/font7.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:8 resources/gfx/16/font8.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0 resources/gfx/16/font9.png

#logo
convert -brightness-contrast -10 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_9.png
convert -brightness-contrast -20 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_8.png
convert -brightness-contrast -30 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_7.png
convert -brightness-contrast -40 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_6.png
convert -brightness-contrast -50 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_5.png
convert -brightness-contrast -60 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_4.png
convert -brightness-contrast -70 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_3.png
convert -brightness-contrast -80 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_2.png
convert -brightness-contrast -90 resources/gfx/32/vrgl117.png resources/gfx/32/vrgl117_1.png