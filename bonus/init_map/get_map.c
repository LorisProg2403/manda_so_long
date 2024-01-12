/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:58:28 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/10 13:25:34 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

int	number_of_lines(char *p)
{
	int		n;
	int		fd;
	char	*line;

	fd = open(p, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		n++;
		free(line);
	}
	close(fd);
	return (n);
}

int	get_map(char *s, t_game *game)
{
	int		fd;
	int		n_lines;
	int		i;
	char	*line;

	(*game).path = ft_strjoin("maps/", s);
	n_lines = number_of_lines((*game).path);
	fd = open((*game).path, O_RDONLY);
	if (fd < 0)
		return (1);
	(*game).map = (char **)malloc(sizeof(char *) * (n_lines + 1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*game).map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->map[i] = 0;
	close(fd);
	free(game->path);
	return (0);
}
