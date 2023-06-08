/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:23:22 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 18:13:00 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->window.x = (data->map.map_size.x + 1) * 64;
	data->window.y = (data->map.map_size.y + 1) * 64;
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->window.x, data->window.y, "so_long");
	initial_render(data);
	if (data->win_ptr == NULL)
	{	
		free(data->win_ptr);
		return ;
	}
}
