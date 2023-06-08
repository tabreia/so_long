/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:18:52 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:53:57 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_walls(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	put_wall_top(data, i, x, y);
	i = 0;
	y = put_wall_left(data, i, y);
	x = 0;
	i = 0;
	x = put_wall_right(data, i, x, y);
	y = 0;
	i = 0;
	y = put_wall_bottom(data, i, x, y);
	i = 0;
	x = 0;
	put_hud_back(data, i, x, y);
	return (0);
}

int	erase_assets(t_data *data)
{
	static int	collects;
	static int	i;

	if (i != 1)
	{
		i = 1;
		collects = 0;
	}
	if (data->map.map_arr[data->player.y_pos_arr] \
	[data->player.x_pos_arr] == 'C')
	{
		data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] = '0';
		collects++;
	}
	if (data->map.map_arr[data->player.y_pos_arr] \
	[data->player.x_pos_arr] == 'P')
	{
		data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] = '0';
	}
	return (collects);
}
