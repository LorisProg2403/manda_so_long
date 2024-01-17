/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:16:41 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 22:16:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_count
{
	int		c;
	int		e;
	int		p;
}	t_count;

typedef struct s_point
{
	int			x;
	int			y;
	char		value;
	bool		visited;
}	t_point;

typedef struct s_game
{
	char		**map;
	char		*path;
	int			height;
	int			width;
	int			moves;
	int			items;
	int			item_get;
	bool		exit_reached;
	bool		items_reached;
	t_point		**points;
	t_point		player;
}	t_game;

typedef struct s_data
{
	t_game		*game;
	void		*mlx;
	void		*win;
}	t_data;

typedef struct s_res
{
	bool	state;
	int		code;
	char	*msg;
	t_data	data;
}	t_res;

#endif