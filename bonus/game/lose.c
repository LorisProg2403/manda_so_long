/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:14:20 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/13 12:14:21 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

static void	clean_screen(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data.game->height + 1)
	{
		j = 0;
		while (j <= data.game->width + 1)
		{
			new_img(data, j, i, BLACK_IMG_PATH);
			j++;
		}
		i++;
	}
}

static void	display_text(t_data data)
{
	char	*info;

	info = "Press [Q] or close the window to exit!";
	mlx_string_put(data.mlx, data.win, IMG_SIZE * (data.game->width / 2),
		IMG_SIZE * (data.game->height / 2), 16711680, "YOU LOSE !");
	mlx_string_put(data.mlx, data.win, IMG_SIZE * (data.game->width / 2 - 2),
		IMG_SIZE * (data.game->height / 2 + 1), 16711680, info);
}

void	lose(t_data data)
{
	clean_screen(data);
	display_text(data);
	data.game->is_over = true;
}
