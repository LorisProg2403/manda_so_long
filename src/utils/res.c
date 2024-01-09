/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:44:39 by lgaume            #+#    #+#             */
/*   Updated: 2023/12/23 23:44:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_res	new_res(bool state, int code, char *msg, t_data data)
{
	t_res	res;

	res.state = state;
	res.code = code;
	res.msg = msg;
	res.data = data;
	return (res);
}