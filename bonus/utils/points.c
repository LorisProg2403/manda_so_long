/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:11:37 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/24 15:11:39 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

t_point	n_point(int x, int y, char value)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.value = value;
	p.visited = false;
	return (p);
}
