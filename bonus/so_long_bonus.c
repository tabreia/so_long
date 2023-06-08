/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:08:50 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 16:10:14 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_data	*generate_t_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		free_game(data);
		return (0);
	}
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img.mlx_img = 0;
	data->map.map_val = 0;
	data->sprites.player = "./bonus/sprites/player.xpm";
	data->sprites.ground = "./bonus/sprites/ground.xpm";
	data->sprites.wall = "./bonus/sprites/wall.xpm";
	data->sprites.crate = "./bonus/sprites/crate.xpm";
	data->sprites.coin = "./bonus/sprites/coin.xpm";
	data->sprites.exit = "./bonus/sprites/exit.xpm";
	data->sprites.hud_back = "./bonus/sprites/hud_back.xpm";
	data->sprites.danger = "./bonus/sprites/danger.xpm";
	data->player.x_pos_arr = 0;
	data->player.y_pos_arr = 0;
	data->player.collects_in_inventory = 0;
	return (data);
}

char	**init_number_sprites(t_data *data)
{
	data->sprites.numbers = (char **)malloc(sizeof(t_sprites) * 10);
	if (!data->sprites.numbers)
	{
		free_game(data);
		return (0);
	}
	data->sprites.numbers[0] = "./bonus/sprites/numbers/0.xpm";
	data->sprites.numbers[1] = "./bonus/sprites/numbers/1.xpm";
	data->sprites.numbers[2] = "./bonus/sprites/numbers/2.xpm";
	data->sprites.numbers[3] = "./bonus/sprites/numbers/3.xpm";
	data->sprites.numbers[4] = "./bonus/sprites/numbers/4.xpm";
	data->sprites.numbers[5] = "./bonus/sprites/numbers/5.xpm";
	data->sprites.numbers[6] = "./bonus/sprites/numbers/6.xpm";
	data->sprites.numbers[7] = "./bonus/sprites/numbers/7.xpm";
	data->sprites.numbers[8] = "./bonus/sprites/numbers/8.xpm";
	data->sprites.numbers[9] = "./bonus/sprites/numbers/9.xpm";
	return (data->sprites.numbers);
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

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	srand(time(0));
	check_if_file_exists(av[1]);
	data = generate_t_data();
	validate_map_file(av[1], data);
	data->player = get_init_player_pos(data);
	data->pos_enemy = (int **)malloc(sizeof(int *) * 2);
	if (!data->pos_enemy)
		free_game(data);
	generate_enemys(&data->map);
	get_enemy_pos(data);
	init_anim_sprites(data);
	data->sprites.numbers = init_number_sprites(data);
	data->player.x_pos_img = data->player.x_pos_arr * 64;
	data->player.y_pos_img = data->player.y_pos_arr * 64;
	init_window(data);
	mlx_hook(data->win_ptr, 17, 1L << 17, free_game, data);
	data->player.moves = handle_input(0, data);
	render(data);
	mlx_loop(data->mlx_ptr);
	free_game(data);
}
