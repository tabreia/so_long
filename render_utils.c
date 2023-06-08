/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:55:31 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/29 15:03:23 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_data *data)
{
	static t_data	*info;
	int				valid;

	valid = 0;
	if (!info)
	{
		info = data;
		info->player.moves = 0;
	}
	if (key == XK_Escape)
		free_game(data);
	valid = handle_keypress(key, info);
	if (valid)
	{
		render(info);
		ft_printf("\x1B[32mCurrent number of moves:\x1B[0m %i\n"\
		, info->player.moves);
	}
	return (0);
}

void	initial_render(t_data *data)
{
	render_walls(data);
	render_ground(data);
	render_crates(data);
	render_collectibles(data);
}

int	render(t_data *data)
{
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	render_exit(data);
	render_player(data);
	data->player.collects_in_inventory = erase_assets(data);
	check_collectibles(data->player.collects_in_inventory, data);
	check_win_condition(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	return (0);
}

int	erase_assets(t_data *data)
{
	static int	collects;
	static int	i;

	if (i != 1)
	{
		i = 1;
		collects = 0;
	}
	if (data->map.map_arr[data->player.y_pos][data->player.x_pos] == 'C')
	{
		data->map.map_arr[data->player.y_pos][data->player.x_pos] = '0';
		collects++;
	}
	if (data->map.map_arr[data->player.y_pos][data->player.x_pos] == 'P')
	{
		data->map.map_arr[data->player.y_pos][data->player.x_pos] = '0';
	}
	return (collects);
}

void	render_collectibles(t_data *data)
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
				put_asset(data, data->sprites.coin, y * 64, x * 64);
			x++;
		}
		y++;
	}
}
