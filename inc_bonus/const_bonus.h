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
# define PLAYER_IMG_PATH "./img/player.xpm"
# define BLACK_IMG_PATH "./img/bonus/black.xpm"
# define TNT_IMG_PATH "./img/bonus/tnt.xpm"

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
