/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:39:46 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:53:54 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_n(t_data *data, int y, int x, int index)
{
	if (data->map.map_arr[y - 1][x] != '1' && data->map.map_arr[y - 1][x] \
		!= 'C' && data->map.map_arr[y - 1][x] != 'D' && \
			data->map.map_arr[y - 1][x] != 'E')
	{
		data->map.map_arr[y][x] = '0';
		data->map.map_arr[y - 1][x] = 'D';
		put_asset(data, data->sprites.ground, y * 64, x * 64);
		put_asset(data, data->sprites.danger, ((y - 1) * 64), x * 64);
		data->pos_enemy[0][index] -= 1;
	}
	else
		move_enemys(data, y, x, index);
}

void	enemy_s(t_data *data, int y, int x, int index)
{
	if (data->map.map_arr[y + 1][x] != '1' && data->map.map_arr[y + 1][x] \
		!= 'C' && data->map.map_arr[y + 1][x] != 'D' && \
			data->map.map_arr[y + 1][x] != 'E')
	{
		data->map.map_arr[y][x] = '0';
		data->map.map_arr[y + 1][x] = 'D';
		put_asset(data, data->sprites.ground, y * 64, x * 64);
		put_asset(data, data->sprites.danger, ((y + 1) * 64), x * 64);
		data->pos_enemy[0][index] += 1;
	}
	else
		move_enemys(data, y, x, index);
}

void	enemy_w(t_data *data, int y, int x, int index)
{
	if (data->map.map_arr[y][x - 1] != '1' && data->map.map_arr[y][x - 1] \
		!= 'C' && data->map.map_arr[y][x - 1] != 'D' && \
			data->map.map_arr[y][x - 1] != 'E')
	{
		data->map.map_arr[y][x] = '0';
		data->map.map_arr[y][x - 1] = 'D';
		put_asset(data, data->sprites.ground, y * 64, x * 64);
		put_asset(data, data->sprites.danger, y * 64, ((x - 1) * 64));
		data->pos_enemy[1][index] -= 1;
	}
	else
		move_enemys(data, y, x, index);
}

void	enemy_e(t_data *data, int y, int x, int index)
{
	if (data->map.map_arr[y][x + 1] != '1' && data->map.map_arr[y][x + 1] \
		!= 'C' && data->map.map_arr[y][x + 1] != 'D' && \
			data->map.map_arr[y][x + 1] != 'E')
	{
		data->map.map_arr[y][x] = '0';
		data->map.map_arr[y][x + 1] = 'D';
		put_asset(data, data->sprites.ground, y * 64, x * 64);
		put_asset(data, data->sprites.danger, y * 64, ((x + 1) * 64));
		data->pos_enemy[1][index] += 1;
	}
	else
		move_enemys(data, y, x, index);
}

/*----------
move_dir dictates in what direction the enemy will move;
0 is up
1 is down
2 is left
3 is right
----------*/
void	move_enemys(t_data *data, int y_enemy, int x_enemy, int index)
{
	int	move_dir;
	int	y;
	int	x;
	int	stuck;

	move_dir = (rand() % 4);
	y = y_enemy;
	x = x_enemy;
	stuck = check_if_stuck(data, y, x);
	if (stuck == 1)
	{
		if (move_dir == 0)
			enemy_n(data, y, x, index);
		if (move_dir == 1)
			enemy_s(data, y, x, index);
		if (move_dir == 2)
			enemy_w(data, y, x, index);
		if (move_dir == 3)
			enemy_e(data, y, x, index);
	}
}
