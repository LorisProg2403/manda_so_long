/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:21:17 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/10 12:29:31 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	get_text_pos(t_game *game)
{
	int	quarter;

	quarter = game->width / 4;
	game->i_text_x = IMG_SIZE * (quarter * 3);
	game->m_text_x = IMG_SIZE * quarter;
}

void	get_h_and_w(t_game *game)
{
	int	h;

	h = 0;
	game->width = ft_strlen(game->map[0]) - 1;
	while (game->map[h])
		h++;
	game->height = h - 1;
}

void	set_points(t_game *game)
{
	int	i;
	int	j;

	game->points = malloc(sizeof(t_point *) * (game->height + 1));
	i = 0;
	while (i <= game->height)
	{
		game->points[i] = malloc(sizeof(t_point) * (game->width + 1));
		j = 0;
		while (j <= game->width)
		{
			game->points[i][j] = n_point(j, i, game->map[i][j]);
			if (game->map[i][j] == PLAYER)
				game->player = n_point(j, i, 'P');
			if (game->map[i][j] == ITEM)
				game->items++;
			j++;
		}
		i++;
	}
}

void	set_map(t_game *game)
{
	get_h_and_w(game);
	game->moves = 0;
	game->items = 0;
	game->exit_reached = false;
	game->items_reached = false;
	game->is_over = false;
	game->is_start = false;
	set_points(game);
	get_text_pos(game);
}
