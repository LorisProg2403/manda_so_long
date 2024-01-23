/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:39:24 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/23 04:39:25 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	get_corr_anim2(t_point *c, int x, int y, t_img img)
{
	(*c).x = x * IMG_SIZE + (img.h / 2);
	(*c).y = y * IMG_SIZE + (img.w / 2);
}

void	anim_item(t_data data, int x, int y)
{
	int		i;
	t_point	corr;

	if (data.game->anim_item.sprites_count == 42)
	{
		data.game->anim_item.sprites_count = 0;
		return ;
	}
	i = data.game->anim_item.sprites_count;
	new_img(data, x, y, PATH_IMG_PATH);
	get_corr_anim2(&corr, x, y, data.game->anim_item.sprites[i]);
	mlx_put_image_to_window(data.mlx, data.win,
		data.game->anim_item.sprites[i].img, corr.x, corr.y);
	data.game->anim_item.sprites_count++;
}
