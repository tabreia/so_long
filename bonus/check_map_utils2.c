/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:11 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/30 17:50:01 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_rec(t_data *data)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	while (data->map.map_arr[0][i])
		i++;
	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
			x++;
		if (x != i)
		{
			ft_printf("\x1B[1;31mError\n\x1B[31mMap isn't rectangular\n");
			free_map(data);
		}
		y++;
	}
	return (0);
}

int	check_horizontal_walls(t_data *data, int y, int x)
{
	while (x <= data->map.map_size.x)
	{
		if (data->map.map_arr[0][x] != '1')
		{
			ft_printf("\x1B[1;31mError\n\x1B[31mMap isn't surrounded by walls\n");
			free_map(data);
		}
		x++;
	}
	x = 0;
	while (x <= data->map.map_size.x)
	{
		if (data->map.map_arr[y][x] != '1')
		{
			ft_printf("\x1B[1;31mError\n\x1B[31mMap isn't surrounded by walls\n");
			free_map(data);
		}
		x++;
	}
	return (0);
}

int	check_vertical_walls(t_data *data, int y, int x)
{
	while (y <= data->map.map_size.y)
	{
		if (data->map.map_arr[y][0] != '1')
		{
			ft_printf("\x1B[1;31mError\n\x1B[31mMap isn't surrounded by walls\n");
			free_map(data);
		}
		y++;
	}
	y = 0;
	while (y <= data->map.map_size.y)
	{
		if (data->map.map_arr[y][x] != '1')
		{
			ft_printf("\x1B[1;31mError\n\x1B[31mMap isn't surrounded by walls\n");
			free_map(data);
		}
		y++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int	err;

	err = check_horizontal_walls(data, data->map.map_size.y, 0);
	err += check_vertical_walls(data, 0, data->map.map_size.x);
	return (err);
}

int	check_elements(t_data *data)
{
	if (data->map.collectibles < 1 || \
		data->map.exit != 1 || data->map.player != 1)
	{
		ft_printf("\x1B[1;31mError\n\x1B[31m");
		if (data->map.collectibles < 1)
			ft_printf \
			("Number of collectibles is less than one\n");
		if (data->map.exit != 1)
			ft_printf \
			("Number of exits is different than one\n");
		if (data->map.player != 1)
			ft_printf \
			("Invalid number of player spawn points\n");
		free_map(data);
	}
	return (0);
}
