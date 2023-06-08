/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_enemys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:56:33 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 17:46:10 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_zeros(t_map *map)
{
	int	y;
	int	x;
	int	zeroes;

	y = 0;
	zeroes = 0;
	while (y <= map->map_size.y)
	{
		x = 0;
		while (x <= map->map_size.x)
		{
			if (map->map_arr[y][x] == '0')
				zeroes++;
			x++;
		}
		y++;
	}
	return (zeroes);
}

int	rand_place_enemy(t_map *map, int y, int x)
{
	int	place;

	place = ((rand() % 10) + 1);
	if (place == 1)
	{
		map->map_arr[y][x] = 'D';
		return (1);
	}
	return (0);
}

void	place_enemys(t_map *map, int num_of_enemys)
{
	int	y;
	int	x;
	int	place;

	place = 0;
	while (num_of_enemys > 0)
	{
		y = 0;
		while (++y < map->map_size.y)
		{
			x = 0;
			while (++x < map->map_size.x)
			{
				if (map->map_arr[y][x] == '0')
				{
					if (rand_place_enemy(map, y, x) == 1)
						num_of_enemys--;
					if (num_of_enemys == 0)
						return ;
				}
			}
		}
	}
}

void	generate_enemys(t_map *map)
{
	int	zeroes;
	int	num_of_enemys;

	zeroes = count_zeros(map);
	num_of_enemys = zeroes / 10;
	if (num_of_enemys == 0)
		num_of_enemys++;
	place_enemys(map, num_of_enemys);
	map->dangers = num_of_enemys;
}
