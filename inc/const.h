/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:16:38 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 22:16:38 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

// Keys
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_ESC 53

// Images path
# define WALL_IMG_PATH "./img/wall.xpm"
# define PATH_IMG_PATH "./img/grass.xpm"
# define EXIT_IMG_PATH "./img/exit.xpm"
# define ITEM_IMG_PATH "./img/apple.xpm"
# define PLAYER_IMG_PATH "./img/player.xpm"

// Code
# define MAP_NOT_OPEN 1
# define MAP_ERROR 2
# define PATHFINDING_ERROR 3

// Data
# define IMG_SIZE 50

// MAP CHARACTERS
# define WALL '1'
# define PATH '0'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

#endif