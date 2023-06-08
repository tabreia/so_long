/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:13:13 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/27 18:38:43 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	put_player(t_data *data)
{
	int	size;

	size = 64;
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
					data->sprites.player, &size, &size);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.mlx_img, data->player.x_pos_img, data->player.y_pos_img);
}

void	anim_n(t_data *data)
{
	int	init_y;
	int	init_x;

	init_y = data->player.y_pos_img;
	init_x = data->player.x_pos_img;
	data->player.y_pos_img -= 21;
	data->sprites.player = data->sprites.player_n[1];
	put_asset(data, data->sprites.ground, init_y, init_x);
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.y_pos_img -= 21;
	data->sprites.player = data->sprites.player_n[2];
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.y_pos_img -= 22;
	data->sprites.player = data->sprites.player_n[0];
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
}

void	anim_s(t_data *data)
{
	int	init_y;
	int	init_x;

	init_y = data->player.y_pos_img;
	init_x = data->player.x_pos_img;
	data->player.y_pos_img += 21;
	data->sprites.player = data->sprites.player_s[1];
	put_asset(data, data->sprites.ground, init_y, init_x);
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.y_pos_img += 21;
	data->sprites.player = data->sprites.player_s[2];
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.y_pos_img += 22;
	data->sprites.player = data->sprites.player_s[0];
	put_asset(data, data->sprites.player, data->player.y_pos_img, init_x);
	put_asset(data, data->sprites.ground, init_y, init_x);
}

void	anim_w(t_data *data)
{
	int	init_y;
	int	init_x;

	init_y = data->player.y_pos_img;
	init_x = data->player.x_pos_img;
	data->player.x_pos_img -= 21;
	data->sprites.player = data->sprites.player_w[1];
	put_asset(data, data->sprites.ground, init_y, init_x);
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.x_pos_img -= 21;
	data->sprites.player = data->sprites.player_w[2];
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.x_pos_img -= 22;
	data->sprites.player = data->sprites.player_w[0];
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
}

void	anim_e(t_data *data)
{
	int	init_y;
	int	init_x;

	init_y = data->player.y_pos_img;
	init_x = data->player.x_pos_img;
	data->player.x_pos_img += 21;
	data->sprites.player = data->sprites.player_e[1];
	put_asset(data, data->sprites.ground, init_y, init_x);
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.x_pos_img += 21;
	data->sprites.player = data->sprites.player_e[2];
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
	usleep(175000);
	data->player.x_pos_img += 22;
	data->sprites.player = data->sprites.player_e[0];
	put_asset(data, data->sprites.player, init_y, data->player.x_pos_img);
	put_asset(data, data->sprites.ground, init_y, init_x);
}
