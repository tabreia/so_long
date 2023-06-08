/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:53:50 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 15:05:24 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_to_window(t_data *data, int i, int loc)
{
	char	*sprite;
	int		y;
	int		x;

	sprite = data->sprites.wall;
	y = data->window.y - 64;
	x = data->window.x - 64;
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	if (loc == 1)
		put_asset(data, sprite, 0, i);
	if (loc == 2)
		put_asset(data, sprite, i, 0);
	if (loc == 3)
		put_asset(data, sprite, y, i);
	if (loc == 4)
		put_asset(data, sprite, i, x);
}

void	put_wall_top(t_data *data, int i, int x, int y)
{
	while (data->map.map_arr[y][x])
	{
		if (data->map.map_arr[y][x] == '1')
		{
			put_to_window(data, i, 1);
			i += 64;
		}
		x++;
	}
}

int	put_wall_left(t_data *data, int i, int y)
{
	while (data->map.map_arr[y])
	{
		if (data->map.map_arr[y][0] == '1')
		{
			put_to_window(data, i, 2);
			i += 64;
		}
		y++;
	}
	y--;
	return (y);
}

int	put_wall_right(t_data *data, int i, int x, int y)
{
	while (data->map.map_arr[y][x])
	{
		if (data->map.map_arr[y][x] == '1')
		{
			put_to_window(data, i, 3);
			i += 64;
		}
		x++;
	}
	x--;
	return (x);
}

int	put_wall_bottom(t_data *data, int i, int x, int y)
{
	while (data->map.map_arr[y])
	{
		if (data->map.map_arr[y][x] == '1')
		{
			put_to_window(data, i, 4);
			i += 64;
		}
		y++;
	}
	return (y);
}
