/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:16:56 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 16:17:22 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_if_file_exists(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\x1B[1;31mError\n\x1B[31mInvalid file path\n");
		close(fd);
		exit(0);
	}
	return (0);
}

void	init_window(t_data *data)
{
	data->window.x = (data->map.map_size.x + 1) * 64;
	data->window.y = (data->map.map_size.y + 1) * 64;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window.x, \
		data->window.y, "so_long");
}
