/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:25:53 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/12 12:25:54 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/so_long_bonus.h"

int	close_win(int n, void *params)
{
	(void)n;
	(void)params;
	ft_printf(BBLUE"\nGame closed\n"RESET);
	exit(EXIT_SUCCESS);
	return (0);
}
