/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:39:35 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/10 12:29:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	visit_point(int x, int y, t_game *game)
{
	t_point	p;

	if (x < 0 || y < 0 || x > game->width || y > game->height)
		return ;
	p = game->points[y][x];
	if (p.value == WALL)
		return ;
	if (p.visited)
		return ;
	if (p.value == ITEM)
		game->item_get++;
	if (p.value == EXIT)
	{
		game->exit_reached = true;
		return ;
	}
	if (game->item_get == game->items)
		game->items_reached = true;
	p.visited = true;
	game->points[y][x] = p;
	visit_point(x + 1, y, game);
	visit_point(x - 1, y, game);
	visit_point(x, y - 1, game);
	visit_point(x, y + 1, game);
}

t_res	is_winnable(t_data data)
{
	visit_point(data.game->player.x, data.game->player.y, data.game);
	if (!data.game->exit_reached)
		return (new_res(1, 3, "Can't reach the exit!\n", data));
	if (!data.game->items_reached)
		return (new_res(1, 3, "Can't reach the items!\n", data));
	return (new_res(0, 0, NULL, data));
}
