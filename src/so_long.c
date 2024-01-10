/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:29:55 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/10 13:00:20 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	test_map(t_game *game)
{
	if (!game->width || !game->height)
	{
		printf(BRED"No width/height!\n"RESET);
		exit(1);
	}
	if (game->moves)
	{
		printf(BRED"Moves hasnt been set to 0!\n"RESET);
		exit(1);
	}
	if (!game->items)
	{
		printf(BRED"Items hasnt been set!\n"RESET);
		exit(1);
	}
	if (!game->player.x || !game->player.y)
	{
		printf(BRED"Player hasnt been set!\n"RESET);
		exit(1);
	}
	int i = 0;
	printf(BBLUE"TEST OF MAP!\n\n"RESET);
	while (i <= game->height)
	{
		int j = 0;
		while (j <= game->width)
		{
			if (game->map[i][j] == PLAYER)
				printf(BYELLOW"%c"RESET, game->map[i][j]);
			else if (game->map[i][j] == ITEM)
				printf(BRED"%c"RESET, game->map[i][j]);
			else if (game->map[i][j] == EXIT)
				printf(BGREEN"%c"RESET, game->map[i][j]);
			else
				printf(BLUE"%c"RESET, game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	printf(BBLUE"TEST OF POINTS!\n\n"RESET);
	while (i <= game->height)
	{
		int j = 0;
		while (j <= game->width)
		{
			if (game->points[i][j].value == PLAYER)
				printf(BYELLOW"%c"RESET, game->points[i][j].value);
			else if (game->points[i][j].value == ITEM)
				printf(BRED"%c"RESET, game->points[i][j].value);
			else if (game->points[i][j].value == EXIT)
				printf(BGREEN"%c"RESET, game->points[i][j].value);
			else
				printf(BLUE"%c"RESET, game->points[i][j].value);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
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
	//test_map(data.game);
	start_game(&data);
}
