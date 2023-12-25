/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:29:55 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 22:29:57 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	endgame(t_data data)
{
	free_points(*data.game);
	free_map(*data.game);
	mlx_destroy_window(data.mlx, data.win);
}

int	check_res(t_res res)
{
	if (res.state)
	{
		printf(BRED"%s\n"RESET, res.msg);
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
	data.game->items = 0;
	res = init_map(av[1], data);
	if (check_res(res))
		return (1);
	res = start_game(data);
	if (check_res(res))
		return (1);
	endgame(data);
	exit (0);
}

Seg mystere