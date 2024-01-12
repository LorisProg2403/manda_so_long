/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:35 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/12 12:31:36 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "const_bonus.h"
# include "struct_bonus.h"
# include <fcntl.h>

// UTILS
void	free_points(t_game game);
void	free_map(t_game game);
int		close_win(int n, void *params);
t_res	new_res(bool state, int code, char *msg, t_data data);
t_point	n_point(int x, int y, char value);

// GAME
void	get_corr(t_point *c, t_point p, int width, int height);
void	new_img(t_data data, int x, int y, char *path);
char	*get_path(t_point p);
void	add_img(t_data data, int x, int y, t_point p);
int		has_access(t_data data, t_point pos, int add_x, int add_y);
void	move(t_data data, int add_x, int add_y);
int		handle_key(int key, t_data *data);
void	start_game(t_data *data);

// INIT_MAP
t_res	check_map(t_data data);
int		get_map(char *s, t_game *game);
t_res	init_map(char *s, t_data *data);
t_res	is_winnable(t_data data);
void	set_map(t_game *game);

// SO_LONG.C
void	endgame(t_data data);

#endif
