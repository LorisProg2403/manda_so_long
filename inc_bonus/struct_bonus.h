/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:32:52 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/12 12:32:54 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

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
	int			m_text_x;
	int			i_text_x;
	bool		exit_reached;
	bool		items_reached;
	bool		is_over;
	bool		is_start;
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
