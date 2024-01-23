/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:28 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/23 11:32:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

int	handle_tnt(t_point pos, int add_x, int add_y, t_data data)
{
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == TNT)
	{
		ft_printf(BRED"\nYou lost... try again!\n"RESET);
		lose(data);
		return (1);
	}
	return (0);
}

void	handle_item(t_point pos, int add_x, int add_y, t_data data)
{
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == ITEM)
	{
		data.game->items--;
		data.game->points[pos.y + add_y][pos.x + add_x].value = PATH;
		new_img(data, pos.x + add_x, pos.y + add_y, PATH_IMG_PATH);
	}
}

int	has_access(t_data data, t_point pos, int add_x, int add_y)
{
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == WALL)
		return (0);
	if (data.game->points[pos.y + add_y][pos.x + add_x].value == EXIT)
	{
		if (data.game->items)
			return (0);
		else
		{
			data.game->moves++;
			ft_printf("%d moves\n", data.game->moves);
			ft_printf(BGREEN"\nYou won in %d moves !\nWell played !\n"RESET,
				data.game->moves);
			victory(data);
			return (0);
		}
	}
	return (1);
}

void	move(t_data data, int add_x, int add_y)
{
	t_point	pos;

	pos = data.game->player.pos;
	if (handle_tnt(pos, add_x, add_y, data))
		return ;
	if (!has_access(data, pos, add_x, add_y))
		return ;
	data.game->moves++;
	handle_item(pos, add_x, add_y, data);
	update_text(data);
	ft_printf("%d moves\n", data.game->moves);
	if (add_x == 1)
		data.game->player.mov_right = true;
	if (add_x == -1)
		data.game->player.mov_left = true;
	if (add_y == -1)
		data.game->player.mov_up = true;
	if (add_y == 1)
		data.game->player.mov_down = true;
}

int	handle_key(int key, t_data *data)
{
	if (key == KEY_Q || key == KEY_ESC)
	{
		ft_printf(BBLUE"\nGame closed\n"RESET);
		endgame(*data);
	}
	if (key == KEY_ENTER && !data->game->is_start)
		start_game(data);
	if (data->game->is_over && !data->game->is_start)
		return (1);
	if (data->game->player.mov_right || data->game->player.mov_left
		|| data->game->player.mov_up || data->game->player.mov_down)
		return (1);
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
