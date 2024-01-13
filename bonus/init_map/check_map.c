/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:34:14 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/24 12:34:16 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

int	is_allowed(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != WALL && c != PATH && c != PLAYER && c != EXIT
				&& c != TNT && c != ITEM)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct(char **map)
{
	t_count	c;
	int		i;
	int		j;

	set_zero(4, &c.c, &c.e, &c.p, &i);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ITEM)
				c.c++;
			if (map[i][j] == PLAYER)
				c.p++;
			if (map[i][j] == EXIT)
				c.e++;
			j++;
		}
		i++;
	}
	if (c.e != 1 || c.p != 1 || c.c < 1)
		return (1);
	return (0);
}

int	is_rectangle(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (1);
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

int	wall_around(char **map)
{
	int	i;
	int	w;
	int	h;

	set_zero(2, &i, &h);
	while (map[h])
		h++;
	w = ft_strlen(map[0]);
	w--;
	h--;
	while (i <= w)
	{
		if (map[0][i] != '1' || map[h][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i <= h)
	{
		if (map[i][0] != '1' || map[i][w] != '1')
			return (1);
		i++;
	}
	return (0);
}

t_res	check_map(t_data data)
{
	if (is_allowed(data.game->map))
		return (new_res(1, 2, "Map has unallowed character(s)!\n", data));
	if (is_correct(data.game->map))
		return (new_res(1, 2, "Map doesn't follow the rules!\n", data));
	if (is_rectangle(data.game->map))
		return (new_res(1, 2, "Map should be a rectangle!\n", data));
	if (wall_around(data.game->map))
		return (new_res(1, 2, "Map should be surrounded by wall!\n", data));
	return (new_res(0, 0, NULL, data));
}
