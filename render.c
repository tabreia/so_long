/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:54:41 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 14:48:50 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}

void	render_ground(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == '0')
				put_asset(data, data->sprites.ground, y * 64, x * 64);
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

void	render_player(t_data *data)
{
	int	y;
	int	x;

	y = data->player.y_pos;
	x = data->player.x_pos;
	if (data->map.map_arr[y][x] == 'E')
	{
		data->sprites.player = "./sprites/playerexit.xpm";
		put_asset(data, data->sprites.player, y * 64, x * 64);
		ft_printf("\x1B[1;32mYou have reached the exit !!\x1B[0m\n");
	}
	if (data->map.map_arr[y][x] == 'C')
	{
		data->sprites.player = "./sprites/playercoin.xpm";
		put_asset(data, data->sprites.player, y * 64, x * 64);
	}
	if (data->map.map_arr[y][x] == 'P')
	{
		data->sprites.player = "./sprites/playerS_0.xpm";
		put_asset(data, data->sprites.player, y * 64, x * 64);
	}
}
