/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:32:52 by lgaume            #+#    #+#             */
/*   Updated: 2024/06/04 21:44:59 by lgaume           ###   ########.fr       */
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

typedef struct s_img
{
	void		*img;
	int			w;
	int			h;
}	t_img;

typedef struct s_item
{
	int			sprites_count;
	t_img		*sprites;
}	t_item;

typedef struct s_player
{
	bool		mov_right;
	bool		mov_left;
	bool		mov_up;
	bool		mov_down;
	int			sprites_count;
	t_point		pos;
	t_img		**sprites;
}	t_player;

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
	int			item_get;
	bool		exit_reached;
	bool		items_reached;
	bool		is_over;
	bool		is_start;
	t_point		**points;
	t_player	player;
	t_item		anim_item;
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
