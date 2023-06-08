/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:05:21 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:54:05 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*-------------------
pos_arr[0] saves the coordinates of all the enemys on the y axis
while pos_arr[1] saves the coordinates of all the enemys on the x axis
--------------------*/
void	get_enemy_pos(t_data *data)
{
	int	x_arr;
	int	y_arr;
	int	i;

	y_arr = 0;
	i = 0;
	data->pos_enemy[0] = malloc(sizeof(int) * data->map.dangers);
	if (!data->pos_enemy[0])
		free_game(data);
	data->pos_enemy[1] = malloc(sizeof(int) * data->map.dangers);
	if (!data->pos_enemy[1])
		free_game(data);
	while (y_arr <= data->map.map_size.y)
	{
		x_arr = -1;
		while (++x_arr <= data->map.map_size.x)
		{
			if (data->map.map_arr[y_arr][x_arr] == 'D')
			{
				data->pos_enemy[0][i] = y_arr;
				data->pos_enemy[1][i++] = x_arr;
			}	
		}
		y_arr++;
	}
}

t_player	get_init_player_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == 'P')
			{
				data->player.x_pos_arr = x;
				data->player.y_pos_arr = y;
			}
			x++;
		}
		y++;
	}
	return (data->player);
}
