/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:47:18 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/30 19:45:09 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_val(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map_val)
	{
		while (data->map.map_val[i])
			free(data->map.map_val[i++]);
		free(data->map.map_val);
		data->map.map_val = 0;
	}
}

void	free_map(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->map.map_arr)
	{
		while (data->map.map_arr[i])
			free(data->map.map_arr[i++]);
		free(data->map.map_arr);
	}
	if (data->map.map_val)
		free_map_val(data);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}

int	free_game(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return (0);
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = 0;
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_map(data);
	return (0);
}
