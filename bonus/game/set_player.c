/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:41:25 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/19 18:41:27 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	set_img(t_data data, t_player *p)
{
	int	i;
	int	j;

	p->sprites = malloc(sizeof(t_img *) * 4);
	i = 0;
	while (i < 4)
	{
		p->sprites[i] = malloc(sizeof(t_img) * 50);
		j = 0;
		while (j < 50)
		{
			p->sprites[i][j].img = mlx_xpm_file_to_image(data.mlx,
					PLAYER_IMG_PATH, &p->sprites[i][j].w, &p->sprites[i][j].h);
			j++;
		}
		i++;
	}
}

void	set_player(t_data data)
{
	data.game->player.mov_right = false;
	data.game->player.mov_left = false;
	data.game->player.mov_down = false;
	data.game->player.mov_up = false;
	data.game->player.sprites_count = 0;
	set_img(data, &data.game->player);
}
