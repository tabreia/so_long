/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:11:27 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:54:21 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_n_of_digits(int moves)
{
	int	count;

	count = 0;
	while (moves != 0)
	{
		moves = moves / 10;
		count++;
	}
	return (count);
}

void	put_nbr_on_screen(t_data *data, int moves, int digits)
{
	int	x;
	int	y;

	x = (data->map.map_size.x + 1) - digits;
	y = data->map.map_size.y;
	put_asset(data, data->sprites.numbers[moves], y * 64, x * 64);
}

void	render_n_of_moves(t_data *data, int moves, int digits)
{
	static int	n;

	n = digits;
	if (moves == 0)
		put_nbr_on_screen(data, 0, 1);
	else if (moves >= 10)
	{
		render_n_of_moves(data, moves / 10, digits);
		moves = moves % 10;
	}
	if (moves < 10)
		put_nbr_on_screen(data, moves, n--);
}
