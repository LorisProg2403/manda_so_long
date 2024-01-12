/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:15 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/10 13:08:51 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	start_game(t_data *data)
{
	int		i;
	int		j;
	void	*mlx_ini;
	void	*mlx_win;

	mlx_ini = mlx_init();
	mlx_win = mlx_new_window(mlx_ini, IMG_SIZE * (data->game->width + 1),
			IMG_SIZE * (data->game->height + 1), "SO_LONG");
	data->mlx = mlx_ini;
	data->win = mlx_win;
	i = 0;
	while (i <= data->game->height)
	{
		j = 0;
		while (j <= data->game->width)
		{
			add_img(*data, j, i, data->game->points[i][j]);
			j++;
		}
		i++;
	}
	mlx_key_hook((*data).win, handle_key, data);
	mlx_hook(mlx_win, 17, 0, close_win, NULL);
	mlx_loop(mlx_ini);
}
