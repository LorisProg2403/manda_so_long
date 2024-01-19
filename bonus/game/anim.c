/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:58:38 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/19 14:58:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

int	anim(t_data data)
{
	if (!data.game->is_start || data.game->is_over)
		return (1);
	if (data.game->player.mov_down)
		move_down(data);
	if (data.game->player.mov_up)
		move_up(data);
	if (data.game->player.mov_left)
		move_left(data);
	if (data.game->player.mov_right)
		move_right(data);
	return (0);
}
