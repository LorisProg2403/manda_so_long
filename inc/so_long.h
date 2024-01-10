/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:08:21 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 22:08:21 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "const.h"
# include "struct.h"
# include <fcntl.h>

// INIT_MAP
t_res		init_map(char *s, t_data *data);
int			get_map(char *s, t_game *game);
t_res		check_map(t_data data);
void		set_map(t_game *game);
t_res		is_winnable(t_data data);

// UTILS
t_res		new_res(bool state, int code, char *msg, t_data data);
t_point		n_point(int x, int y, char value);
void		free_points(t_game game);
void		free_map(t_game game);

// GAME
void		start_game(t_data *data);
void		add_img(t_data data, int x, int y, t_point p);
char		*get_path(t_point p);
void		new_img(t_data data, int x, int y, char *path);
void		get_corr(t_point *c, t_point p, int width, int height);
int			handle_key(int key, t_data *data);
// SO_LONG.C
void		endgame(t_data data);

#endif