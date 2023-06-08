/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:17:58 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:53:47 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_if_stuck(t_data *data, int y_enemy, int x_enemy)
{
	char	up;
	char	down;
	char	left;
	char	right;
	int		valid;

	up = data->map.map_arr[y_enemy - 1][x_enemy];
	down = data->map.map_arr[y_enemy + 1][x_enemy];
	left = data->map.map_arr[y_enemy][x_enemy - 1];
	right = data->map.map_arr[y_enemy][x_enemy + 1];
	valid = 0;
	if (up == 'P' || up == '0')
		valid = 1;
	if (down == 'P' || down == '0')
		valid = 1;
	if (left == 'P' || left == '0')
		valid = 1;
	if (right == 'P' || right == '0')
		valid = 1;
	return (valid);
}

void	check_collectibles(int collects, t_data *data)
{
	static int	flag;

	if (collects == data->map.collectibles && flag != 1)
	{
		ft_printf("\x1B[1;32mAll collectibles obtained!!\
Go to the exit!!\x1B[0m\n");
		flag = 1;
	}
}

void	check_win_condition(t_data *data)
{
	if ((data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] \
	== 'E') && (data->player.collects_in_inventory == data->map.collectibles))
	{
		ft_printf("\x1B[1;32mYou have successfuly completed the level !!\n");
		ft_printf("\x1B[1;32mFinal number of moves: %i\x1B[0m\n"\
		, data->player.moves);
		free_game(data);
	}
}

void	check_if_die(t_data *data)
{
	if (data->map.map_arr[data->player.y_pos_arr][data->player.x_pos_arr] \
	== 'D')
	{
		ft_printf("\x1B[1;31mYou have been killed by an enemy\x1B[0m\n");
		free_game(data);
	}
}
