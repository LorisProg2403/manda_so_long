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
	free_sprites(data);
	free(data.game);
	mlx_destroy_window(data.mlx, data.win);
	exit(EXIT_SUCCESS);
}

int	check_res(t_res res)
{
	if (res.state)
	{
		if (res.code == MAP_NOT_OPEN)
		{
			ft_printf(BRED"%s\n"RESET, res.msg);
			free(res.data.game);
		}
		else if (res.code == MAP_ERROR)
		{
			free_map(*res.data.game);
			free(res.data.game);
			ft_printf(BRED"%s\n"RESET, res.msg);
		}
		else
		{
			free_map(*res.data.game);
			free_points(*res.data.game);
			free_sprites(res.data);
			free(res.data.game);
			ft_printf(BRED"%s\n"RESET, res.msg);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_res	res;
	t_data	data;

	if (ac != 2)
	{
		ft_printf(BRED"Need only ONE argument\n"RESET);
		return (1);
	}
	res = init_map(av[1], &data);
	if (check_res(res))
		return (1);
	load_game(&data);
}
/*TODO :
 * Size of the text
 * Find Sprites for animations (10 by movements including the static one)
 * Better win and lose screen ?*/
