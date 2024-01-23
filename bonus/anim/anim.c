/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:58:38 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/23 11:27:48 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	check_item(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data.game->height)
	{
		j = 0;
		while (j <= data.game->width)
		{
			if (data.game->points[i][j].value == 'C')
				anim_item(data, j, i);
			j++;
		}
		i++;
	}
}

int	anim(t_data *data)
{
	if (!data->game->is_start || data->game->is_over)
		return (1);
	check_item(*data);
	if (data->game->player.mov_down)
		move_down(data);
	if (data->game->player.mov_up)
		move_up(data);
	if (data->game->player.mov_left)
		move_left(data);
	if (data->game->player.mov_right)
		move_right(data);
	return (0);
}
