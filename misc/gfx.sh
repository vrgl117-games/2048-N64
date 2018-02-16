#!/bin/env bash

font='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'

convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:2048 -crop 64x32 resources/gfx/logo-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Press Start" -crop 64x32 resources/gfx/press_start-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Game Over"  resources/gfx/game_over.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 24 label:"Pause"  resources/gfx/pause.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Continue"  resources/gfx/continue.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"> Continue <"  resources/gfx/continue_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"Restart"  resources/gfx/restart.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:"> Restart <"  resources/gfx/restart_selec.png



convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:2 -crop 64x32 resources/gfx/2-%02d.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:4 -crop 64x32 resources/gfx/4-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:8 -crop 64x32 resources/gfx/8-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:16 -crop 64x32  resources/gfx/16-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:32 -crop 64x32  resources/gfx/32-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:64 -crop 64x32  resources/gfx/64-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:128 -crop 64x32  resources/gfx/128-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:256 -crop 64x32  resources/gfx/256-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:512 -crop 64x32  resources/gfx/512-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:1024 -crop 64x32  resources/gfx/1024-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:2048 -crop 64x32  resources/gfx/2048-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:4096 -crop 64x32  resources/gfx/4096-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:8192 -crop 64x32  resources/gfx/8192-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:16384 -crop 64x32  resources/gfx/16384-%02d.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:32768 -crop 64x32  resources/gfx/32768-%02d.png

convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0  resources/gfx/font0.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:1  resources/gfx/font1.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:2  resources/gfx/font2.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:3  resources/gfx/font3.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:4  resources/gfx/font4.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:5  resources/gfx/font5.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:6  resources/gfx/font6.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:7  resources/gfx/font7.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:8  resources/gfx/font8.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0  resources/gfx/font9.png

convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:SCORE  resources/gfx/score.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:BEST  resources/gfx/best.png

convert -brightness-contrast -10 resources/gfx/vrgl117.png resources/gfx/vrgl117_9.png
convert -brightness-contrast -20 resources/gfx/vrgl117.png resources/gfx/vrgl117_8.png
convert -brightness-contrast -30 resources/gfx/vrgl117.png resources/gfx/vrgl117_7.png
convert -brightness-contrast -40 resources/gfx/vrgl117.png resources/gfx/vrgl117_6.png
convert -brightness-contrast -50 resources/gfx/vrgl117.png resources/gfx/vrgl117_5.png
convert -brightness-contrast -60 resources/gfx/vrgl117.png resources/gfx/vrgl117_4.png
convert -brightness-contrast -70 resources/gfx/vrgl117.png resources/gfx/vrgl117_3.png
convert -brightness-contrast -80 resources/gfx/vrgl117.png resources/gfx/vrgl117_2.png
convert -brightness-contrast -90 resources/gfx/vrgl117.png resources/gfx/vrgl117_1.png