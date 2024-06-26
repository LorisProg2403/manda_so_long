/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:29:55 by lgaume            #+#    #+#             */
/*   Updated: 2024/05/27 15:42:37 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	endgame(t_data data)
{
	free_points(data.game);
	free_map(data.game);
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
			return (1);
		}
		if (res.code == MAP_ERROR)
		{
			free_map(res.data.game);
			free_points(res.data.game);
			free(res.data.game);
			ft_printf(BRED"%s\n"RESET, res.msg);
			return (1);
		}
		else
		{
			free_map(res.data.game);
			free_points(res.data.game);
			free(res.data.game);
			ft_printf(BRED"%s\n"RESET, res.msg);
			return (1);
		}
	}
	return (0);
}

int	test_ber(char *map)
{
	char	*last_dot;

	if (!map)
		return (1);
	last_dot = ft_strrchr(map, '.');
	if (last_dot && !ft_strcmp(last_dot, ".ber"))
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_res	res;
	t_data	data;

	if (ac != 2)
	{
		ft_printf(BRED"Need one argument\n"RESET);
		return (1);
	}
	if (test_ber(av[1]))
	{
		ft_printf(BRED"Map must be a .ber file\n"RESET);
		return (1);
	}
	res = init_map(av[1], &data);
	if (check_res(res))
		return (1);
	start_game(&data);
}
