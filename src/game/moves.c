/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:28 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/24 15:53:30 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	has_access(t_data data, t_point pos, int add_x, int add_y)
{
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == WALL)
		return (0);
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == EXIT)
	{
		if (data.game->items)
			return (0);
		else
			exit(0);
	}
	return (1);
}

void	move(t_data data, int add_x, int add_y)
{
	t_point	pos;

	pos = data.game->player;
	if (!has_access(data, pos, add_x, add_y))
		return ;
	data.game->moves++;
	ft_printf("%d moves\n", data.game->moves);
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == ITEM)
	{
		data.game->items--;
		data.game->points[pos.y + add_y][pos.x + add_x].value = PATH;
		new_img(data, pos.x + add_x, pos.y + add_y, PATH_IMG_PATH);
	}
	new_img(data, pos.x, pos.y, PATH_IMG_PATH);
	new_img(data, pos.x + add_x, pos.y + add_y, PLAYER_IMG_PATH);
	data.game->player.x += add_x;
	data.game->player.y += add_y;
}

int	handle_key(int key, t_data *data)
{
	if (key == KEY_Q || key == KEY_ESC)
		endgame(*data);
	if (key == KEY_W)
		move(*data, 0, -1);
	if (key == KEY_A)
		move(*data, -1, 0);
	if (key == KEY_S)
		move(*data, 0, 1);
	if (key == KEY_D)
		move(*data, 1, 0);
	return (0);
}
