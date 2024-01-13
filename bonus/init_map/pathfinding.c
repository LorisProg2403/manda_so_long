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

#include "../../inc_bonus/so_long_bonus.h"

void	visit_point(int x, int y, int items, t_game *game)
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
		items++;
	if (p.value == EXIT)
		game->exit_reached = true;
	if (items == game->items)
		game->items_reached = true;
	p.visited = true;
	game->points[y][x] = p;
	visit_point(x + 1, y, items, game);
	visit_point(x - 1, y, items, game);
	visit_point(x, y - 1, items, game);
	visit_point(x, y + 1, items, game);
}

t_res	is_winnable(t_data data)
{
	visit_point(data.game->player.x, data.game->player.y, 0, data.game);
	if (!data.game->exit_reached)
		return (new_res(1, 3, "Can't reach the exit!\n", data));
	if (!data.game->items_reached)
		return (new_res(1, 3, "Can't reach the items!\n", data));
	return (new_res(0, 0, NULL, data));
}
