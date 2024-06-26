/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:43:26 by lgaume            #+#    #+#             */
/*   Updated: 2024/05/30 07:11:35 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

/*
 * create path
 * check if the file can open and fill data.game.map with gnl
 * check if the map is ok
 * init every thing needed in the struct game (we do this before
 * 	pathfinding because we need those info for it)
 * check if the map is winnable
 */

t_res	init_map(char *s, t_data *data)
{
	t_res	res;

	data->game = malloc(sizeof(t_game));
	if (get_map(s, data->game))
		return (new_res(1, 1, "Can't open/find map!\n", *data));
	set_map(data->game);
	res = check_map(*data);
	if (res.state)
		return (res);
	res = is_winnable(*data);
	if (res.state)
		return (res);
	return (new_res(0, 0, "", *data));
}
