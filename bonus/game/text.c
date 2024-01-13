/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:23:43 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/13 09:23:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	erase_text(t_data data)
{
	int	x;

	x = 0;
	while (x <= data.game->width)
	{
		new_img(data, x, data.game->height + 1, BLACK_IMG_PATH);
		x++;
	}
}

void	update_text(t_data data)
{
	int		y;
	int		color;
	char	*moves;
	char	*items;

	erase_text(data);
	y = IMG_SIZE * (data.game->height + 1) + (IMG_SIZE / 2);
	moves = ft_strjoin("MOVES : ", ft_itoa(data.game->moves));
	if (data.game->items)
	{
		items = ft_strjoin("ITEMS TO COLLECT : ", ft_itoa(data.game->items));
		color = 255;
	}
	else
	{
		items = ft_strdup("ALL ITEMS COLLECTED !");
		color = 65280;
	}
	mlx_string_put(data.mlx, data.win, data.game->m_text_x, y, 255, moves);
	mlx_string_put(data.mlx, data.win, data.game->i_text_x, y, color, items);
	free(moves);
	free(items);
}
