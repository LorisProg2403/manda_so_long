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

char	*get_text(char *s, int n)
{
	char	*out;
	char	*itoa;

	itoa = ft_itoa(n);
	out = ft_strjoin(s, itoa);
	free(itoa);
	return (out);
}

void	update_text(t_data data)
{
	int		y;
	int		color;
	char	*moves;
	char	*items;

	erase_text(data);
	y = IMG_SIZE * (data.game->height + 1) + (IMG_SIZE / 2);
	moves = get_text("MOVES : ", data.game->moves);
	if (data.game->items)
	{
		items = get_text("ITEMS TO COLLECT : ", data.game->items);
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
