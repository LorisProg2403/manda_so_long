/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:58:28 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/24 00:58:32 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
	(*game).map = (char **)malloc(sizeof(char *) * n_lines);
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
	close(fd);
	free(game->path);
	return (0);
}
