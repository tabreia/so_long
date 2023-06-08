/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:16:56 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:52:45 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_hud_back(t_data *data, int i, int x, int y)
{
	while (y <= data->map.map_size.y)
	{
		while (x <= data->map.map_size.x)
		{
			put_to_window(data, i, 5);
			x++;
			i += 64;
		}
		y++;
	}
}

void	put_asset(t_data *data, char *asset, int y_img, int x_img)
{
	int	size;

	size = 64;
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		asset, &size, &size);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.mlx_img, x_img, y_img);
}
