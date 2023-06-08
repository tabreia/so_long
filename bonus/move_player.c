/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:03:48 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 20:54:16 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_n(t_data *info)
{
	info->player.y_pos_arr -= 1;
	anim_n(info);
	info->player.moves++;
	render(info);
	return (1);
}

int	move_s(t_data *info)
{
	info->player.y_pos_arr += 1;
	anim_s(info);
	info->player.moves++;
	render(info);
	return (1);
}

int	move_w(t_data *info)
{
	info->player.x_pos_arr -= 1;
	anim_w(info);
	info->player.moves++;
	render(info);
	return (1);
}

int	move_e(t_data *info)
{
	info->player.x_pos_arr += 1;
	anim_e(info);
	info->player.moves++;
	render(info);
	return (1);
}
