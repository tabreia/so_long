/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:51:16 by tabreia-          #+#    #+#             */
/*   Updated: 2023/03/28 18:12:55 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**init_sprites_n(t_sprites *sprites)
{
	sprites->player_n = (char **)malloc(sizeof(t_sprites) * 3);
	if (!sprites->player_n)
	{
		free(sprites->player_n[0]);
		free(sprites->player_n[1]);
		free(sprites->player_n[2]);
		return (NULL);
	}	
	sprites->player_n[0] = "./sprites/playerN_0.xpm";
	sprites->player_n[1] = "./sprites/playerN_1.xpm";
	sprites->player_n[2] = "./sprites/playerN_2.xpm";
	return (sprites->player_n);
}

char	**init_sprites_s(t_sprites *sprites)
{
	sprites->player_s = (char **)malloc(sizeof(t_sprites) * 3);
	if (!sprites->player_s)
	{
		free(sprites->player_s[0]);
		free(sprites->player_s[1]);
		free(sprites->player_s[2]);
		return (NULL);
	}	
	sprites->player_s[0] = "./sprites/playerS_0.xpm";
	sprites->player_s[1] = "./sprites/playerS_1.xpm";
	sprites->player_s[2] = "./sprites/playerS_2.xpm";
	return (sprites->player_s);
}

char	**init_sprites_e(t_sprites *sprites)
{
	sprites->player_e = (char **)malloc(sizeof(t_sprites) * 3);
	if (!sprites->player_e)
	{
		free(sprites->player_e[0]);
		free(sprites->player_e[1]);
		free(sprites->player_e[2]);
		return (NULL);
	}	
	sprites->player_e[0] = "./sprites/playerE_0.xpm";
	sprites->player_e[1] = "./sprites/playerE_1.xpm";
	sprites->player_e[2] = "./sprites/playerE_2.xpm";
	return (sprites->player_e);
}

char	**init_sprites_w(t_sprites *sprites)
{
	sprites->player_w = (char **)malloc(sizeof(t_sprites) * 3);
	if (!sprites->player_w)
	{
		free(sprites->player_w[0]);
		free(sprites->player_w[1]);
		free(sprites->player_w[2]);
		return (NULL);
	}	
	sprites->player_w[0] = "./sprites/playerW_0.xpm";
	sprites->player_w[1] = "./sprites/playerW_1.xpm";
	sprites->player_w[2] = "./sprites/playerW_2.xpm";
	return (sprites->player_w);
}

void	init_anim_sprites(t_data *data)
{
	data->sprites.player_n = init_sprites_n(&data->sprites);
	data->sprites.player_s = init_sprites_s(&data->sprites);
	data->sprites.player_w = init_sprites_w(&data->sprites);
	data->sprites.player_e = init_sprites_e(&data->sprites);
}
