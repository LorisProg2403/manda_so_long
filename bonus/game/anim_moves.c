/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:28:47 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/19 19:28:49 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	get_corr_anim(t_point *c, t_point p, int i, char move)
{
	if (move == 'R')
	{
		(*c).x = p.x * IMG_SIZE + 4 + i;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	if (move == 'L')
	{
		(*c).x = p.x * IMG_SIZE + 4 - i;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	if (move == 'D')
	{
		(*c).x = p.x * IMG_SIZE + 3;
		(*c).y = p.y * IMG_SIZE + 4 + i;
	}
	if (move == 'U')
	{
		(*c).x = p.x * IMG_SIZE + 3;
		(*c).y = p.y * IMG_SIZE + 4 - i;
	}
}

void	move_down(t_data data)
{
	t_point	corr;
	int		i;

	if (data.game->player.sprites_count == 50)
	{
		data.game->player.sprites_count = 0;
		data.game->player.mov_down = false;
		data.game->player.pos.y += 1;
		return ;
	}
	i = data.game->player.sprites_count;
	new_img(data, data.game->player.pos.x, data.game->player.pos.y,
		PATH_IMG_PATH);
	new_img(data, data.game->player.pos.x, data.game->player.pos.y + 1,
		PATH_IMG_PATH);
	get_corr_anim(&corr, data.game->player.pos, i, 'D');
	mlx_put_image_to_window(data.mlx, data.win,
		data.game->player.sprites[3][i].img, corr.x, corr.y);
	data.game->player.sprites_count++;
}

void	move_up(t_data data)
{
	t_point	corr;
	int		i;

	if (data.game->player.sprites_count == 50)
	{
		data.game->player.sprites_count = 0;
		data.game->player.mov_up = false;
		data.game->player.pos.y += -1;
		return ;
	}
	i = data.game->player.sprites_count;
	new_img(data, data.game->player.pos.x, data.game->player.pos.y,
		PATH_IMG_PATH);
	new_img(data, data.game->player.pos.x, data.game->player.pos.y - 1,
		PATH_IMG_PATH);
	get_corr_anim(&corr, data.game->player.pos, i, 'U');
	mlx_put_image_to_window(data.mlx, data.win,
		data.game->player.sprites[2][i].img, corr.x, corr.y);
	data.game->player.sprites_count++;
}

void	move_left(t_data data)
{
	t_point	corr;
	int		i;

	if (data.game->player.sprites_count == 50)
	{
		data.game->player.sprites_count = 0;
		data.game->player.mov_left = false;
		data.game->player.pos.x += -1;
		return ;
	}
	i = data.game->player.sprites_count;
	new_img(data, data.game->player.pos.x, data.game->player.pos.y,
		PATH_IMG_PATH);
	new_img(data, data.game->player.pos.x - 1, data.game->player.pos.y,
		PATH_IMG_PATH);
	get_corr_anim(&corr, data.game->player.pos, i, 'L');
	mlx_put_image_to_window(data.mlx, data.win,
		data.game->player.sprites[1][i].img, corr.x, corr.y);
	data.game->player.sprites_count++;
}

void	move_right(t_data data)
{
	t_point	corr;
	int		i;

	if (data.game->player.sprites_count == 50)
	{
		data.game->player.sprites_count = 0;
		data.game->player.mov_right = false;
		data.game->player.pos.x += 1;
		return ;
	}
	i = data.game->player.sprites_count;
	new_img(data, data.game->player.pos.x, data.game->player.pos.y,
		PATH_IMG_PATH);
	new_img(data, data.game->player.pos.x + 1, data.game->player.pos.y,
		PATH_IMG_PATH);
	get_corr_anim(&corr, data.game->player.pos, i, 'R');
	mlx_put_image_to_window(data.mlx, data.win,
		data.game->player.sprites[0][i].img, corr.x, corr.y);
	data.game->player.sprites_count++;
}
