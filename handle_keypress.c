/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:55:09 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 15:05:39 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_data *info)
{
	int	valid;

	valid = 0;
	if ((key == XK_w || key == XK_Up) && (info->map.map_arr \
	[info->player.y_pos - 1][info->player.x_pos] != '1'))
		valid = move_n(info);
	if ((key == XK_s || key == XK_Down) && (info->map.map_arr \
	[info->player.y_pos + 1][info->player.x_pos] != '1'))
		valid = move_s(info);
	if ((key == XK_a || key == XK_Left) && (info->map.map_arr \
	[info->player.y_pos][info->player.x_pos - 1] != '1'))
		valid = move_w(info);
	if ((key == XK_d || key == XK_Right) && (info->map.map_arr \
	[info->player.y_pos][info->player.x_pos + 1] != '1'))
		valid = move_e(info);
	return (valid);
}
