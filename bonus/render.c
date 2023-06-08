/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:01:43 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:54:35 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_printf("\x1B[32mCurrent number of moves:\x1B[0m %i\n"\
		, info->player.moves);
	return (0);
}

void	render_ground(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map.map_arr[y])
	{
		x = 0;
		while (data->map.map_arr[y][x])
		{
			if (data->map.map_arr[y][x] == '0')
				put_asset(data, data->sprites.ground, y * 64, x * 64);
			x++;
		}
		y++;
	}
}

void	initial_render(t_data *data)
{
	render_walls(data);
	render_ground(data);
	render_crates(data);
	render_enemys(data);
	render_collectibles(data);
}

void	render_assets(t_data *data)
{
	int	x;
	int	y;
	int	size;

	size = 64;
	x = data->map.map_size.x;
	y = data->map.map_size.y;
	render_n_of_moves(data, data->player.moves, \
		count_n_of_digits(data->player.moves));
	render_exit(data);
	render_player(data);
}

int	render(t_data *data)
{
	int	i;

	i = 0;
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	render_assets(data);
	data->player.collects_in_inventory = erase_assets(data);
	check_collectibles(data->player.collects_in_inventory, data);
	check_win_condition(data);
	check_if_die(data);
	if (data->player.moves != 0)
	{
		while (i < data->map.dangers)
		{
			move_enemys(data, data->pos_enemy[0][i], \
				data->pos_enemy[1][i], i);
			i++;
		}
	}
	check_if_die(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	return (0);
}
