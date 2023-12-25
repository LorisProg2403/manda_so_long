/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:43:26 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 23:43:27 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/*
 * create path
 * check if the file can open and fill data.game.map with gnl
 * check if the map is ok
 * init every thing needed in the struct game (we do this before
 * 	pathfinding because we need those info for it)
 * check if the map is winnable
 */

t_res	init_map(char *s, t_data data)
{
	t_res	res;

	if (get_map(s, data.game))
		return (new_res(1, 1, "Can't open/find map!\n", data));
	res = check_map(data);
	if (res.state)
		return (res);
	set_map(data.game);
	res = is_winnable(data);
	if (res.state)
		return (res);
	return (new_res(0, 0, NULL, data));
}
