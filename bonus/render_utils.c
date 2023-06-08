/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:09:48 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 10:42:42 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_enemys(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == 'D')
				put_asset(data, data->sprites.danger, y * 64, x * 64);
			x++;
		}
		y++;
	}
}

void	render_collectibles(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == 'C')
				put_asset(data, data->sprites.coin, y * 64, x * 64);
			x++;
		}
		y++;
	}
}

void	render_player(t_data *data)
{
	int	y;
	int	x;

	y = data->player.y_pos_img;
	x = data->player.x_pos_img;
	if (data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] \
		== 'E')
	{
		data->sprites.player = "./sprites/playerexit.xpm";
		put_asset(data, data->sprites.player, y, x);
		ft_printf("\x1B[1;32mYou have reached the exit !!\x1B[0m\n");
	}
	if (data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] \
		== 'C')
	{
		data->sprites.player = "./sprites/playercoin.xpm";
		put_asset(data, data->sprites.player, y, x);
		usleep(300000);
	}
	if (data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] \
		== 'P')
	{
		data->sprites.player = "./bonus/sprites/playerS_0.xpm";
		put_asset(data, data->sprites.player, y, x);
	}
}

void	render_exit(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == 'E')
				put_asset(data, data->sprites.exit, y * 64, x * 64);
			x++;
		}
		y++;
	}
}

void	render_crates(t_data *data)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->map.map_size.y)
	{
		x = 1;
		while (x < data->map.map_size.x)
		{
			if (data->map.map_arr[y][x] == '1')
				put_asset(data, data->sprites.crate, y * 64, x * 64);
			x++;
		}
		y++;
	}
}
