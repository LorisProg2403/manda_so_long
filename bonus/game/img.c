/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:50:17 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/25 15:50:19 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	get_corr(t_point *c, t_point p, int width, int height)
{
	if (height == IMG_SIZE / 2)
	{
		(*c).x = p.x * IMG_SIZE + height / 2;
		(*c).y = p.y * IMG_SIZE + width / 2;
	}
	else if (width == 29)
	{
		(*c).x = p.x * IMG_SIZE + 11;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	else if (height == 45)
	{
		(*c).x = p.x * IMG_SIZE + 3;
		(*c).y = p.y * IMG_SIZE + 3;
	}
	else if (height == 40)
	{
		c->x = p.x * IMG_SIZE + 5;
		c->y = p.y * IMG_SIZE + 5;
	}
	else
	{
		(*c).x = p.x * IMG_SIZE;
		(*c).y = p.y * IMG_SIZE;
	}
}

void	new_img(t_data data, int x, int y, char *path)
{
	int		img_w;
	int		img_h;
	void	*img;
	t_point	corr;

	img = mlx_xpm_file_to_image(data.mlx, path, &img_w, &img_h);
	if (!img)
	{
		ft_printf("%s not found\n", path);
		return ;
	}
	get_corr(&corr, n_point(x, y, '\0'), img_w, img_h);
	mlx_put_image_to_window(data.mlx, data.win, img, corr.x, corr.y);
	mlx_destroy_image(data.mlx, img);
}

char	*get_path(t_point p)
{
	if (p.value == EXIT)
		return (EXIT_IMG_PATH);
	if (p.value == ITEM)
		return (ITEM_IMG_PATH);
	if (p.value == PLAYER)
		return (PLAYER_IMG_PATH);
	if (p.value == WALL)
		return (WALL_IMG_PATH);
	if (p.value == TNT)
		return (TNT_IMG_PATH);
	return (PATH_IMG_PATH);
}

void	add_img(t_data data, int x, int y, t_point p)
{
	if (p.value == EXIT || p.value == ITEM || p.value == PLAYER ||
		p.value == TNT)
	{
		new_img(data, x, y, PATH_IMG_PATH);
		new_img(data, x, y, get_path(p));
	}
	else
		new_img(data, x, y, get_path(p));
}
