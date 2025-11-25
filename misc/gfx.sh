#!/usr/bin/env bash

fontb='misc/font/clearsans-1.00/TTF/ClearSans-Bold.ttf'
fontr='misc/font/clearsans-1.00/TTF/ClearSans-Regular.ttf'

#UI
magick -quiet -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Press Start" -gravity center -extent 186x64 -strip resources/gfx/sprites/en/press_start.rgba16.png
magick -quiet -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Appuyez sur Start" -gravity center -extent 300x64 -strip resources/gfx/sprites/fr/press_start.rgba16.png
magick -quiet -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 36 label:"Pulsa Start" -gravity center -extent 186x64 -strip resources/gfx/sprites/es/press_start.rgba16.png

magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:SCORE -background "#ffffff00" -gravity center -extent 44 -strip resources/gfx/sprites/en/score.rgba16.png
magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:SCORE -background "#ffffff00" -gravity center -extent 44 -strip resources/gfx/sprites/fr/score.rgba16.png
magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:SCORE -background "#ffffff00" -gravity center -extent 44 -strip resources/gfx/sprites/es/score.rgba16.png

magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:BEST -background "#ffffff00" -gravity center -extent 34 -strip resources/gfx/sprites/en/best.rgba16.png
magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:TOP -background "#ffffff00" -gravity center -extent 26 -strip resources/gfx/sprites/fr/best.rgba16.png
magick -quiet -background "#CDC1B4ff" -fill "#776E65ff" -font "$fontb" -pointsize 14 label:BEST -background "#ffffff00" -gravity center -extent 34 -strip resources/gfx/sprites/es/best.rgba16.png

magick -quiet -background "#faf8efff" -fill "#776E65ff" -font "$fontb" -pointsize 10 label:"version: 1.1" -gravity center -extent 56x16 -strip resources/gfx/sprites/version.rgba16.png

#menu
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Game Over" -strip resources/gfx/sprites/en/title_game_over.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Partie Terminée" -strip resources/gfx/sprites/fr/title_game_over.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Fin del juego" -strip resources/gfx/sprites/es/title_game_over.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"You Win!" -strip resources/gfx/sprites/en/title_you_win.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Gagné !" -strip resources/gfx/sprites/fr/title_you_win.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"¡Exito!" -strip resources/gfx/sprites/es/title_you_win.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pause" -strip resources/gfx/sprites/en/title_pause.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pause" -strip resources/gfx/sprites/fr/title_pause.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Pausa" -strip resources/gfx/sprites/es/title_pause.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"New Game" -strip resources/gfx/sprites/en/title_new_game.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Nouvelle Partie" -strip resources/gfx/sprites/fr/title_new_game.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Nuevo juego" -strip resources/gfx/sprites/es/title_new_game.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Credits" -strip resources/gfx/sprites/en/title_credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Crédits" -strip resources/gfx/sprites/fr/title_credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 24 label:"Créditos" -strip resources/gfx/sprites/es/title_credits.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continue" -strip resources/gfx/sprites/en/continue.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continuer" -strip resources/gfx/sprites/fr/continue.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Continuar" -strip resources/gfx/sprites/es/continue.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continue" -strip resources/gfx/sprites/en/continue_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continuer" -strip resources/gfx/sprites/fr/continue_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Continuar" -strip resources/gfx/sprites/es/continue_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Music: Track #1 " -strip resources/gfx/sprites/en/music_1.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musique: Piste #1 " -strip resources/gfx/sprites/fr/music_1.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musica: Canción #1 " -strip resources/gfx/sprites/es/music_1.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #1 >" -strip resources/gfx/sprites/en/music_1_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Piste #1 >" -strip resources/gfx/sprites/fr/music_1_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Canción #1 >" -strip resources/gfx/sprites/es/music_1_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Music: Track #2 " -strip resources/gfx/sprites/en/music_2.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musique: Piste #2 " -strip resources/gfx/sprites/fr/music_2.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musica: Canción #2 " -strip resources/gfx/sprites/es/music_2.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #2 >" -strip resources/gfx/sprites/en/music_2_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Piste #2 >" -strip resources/gfx/sprites/fr/music_2_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Canción #2 >" -strip resources/gfx/sprites/es/music_2_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Music: Track #3 " -strip resources/gfx/sprites/en/music_3.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musique: Piste #3 " -strip resources/gfx/sprites/fr/music_3.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musica: Canción #3 " -strip resources/gfx/sprites/es/music_3.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: Track #3 >" -strip resources/gfx/sprites/en/music_3_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Piste #3 >" -strip resources/gfx/sprites/fr/music_3_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: Canción #3 >" -strip resources/gfx/sprites/es/music_3_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Music: No " -strip resources/gfx/sprites/en/music_0.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musique: Non " -strip resources/gfx/sprites/fr/music_0.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:" Musica: No " -strip resources/gfx/sprites/es/music_0.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Music: No >" -strip resources/gfx/sprites/en/music_0_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musique: Non >" -strip resources/gfx/sprites/fr/music_0_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"< Musica: No >" -strip resources/gfx/sprites/es/music_0_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Restart" -strip resources/gfx/sprites/en/restart.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Recommencer" -strip resources/gfx/sprites/fr/restart.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Jugar otra vez" -strip resources/gfx/sprites/es/restart.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Restart" -strip resources/gfx/sprites/en/restart_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Recommencer" -strip resources/gfx/sprites/fr/restart_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Jugar otra vez" -strip resources/gfx/sprites/es/restart_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Credits" -strip resources/gfx/sprites/en/credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Crédits" -strip resources/gfx/sprites/fr/credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Créditos" -strip resources/gfx/sprites/es/credits.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Credits" -strip resources/gfx/sprites/en/credits_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Crédits" -strip resources/gfx/sprites/fr/credits_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Créditos" -strip resources/gfx/sprites/es/credits_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Back" -strip resources/gfx/sprites/en/back.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Retour" -strip resources/gfx/sprites/fr/back.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 label:"Volver" -strip resources/gfx/sprites/es/back.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Back" -strip resources/gfx/sprites/en/back_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Retour" -strip resources/gfx/sprites/fr/back_selec.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontb" -pointsize 18 label:"Volver" -strip resources/gfx/sprites/es/back_selec.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Original 2048 game by Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusic by Eric Matyas\nwww.soundimage.org\n\nN64 version developed by Victor Vieux\nwww.vrgl117.games" -extent 316x202 resources/gfx/sprites/en/text_credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Jeu 2048 original creé par Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusique par Eric Matyas\nwww.soundimage.org\n\nVersion N64 codée par Victor Vieux\nwww.vrgl117.games" -extent 344x202 resources/gfx/sprites/fr/text_credits.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Juego original 2048 por Gabriele Cirulli\nwww.gabrielecirulli.com\n\nMusica por Eric Matyas\nwww.soundimage.org\n\nVersion N64 por Victor Vieux\nwww.vrgl117.games" -extent 324x202 resources/gfx/sprites/es/text_credits.rgba16.png

magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Join the numbers and get to the 2048 tile!\n\n\nThis game is Rumble Pak compatible. Please insert\nyour Rumble Pak now if you wish to play with it." -extent 416x128 resources/gfx/sprites/en/text_help.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Groupez les nombres pour créer la case 2048!\n\n\Ce jeu est compatible avec le Rumble Pak. Insérez\nvotre Rumble Pak maintenant si vous souhaitez\nl'utiliser." -extent 412x128 resources/gfx/sprites/fr/text_help.rgba16.png
magick -quiet -background "#bbada0ff" -fill "#776E65ff" -font "$fontr" -pointsize 18 -gravity Center label:"Junte los numeros y obtenga la casilla 2048!\n\n\nEste juego es compatible con Rumble Pak. Por favor\ninserte su Rumble Pak si desea jugar con este." -extent 424x128 resources/gfx/sprites/es/text_help.rgba16.png

#screen
magick -quiet -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"NO CONTROLLER INSERTED ON PORT #1" -gravity center -extent 446x32 -strip resources/gfx/sprites/en/no_controller.rgba16.png
magick -quiet -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"PAS DE MANETTE CONNECTEE AU PORT #1" -gravity center -extent 476x32 -strip resources/gfx/sprites/fr/no_controller.rgba16.png
magick -quiet -background "#000000FF" -fill "#EDE0C8ff" -font "$fontb" -pointsize 24 label:"JOYSTICK NO INSERTADO EN EL PUERTO #1" -gravity center -extent 482x32 -strip resources/gfx/sprites/es/no_controller.rgba16.png

#grid
magick -quiet -background none -fill "#776E65ff" -font "$fontb" -pointsize 36 label:2 -gravity center -extent 24x64 -strip resources/gfx/sprites/2.rgba32.png
magick -quiet -background none -fill "#776E65ff" -font "$fontb" -pointsize 36 label:4 -gravity center -extent 26x64 -strip resources/gfx/sprites/4.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:8 -gravity center -extent 24x64 -strip resources/gfx/sprites/8.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:16 -gravity center -extent 46x64 -strip resources/gfx/sprites/16.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:32 -gravity center -extent 46x64 -strip resources/gfx/sprites/32.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 36 label:64 -gravity center -extent 46x64 -strip resources/gfx/sprites/64.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:128 -gravity center -extent 60x64 -strip resources/gfx/sprites/128.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:256 -gravity center -extent 60x64 -strip resources/gfx/sprites/256.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 32 label:512 -gravity center -extent 60x64 -strip resources/gfx/sprites/512.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:1024 -gravity center -extent 70x64 -strip resources/gfx/sprites/1024.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:2048 -gravity center -extent 70x64 -strip resources/gfx/sprites/2048.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:4096 -gravity center -extent 70x64 -strip resources/gfx/sprites/4096.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 28 label:8192 -gravity center -extent 70x64 -strip resources/gfx/sprites/8192.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:16384 -gravity center -extent 74x64 -strip resources/gfx/sprites/16384.rgba32.png
magick -quiet -background none -fill "#F9F6F2ff" -font "$fontb" -pointsize 24 label:32768 -gravity center -extent 74x64 -strip resources/gfx/sprites/32768.rgba32.png
