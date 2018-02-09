#!/bin/env bash

font='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'

convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:2048  resources/gfx/logo.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:2  resources/gfx/logo_2.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:0  resources/gfx/logo_0.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:4  resources/gfx/logo_4.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 48 label:8  resources/gfx/logo_8.png

convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Press Start"  resources/gfx/press_start.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Game Over"  resources/gfx/game_over.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Continue"  resources/gfx/continue.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"> Continue <"  resources/gfx/continue_selec.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"Restart"  resources/gfx/restart.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:"> Restart <"  resources/gfx/restart_selec.png



convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:2  resources/gfx/2.png
convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 36 label:4  resources/gfx/4.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:8  resources/gfx/8.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:16  resources/gfx/16.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:32  resources/gfx/32.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 36 label:64  resources/gfx/64.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:128  resources/gfx/128.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:256  resources/gfx/256.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 32 label:512  resources/gfx/512.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:1024  resources/gfx/1024.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:2048  resources/gfx/2048.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:4096  resources/gfx/4096.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 28 label:8192  resources/gfx/8192.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:16384  resources/gfx/16384.png
convert -background "#ffffff00" -fill "#F9F6F2ff" -font "$font" -pointsize 24 label:32768  resources/gfx/32768.png

convert -background "#ffffff00" -fill "#776E65ff" -font "$font" -pointsize 18 label:0123456789  resources/gfx/font.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:SCORE  resources/gfx/score.png
convert -background "#ffffff00" -fill "#EEE4DAff" -font "$font" -pointsize 14 label:BEST  resources/gfx/best.png
