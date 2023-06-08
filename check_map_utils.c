/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:02 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 16:17:13 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map_arr[y])
		y++;
	y--;
	while (map->map_arr[y][x])
		x++;
	x--;
	map->map_size.x = x;
	map->map_size.y = y;
}

int	check_map_val(t_data *data, char **map_val)
{
	int	y;
	int	x;

	y = 0;
	while (map_val[y])
	{
		x = 0;
		while (map_val[y][x])
		{
			if (map_val[y][x] == 'C')
			{
				ft_printf \
				("\x1B[1;31mError\n\x1B[31mCan't reach all collectibles\n");
				free_map(data);
			}
			if (map_val[y][x] == 'E')
			{
				ft_printf("\x1B[1;31mError\n\x1B[31mCan't reach exit\n");
				free_map(data);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	flood_fill(char **map_val, int y, int x)
{
	if (map_val[y][x] == 'F' || (map_val[y][x] != '0' && map_val[y][x] != 'C'\
		&& map_val[y][x] != 'E' && map_val[y][x] != 'P'))
		return ;
	map_val[y][x] = 'F';
	flood_fill(map_val, y - 1, x);
	flood_fill(map_val, y + 1, x);
	flood_fill(map_val, y, x - 1);
	flood_fill(map_val, y, x + 1);
}

char	**read_map(t_data *data, char *file_path)
{
	int		fd;
	int		lines;
	char	*str;
	char	**map;
	int		i;

	i = -1;
	lines = count_lines(file_path);
	if (lines > 0)
		map = (char **)malloc(sizeof(t_map) * lines);
	else
	{
		ft_printf("\x1B[1;31mError\n\x1B[31mEmpty map\n");
		free_map(data);
	}
	fd = open(file_path, O_RDONLY);
	while (i++ < lines)
	{
		str = get_next_line(fd);
		map[i] = ft_strtrim(str, "\n\r");
		free(str);
	}
	close(fd);
	return (map);
}

t_map	initiliaze_map(void)
{
	t_map	map;

	map.collectibles = 0;
	map.exit = 0;
	map.player = 0;
	map.map_size.x = 0;
	map.map_size.y = 0;
	return (map);
}
