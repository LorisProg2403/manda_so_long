/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:59:23 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/25 15:59:25 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	free_sprites(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 50)
		{
			mlx_destroy_image(data.mlx, data.game->player.sprites[i][j].img);
			j++;
		}
		free(data.game->player.sprites[i]);
		i++;
	}
	free(data.game->player.sprites);
}

void	free_points(t_game game)
{
	int	i;

	i = 0;
	while (i <= game.height)
	{
		free(game.points[i]);
		i++;
	}
	free(game.points);
}

void	free_map(t_game game)
{
	int	i;

	i = 0;
	while (i <= game.height + 1)
	{
		free(game.map[i]);
		i++;
	}
	free(game.map);
}
