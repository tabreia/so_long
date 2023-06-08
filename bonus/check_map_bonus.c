/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:51:22 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 15:55:50 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_elements(t_data *data)
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
				data->map.collectibles++;
			if (data->map.map_arr[y][x] == 'E')
				data->map.exit++;
			if (data->map.map_arr[y][x] == 'P')
			{
				data->player.player_start.x = x;
				data->player.player_start.y = y;
				data->map.player++;
			}
			x++;
		}
		y++;
	}
	return (check_elements(data));
}

int	check_bad_elements(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= data->map.map_size.y - 1)
	{
		x = 0;
		while (x <= data->map.map_size.x - 1)
		{
			if (data->map.map_arr[y][x] != '1' && \
				data->map.map_arr[y][x] != '0' && \
				data->map.map_arr[y][x] != 'C' && \
				data->map.map_arr[y][x] != 'E' && \
				data->map.map_arr[y][x] != 'P')
			{
				ft_printf("\x1B[1;31mError\n\x1B[31mInvalid element in map\n");
				free_map(data);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_file_extension(t_data *data, char *file_path)
{
	int		i;
	int		k;
	int		err;
	char	*ber;

	i = 0;
	k = 0;
	err = 0;
	ber = ".ber";
	while (file_path[i])
		i++;
	i -= 4;
	while (ber[k])
	{
		if (ber[k] != file_path[i])
			err = 1;
		k++;
		i++;
	}
	if (err == 1)
	{
		ft_printf("\x1B[1;31mError\x1B[0m\n\x1B[31mInvalid file type\x1B[0m\x1B[0m\n");
		free_map(data);
	}
	return (0);
}

void	check_map(t_data *data, char **map_val)
{
	check_rec(data);
	check_walls(data);
	check_bad_elements(data);
	get_elements(data);
	flood_fill(map_val, data->player.player_start.y, \
		data->player.player_start.x);
	check_map_val(data, map_val);
}

void	validate_map_file(char *file_path, t_data *data)
{
	int		i;

	i = 0;
	data->map = initiliaze_map();
	data->map.map_arr = read_map(data, file_path);
	if (!data->map.map_arr)
		free_map(data);
	data->map.map_val = read_map(data, file_path);
	if (validate_file_extension(data, file_path) == 1)
		free_map(data);
	get_map_size(&data->map);
	check_map(data, data->map.map_val);
	free_map_val(data);
}
