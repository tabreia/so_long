/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:03:36 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 14:48:41 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_n(t_data *data)
{
	int	y;
	int	x;

	data->sprites.player = "./sprites/player.xpm";
	y = data->player.y_pos * 64;
	x = data->player.x_pos * 64;
	put_asset(data, data->sprites.ground, y, x);
	data->player.y_pos -= 1;
	y -= 64;
	put_asset(data, data->sprites.player, y, x);
	data->player.moves++;
	return (1);
}

int	move_s(t_data *data)
{
	int	y;
	int	x;

	data->sprites.player = "./sprites/player.xpm";
	y = data->player.y_pos * 64;
	x = data->player.x_pos * 64;
	put_asset(data, data->sprites.ground, y, x);
	data->player.y_pos += 1;
	y += 64;
	put_asset(data, data->sprites.player, y, x);
	data->player.moves++;
	return (1);
}

int	move_e(t_data *data)
{
	int	y;
	int	x;

	data->sprites.player = "./sprites/player.xpm";
	y = data->player.y_pos * 64;
	x = data->player.x_pos * 64;
	put_asset(data, data->sprites.ground, y, x);
	data->player.x_pos += 1;
	x += 64;
	put_asset(data, data->sprites.player, y, x);
	data->player.moves++;
	return (1);
}

int	move_w(t_data *data)
{
	int	y;
	int	x;

	data->sprites.player = "./sprites/player.xpm";
	y = data->player.y_pos * 64;
	x = data->player.x_pos * 64;
	put_asset(data, data->sprites.ground, y, x);
	data->player.x_pos -= 1;
	x -= 64;
	put_asset(data, data->sprites.player, y, x);
	data->player.moves++;
	return (1);
}
