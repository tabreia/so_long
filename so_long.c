/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:08:50 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 16:13:01 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*generate_t_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img.mlx_img = 0;
	data->sprites.player = "./sprites/player.xpm";
	data->sprites.ground = "./sprites/ground.xpm";
	data->sprites.wall = "./sprites/wall.xpm";
	data->sprites.crate = "./sprites/crate.xpm";
	data->sprites.coin = "./sprites/coin.xpm";
	data->sprites.exit = "./sprites/exit.xpm";
	data->player.x_pos = 0;
	data->player.y_pos = 0;
	data->player.collects_in_inventory = 0;
	data->map.collectibles = 0;
	return (data);
}

void	check_collectibles(int collects, t_data *data)
{
	static int	flag;

	if (collects == data->map.collectibles && flag != 1)
	{
		ft_printf("All collectibles obtained!! Go to the exit!!\n");
		flag = 1;
	}
}

void	check_win_condition(t_data *data)
{
	if ((data->map.map_arr[data->player.y_pos][data->player.x_pos] == 'E') && \
		(data->player.collects_in_inventory == data->map.collectibles))
	{
		ft_printf("You have successfuly completed the level !!\n");
		ft_printf("Final number of moves: %i", data->player.moves);
		free_game(data);
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
				data->player.x_pos = x;
				data->player.y_pos = y;
			}
			x++;
		}
		y++;
	}
	return (data->player);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	check_if_file_exists(av[1]);
	data = generate_t_data();
	validate_map_file(av[1], data);
	data->player = get_init_player_pos(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	init_window(data);
	if (data->win_ptr == NULL)
	{	
		free(data->win_ptr);
		return (1);
	}
	initial_render(data);
	mlx_hook(data->win_ptr, 17, 1L << 17, free_game, data);
	render(data);
	data->player.moves = handle_input(0, data);
	mlx_loop(data->mlx_ptr);
	free_game(data);
}
