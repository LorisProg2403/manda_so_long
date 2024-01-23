/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:32:43 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/12 12:32:45 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_BONUS_H
# define CONST_BONUS_H

// Keys
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_ESC 53
# define KEY_ENTER 36

// Images path
# define WALL_IMG_PATH "./img/wall.xpm"
# define PATH_IMG_PATH "./img/grass.xpm"
# define EXIT_IMG_PATH "./img/exit.xpm"
# define ITEM_IMG_PATH "./img/apple.xpm"
# define BLACK_IMG_PATH "./img/bonus/black.xpm"
# define TNT_IMG_PATH "./img/bonus/tnt.xpm"

# define PLAYER_IMG_PATH "./img/bonus/player.xpm"
# define RIGHT_1 "./img/bonus/right/right1.xpm"
# define RIGHT_2 "./img/bonus/right/right2.xpm"
# define RIGHT_3 "./img/bonus/right/right3.xpm"
# define RIGHT_4 "./img/bonus/right/right4.xpm"
# define LEFT_1 "./img/bonus/left/left1.xpm"
# define LEFT_2 "./img/bonus/left/left2.xpm"
# define LEFT_3 "./img/bonus/left/left3.xpm"
# define LEFT_4 "./img/bonus/left/left4.xpm"
# define DOWN_1 "./img/bonus/down/down1.xpm"
# define DOWN_2 "./img/bonus/down/down2.xpm"
# define DOWN_3 "./img/bonus/down/down3.xpm"
# define DOWN_4 "./img/bonus/down/down4.xpm"
# define UP_1 "./img/bonus/up/up1.xpm"
# define UP_2 "./img/bonus/up/up2.xpm"
# define UP_3 "./img/bonus/up/up3.xpm"
# define UP_4 "./img/bonus/up/up4.xpm"

// Data
# define IMG_SIZE 50

// Code
# define MAP_NOT_OPEN 1
# define MAP_ERROR 2
# define PATHFINDING_ERROR 3

// MAP CHARACTERS
# define WALL '1'
# define PATH '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define TNT 'T'

#endif
