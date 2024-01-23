/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:27:58 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/23 04:28:00 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	set_img(t_data data, t_item *i)
{
	int	j;

	i->sprites = malloc(sizeof(t_img) * 42);
	j = 0;
	while (j < 7)
	{
		i->sprites[j].img = mlx_xpm_file_to_image(data.mlx,
				COIN_1, &i->sprites[j].w, &i->sprites[j].h);
		i->sprites[j + 7].img = mlx_xpm_file_to_image(data.mlx,
				COIN_2, &i->sprites[j + 7].w, &i->sprites[j + 7].h);
		i->sprites[j + 14].img = mlx_xpm_file_to_image(data.mlx,
				COIN_3, &i->sprites[j + 14].w, &i->sprites[j + 14].h);
		i->sprites[j + 21].img = mlx_xpm_file_to_image(data.mlx,
				COIN_4, &i->sprites[j + 21].w, &i->sprites[j + 21].h);
		i->sprites[j + 28].img = mlx_xpm_file_to_image(data.mlx,
				COIN_5, &i->sprites[j + 28].w, &i->sprites[j + 28].h);
		i->sprites[j + 35].img = mlx_xpm_file_to_image(data.mlx,
				COIN_6, &i->sprites[j + 35].w, &i->sprites[j + 35].h);
		j++;
	}
}

void	set_item(t_data data)
{
	data.game->anim_item.sprites_count = 0;
	set_img(data, &data.game->anim_item);
}
