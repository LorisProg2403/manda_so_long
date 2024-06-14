/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:48:34 by lgaume            #+#    #+#             */
/*   Updated: 2024/06/05 10:41:22 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

static char	*merge_text(char *s, char *alloc)
{
	char	*out;

	out = ft_strjoin(s, alloc);
	free(alloc);
	return (out);
}

static char	*get_text(int n, char *s)
{
	char	*out;
	char	*itoa;

	itoa = ft_itoa(n);
	out = ft_strjoin(itoa, s);
	free(itoa);
	return (out);
}

static void	clean_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->game->height + 1)
	{
		j = 0;
		while (j <= data->game->width + 1)
		{
			new_img(data, j, i, BLACK_IMG_PATH);
			j++;
		}
		i++;
	}
}

static void	display_text(t_data data)
{
	char	*move;
	char	*info;

	move = merge_text("In ", get_text(data.game->moves, " moves"));
	info = "Press [Q] or close the window to exit!";
	mlx_string_put(data.mlx, data.win, IMG_SIZE * (data.game->width / 2),
		IMG_SIZE * (data.game->height / 2), 65280, "YOU WON !");
	mlx_string_put(data.mlx, data.win, IMG_SIZE * (data.game->width / 2) - 5,
		IMG_SIZE * (data.game->height / 2 + 1), 65535, move);
	mlx_string_put(data.mlx, data.win, IMG_SIZE * (data.game->width / 2 - 2),
		IMG_SIZE * (data.game->height / 2 + 2), 65535, info);
	free(move);
}

void	victory(t_data *data)
{
	clean_screen(data);
	display_text(data);
	data->game->is_over = true;
}
