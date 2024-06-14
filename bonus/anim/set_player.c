/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:41:25 by lgaume            #+#    #+#             */
/*   Updated: 2024/06/05 10:32:30 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

void	set_img_down(t_data *data, t_player *p)
{
	int	i;

	p->sprites[3] = malloc(sizeof(t_img) * 50);
	i = 0;
	while (i < 10)
	{
		p->sprites[3][i].img = mlx_xpm_file_to_image(data->mlx,
				DOWN_1, &p->sprites[3][i].w, &p->sprites[3][i].h);
		p->sprites[3][i + 10].img = mlx_xpm_file_to_image(data->mlx,
				DOWN_2, &p->sprites[3][i + 10].w, &p->sprites[3][i + 10].h);
		p->sprites[3][i + 20].img = mlx_xpm_file_to_image(data->mlx,
				DOWN_3, &p->sprites[3][i + 20].w, &p->sprites[3][i + 20].h);
		p->sprites[3][i + 30].img = mlx_xpm_file_to_image(data->mlx,
				DOWN_4, &p->sprites[3][i + 30].w, &p->sprites[3][i + 30].h);
		p->sprites[3][i + 40].img = mlx_xpm_file_to_image(data->mlx,
				DOWN_1, &p->sprites[3][i + 40].w, &p->sprites[3][i + 40].h);
		i++;
	}
}

void	set_img_up(t_data *data, t_player *p)
{
	int	i;

	p->sprites[2] = malloc(sizeof(t_img) * 50);
	i = 0;
	while (i < 10)
	{
		p->sprites[2][i].img = mlx_xpm_file_to_image(data->mlx,
				UP_1, &p->sprites[2][i].w, &p->sprites[2][i].h);
		p->sprites[2][i + 10].img = mlx_xpm_file_to_image(data->mlx,
				UP_2, &p->sprites[2][i + 10].w, &p->sprites[2][i + 10].h);
		p->sprites[2][i + 20].img = mlx_xpm_file_to_image(data->mlx,
				UP_3, &p->sprites[2][i + 20].w, &p->sprites[2][i + 20].h);
		p->sprites[2][i + 30].img = mlx_xpm_file_to_image(data->mlx,
				UP_4, &p->sprites[2][i + 30].w, &p->sprites[2][i + 30].h);
		p->sprites[2][i + 40].img = mlx_xpm_file_to_image(data->mlx,
				UP_1, &p->sprites[2][i + 40].w, &p->sprites[2][i + 40].h);
		i++;
	}
}

void	set_img_left(t_data *data, t_player *p)
{
	int	i;

	p->sprites[1] = malloc(sizeof(t_img) * 50);
	i = 0;
	while (i < 10)
	{
		p->sprites[1][i].img = mlx_xpm_file_to_image(data->mlx,
				LEFT_1, &p->sprites[1][i].w, &p->sprites[1][i].h);
		p->sprites[1][i + 10].img = mlx_xpm_file_to_image(data->mlx,
				LEFT_2, &p->sprites[1][i + 10].w, &p->sprites[1][i + 10].h);
		p->sprites[1][i + 20].img = mlx_xpm_file_to_image(data->mlx,
				LEFT_3, &p->sprites[1][i + 20].w, &p->sprites[1][i + 20].h);
		p->sprites[1][i + 30].img = mlx_xpm_file_to_image(data->mlx,
				LEFT_4, &p->sprites[1][i + 30].w, &p->sprites[1][i + 30].h);
		p->sprites[1][i + 40].img = mlx_xpm_file_to_image(data->mlx,
				LEFT_1, &p->sprites[1][i + 40].w, &p->sprites[1][i + 40].h);
		i++;
	}
}

void	set_img_right(t_data *data, t_player *p)
{
	int	i;

	p->sprites[0] = malloc(sizeof(t_img) * 50);
	i = 0;
	while (i < 10)
	{
		p->sprites[0][i].img = mlx_xpm_file_to_image(data->mlx,
				RIGHT_1, &p->sprites[0][i].w, &p->sprites[0][i].h);
		p->sprites[0][i + 10].img = mlx_xpm_file_to_image(data->mlx,
				RIGHT_2, &p->sprites[0][i + 10].w, &p->sprites[0][i + 10].h);
		p->sprites[0][i + 20].img = mlx_xpm_file_to_image(data->mlx,
				RIGHT_3, &p->sprites[0][i + 20].w, &p->sprites[0][i + 20].h);
		p->sprites[0][i + 30].img = mlx_xpm_file_to_image(data->mlx,
				RIGHT_4, &p->sprites[0][i + 30].w, &p->sprites[0][i + 30].h);
		p->sprites[0][i + 40].img = mlx_xpm_file_to_image(data->mlx,
				RIGHT_1, &p->sprites[0][i + 40].w, &p->sprites[0][i + 40].h);
		i++;
	}
}

void	set_player(t_data *data)
{
	data->game->player.mov_right = false;
	data->game->player.mov_left = false;
	data->game->player.mov_down = false;
	data->game->player.mov_up = false;
	data->game->player.sprites_count = 0;
	data->game->player.sprites = malloc(sizeof(t_img *) * 4);
	set_img_right(data, &(*data).game->player);
	set_img_left(data, &(*data).game->player);
	set_img_up(data, &(*data).game->player);
	set_img_down(data, &(*data).game->player);
}
