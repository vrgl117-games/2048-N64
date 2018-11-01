#!/usr/bin/env bash

fontb='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'
fontr='misc/font/clearsans-1.00/TTF/ClearSans-Regular.ttf'

#UI
convert -strip resources/gfx/sprites/logo.png -crop 32 resources/gfx/maps/logo-%d_0.png
convert -strip -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Press Start" -gravity center -extent 186x64 -crop 32 resources/gfx/maps/en/press_start-%d_0.png
convert -strip -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Appuyez sur Start" -gravity center -extent 300x64 -crop 32 resources/gfx/maps/fr/press_start-%d_0.png
convert -strip -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Pulsa Start" -gravity center -extent 186x64 -crop 32 resources/gfx/maps/es/press_start-%d_0.png

convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:SCORE -gravity north -extent 44x32 resources/gfx/sprites/en/score.png
convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:SCORE -gravity north -extent 44x32 resources/gfx/sprites/fr/score.png
convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:SCORE -gravity north -extent 44x32 resources/gfx/sprites/es/score.png

convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:BEST -gravity north -extent 34x32 resources/gfx/sprites/en/best.png
convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:TOP -gravity north -extent 26x32 resources/gfx/sprites/fr/best.png
convert -strip -background "#CDC1B4ff" -fill "#EEE4DAff" -font "$fontb" -pointsize 14 label:BEST -gravity north -extent 34x32 resources/gfx/sprites/es/best.png

convert -strip -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 10 label:"version: 1.0" -gravity center -extent 56x16 resources/gfx/sprites/version.png

#menu
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Game Over" resources/gfx/sprites/en/title_game_over.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Partie Terminée" resources/gfx/sprites/fr/title_game_over.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Fin del juego" resources/gfx/sprites/es/title_game_over.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"You Win!" resources/gfx/sprites/en/title_you_win.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Gagné !" resources/gfx/sprites/fr/title_you_win.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"¡Exito!" resources/gfx/sprites/es/title_you_win.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pause" resources/gfx/sprites/en/title_pause.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pause" resources/gfx/sprites/fr/title_pause.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pausa" resources/gfx/sprites/es/title_pause.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"New Game" resources/gfx/sprites/en/title_new_game.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Nouvelle Partie" resources/gfx/sprites/fr/title_new_game.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Nuevo juego" resources/gfx/sprites/es/title_new_game.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Credits" resources/gfx/sprites/en/title_credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Crédits" resources/gfx/sprites/fr/title_credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Créditos" resources/gfx/sprites/es/title_credits.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continue" resources/gfx/sprites/en/continue.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continuer" resources/gfx/sprites/fr/continue.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continuar" resources/gfx/sprites/es/continue.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continue" resources/gfx/sprites/en/continue_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continuer" resources/gfx/sprites/fr/continue_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continuar" resources/gfx/sprites/es/continue_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Music: Track #1  " resources/gfx/sprites/en/music_1.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musique: Track #1  " resources/gfx/sprites/fr/music_1.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musica: Track #1  " resources/gfx/sprites/es/music_1.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #1 >" resources/gfx/sprites/en/music_1_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Track #1 >" resources/gfx/sprites/fr/music_1_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Track #1 >" resources/gfx/sprites/es/music_1_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Music: Track #2  " resources/gfx/sprites/en/music_2.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musique: Track #2  " resources/gfx/sprites/fr/music_2.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musica: Track #2  " resources/gfx/sprites/es/music_2.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #2 >" resources/gfx/sprites/en/music_2_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Track #2 >" resources/gfx/sprites/fr/music_2_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Track #2 >" resources/gfx/sprites/es/music_2_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Music: Track #3  " resources/gfx/sprites/en/music_3.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musique: Track #3  " resources/gfx/sprites/fr/music_3.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musica: Track #3  " resources/gfx/sprites/es/music_3.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #3 >" resources/gfx/sprites/en/music_3_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Track #3 >" resources/gfx/sprites/fr/music_3_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Track #3 >" resources/gfx/sprites/es/music_3_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Music: OFF  " resources/gfx/sprites/en/music_0.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musique: OFF  " resources/gfx/sprites/fr/music_0.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"  Musica: OFF  " resources/gfx/sprites/es/music_0.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: OFF >" resources/gfx/sprites/en/music_0_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: OFF >" resources/gfx/sprites/fr/music_0_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: OFF >" resources/gfx/sprites/es/music_0_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Restart" resources/gfx/sprites/en/restart.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Recommencer" resources/gfx/sprites/fr/restart.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Jugar otra vez" resources/gfx/sprites/es/restart.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Restart" resources/gfx/sprites/en/restart_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Recommencer" resources/gfx/sprites/fr/restart_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Jugar otra vez" resources/gfx/sprites/es/restart_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Credits" resources/gfx/sprites/en/credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Crédits" resources/gfx/sprites/fr/credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Créditos" resources/gfx/sprites/es/credits.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Credits" resources/gfx/sprites/en/credits_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Crédits" resources/gfx/sprites/fr/credits_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Créditos" resources/gfx/sprites/es/credits_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Back" resources/gfx/sprites/en/back.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Retour" resources/gfx/sprites/fr/back.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Volver" resources/gfx/sprites/es/back.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Back" resources/gfx/sprites/en/back_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Retour" resources/gfx/sprites/fr/back_selec.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Volver" resources/gfx/sprites/es/back_selec.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Original 2048 game by Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusic by Eric Matyas\nwww.soundimage.org\n\nN64 version developed by Victor Vieux\nwww.vrgl117.games" -extent 316x202 resources/gfx/sprites/en/text_credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Jeu 2048 original creé par Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusique par Eric Matyas\nwww.soundimage.org\n\nVersion N64 codée par Victor Vieux\nwww.vrgl117.games" -extent 344x202 resources/gfx/sprites/fr/text_credits.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Juego original 2048 por Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusica por Eric Matyas\nwww.soundimage.org\n\nVersion N64 por Victor Vieux\nwww.vrgl117.games" -extent 324x202 resources/gfx/sprites/es/text_credits.png

convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Join the numbers and get to the 2048 tile!\n\n\nThis game is Rumble Pak compatible. Please insert\nyour Rumble Pak now if you wish to play with it." -extent 416x128 resources/gfx/sprites/en/text_help.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Grouppez les nombres pour créer la case 2048!\n\n\Ce jeu est compatible avec le Rumble Pak. Insérez\nvotre Rumble Pak maintenant si vous souhaitez\nl'utiliser." -extent 412x128 resources/gfx/sprites/fr/text_help.png
convert -strip -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Junte los numeros y obtenga la casilla 2048!\n\n\nEste juego es compatible con Rumble Pak. Por favor\ninserte su Rumble Pak si desea jugar con este." -extent 424x128 resources/gfx/sprites/es/text_help.png

#screen
convert -strip -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"NO CONTROLLER INSERTED ON PORT #1" -gravity center -extent 446x32 -crop 64 resources/gfx/maps/en/no_controller-%d_0.png
convert -strip -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"PAS DE MANETTE CONNECTEE AU PORT #1" -gravity center -extent 476x32 -crop 64 resources/gfx/maps/fr/no_controller-%d_0.png
convert -strip -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"JOYSTICK NO INSERTADO EN EL PUERTO #1" -gravity center -extent 482x32 -crop 64 resources/gfx/maps/es/no_controller-%d_0.png

#grid
convert -strip -background "#EEE4DAff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:2 -gravity center -extent 24x64 resources/gfx/maps/2-%d_0.png
convert -strip -background "#EDE0C8ff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:4 -gravity center -extent 26x64 resources/gfx/maps/4-%d_0.png
convert -strip -background "#F2B179ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:8 -gravity center -extent 24x64 resources/gfx/maps/8-%d_0.png
convert -strip -background "#F59563ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:16 -gravity center -extent 46x64 -crop 32 resources/gfx/maps/16-%d_0.png
convert -strip -background "#F67C5Fff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:32 -gravity center -extent 46x64 -crop 32 resources/gfx/maps/32-%d_0.png
convert -strip -background "#F45E43ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:64 -gravity center -extent 46x64 -crop 32 resources/gfx/maps/64-%d_0.png
convert -strip -background "#ECCE78ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:128 -gravity center -extent 60x64 -crop 32 resources/gfx/maps/128-%d_0.png
convert -strip -background "#ECCB69ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:256 -gravity center -extent 60x64 -crop 32 resources/gfx/maps/256-%d_0.png
convert -strip -background "#ECC75Aff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:512 -gravity center -extent 60x64 -crop 32 resources/gfx/maps/512-%d_0.png
convert -strip -background "#ECC44Cff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:1024 -gravity center -extent 70x64 -crop 32 resources/gfx/maps/1024-%d_0.png
convert -strip -background "#EDC22Eff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:2048 -gravity center -extent 70x64 -crop 32 resources/gfx/maps/2048-%d_0.png
convert -strip -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:4096 -gravity center -extent 70x64 -crop 32 resources/gfx/maps/4096-%d_0.png
convert -strip -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:8192 -gravity center -extent 70x64 -crop 32 resources/gfx/maps/8192-%d_0.png
convert -strip -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:16384 -gravity center -extent 74x64 -crop 32 resources/gfx/maps/16384-%d_0.png
convert -strip -background "#3C3A33ff" -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:32768 -gravity center -extent 74x64 -crop 32 resources/gfx/maps/32768-%d_0.png

#font
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:0 -shave 0x4 resources/gfx/maps/font0_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:1 -shave 0x4 resources/gfx/maps/font1_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:2 -shave 0x4 resources/gfx/maps/font2_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:3 -shave 0x4 resources/gfx/maps/font3_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:4 -shave 0x4 resources/gfx/maps/font4_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:5 -shave 0x4 resources/gfx/maps/font5_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:6 -shave 0x4 resources/gfx/maps/font6_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:7 -shave 0x4 resources/gfx/maps/font7_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:8 -shave 0x4 resources/gfx/maps/font8_0.png
convert -strip -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:9 -shave 0x4 resources/gfx/maps/font9_0.png

# studio logo
convert -strip -brightness-contrast -10 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_9.png
convert -strip -brightness-contrast -20 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_8.png
convert -strip -brightness-contrast -30 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_7.png
convert -strip -brightness-contrast -40 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_6.png
convert -strip -brightness-contrast -50 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_5.png
convert -strip -brightness-contrast -60 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_4.png
convert -strip -brightness-contrast -70 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_3.png
convert -strip -brightness-contrast -80 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_2.png
convert -strip -brightness-contrast -90 resources/gfx/sprites/intro.png resources/gfx/sprites/intro_1.png

# n64 logo
convert -strip -brightness-contrast -10 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_9.png
convert -strip -brightness-contrast -20 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_8.png
convert -strip -brightness-contrast -30 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_7.png
convert -strip -brightness-contrast -40 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_6.png
convert -strip -brightness-contrast -50 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_5.png
convert -strip -brightness-contrast -60 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_4.png
convert -strip -brightness-contrast -70 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_3.png
convert -strip -brightness-contrast -80 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_2.png
convert -strip -brightness-contrast -90 resources/gfx/sprites/n64.png resources/gfx/sprites/n64_1.png
