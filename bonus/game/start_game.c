/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:53:15 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/23 11:26:16 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	load_game(t_data *data)
{
	void	*mlx_ini;
	void	*mlx_win;
	char	*rules;
	char	*start;

	rules = "Collect all the items to take the exit and win !";
	start = "Press [ENTER] to start the game, Have fun !";
	mlx_ini = mlx_init();
	mlx_win = mlx_new_window(mlx_ini, IMG_SIZE * (data->game->width + 1),
			IMG_SIZE * (data->game->height + 2), "SO_LONG");
	data->mlx = mlx_ini;
	data->win = mlx_win;
	mlx_string_put(mlx_ini, mlx_win, IMG_SIZE * (data->game->width / 2 - 1),
		IMG_SIZE * (data->game->height / 2), 255, "WELCOME IN SO_LONG !");
	mlx_string_put(mlx_ini, mlx_win, IMG_SIZE * (data->game->width / 2 - 3),
		IMG_SIZE * (data->game->height / 2 + 1), 255, rules);
	mlx_string_put(mlx_ini, mlx_win, IMG_SIZE * (data->game->width / 2 - 2)
		- 25, IMG_SIZE * (data->game->height / 2 + 2), 255, start);
	mlx_key_hook((*data).win, handle_key, data);
	mlx_hook(mlx_win, 17, 0, close_win, NULL);
	mlx_loop_hook((*data).mlx, anim, data);
	mlx_loop(mlx_ini);
}

void	start_game(t_data *data)
{
	int		i;
	int		j;

	data->game->is_start = true;
	i = 0;
	update_text(*data);
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
	set_player(*data);
	set_item(*data);
}
