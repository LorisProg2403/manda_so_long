/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:58 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/12 12:31:00 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	endgame(t_data data)
{
	free_points(*data.game);
	free_map(*data.game);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}

int	check_res(t_res res)
{
	if (res.state)
	{
		ft_printf(BRED"%s\n"RESET, res.msg);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_res	res;
	t_data	data;

	if (ac != 2)
	{
		ft_printf(BRED"More than one arguments\n"RESET);
		return (1);
	}
	res = init_map(av[1], &data);
	if (check_res(res))
		return (1);
	start_game(&data);
}
/*TODO :
 * Death when going into TNT
 * Text for the moves on the window
 * Change mlx functions for the size of the string
 * Add win screen (full black and text ?)
 * Multiple map ?
 * Sprites for movement (Redraw all the map everytime ?)*/
