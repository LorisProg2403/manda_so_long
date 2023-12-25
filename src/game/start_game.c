/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:15 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/24 15:53:17 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_res	start_game(t_data data)
{
	int	i;
	int	j;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, IMG_SIZE * data.game->width,
			IMG_SIZE * data.game->height, "SO_LONG");
	i = 0;
	while (i <= data.game->height)
	{
		j = 0;
		while (j <= data.game->width)
		{
			add_img(data, j, i, data.game->points[i][j]);
			j++;
		}
		i++;
	}
	mlx_key_hook(data.mlx, handle_key, &data);
	mlx_loop(data.mlx);
	return (new_res(0, 0, NULL, data));
}
