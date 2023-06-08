/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:28:42 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 16:13:54 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_sprites
{
	char		*player;
	char		*ground;
	char		*wall;
	char		*crate;
	char		*coin;
	char		*exit;
	int			size;
}	t_sprites;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_map
{
	int			exit;
	int			player;
	int			collectibles;	
	char		**map_arr;
	char		**map_val;
	t_point		map_size;
}	t_map;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
}	t_img;

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
	int			collects_in_inventory;
	int			moves;
	t_point		player_start;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
	t_sprites	sprites;
	t_map		map;
	t_point		window;
}	t_data;

int			render(t_data *data);
int			get_elements(t_data *data);
int			check_boundaries(t_map *map);
int			put_wall_left(t_data *data, int i, int y);
int			put_wall_right(t_data *data, int i, int x, int y);
int			render_walls(t_data *data);
int			erase_assets(t_data *data);
int			free_game(t_data *data);
int			check_elements(t_data *data);
int			check_horizontal_walls(t_data *data, int y, int x);
int			check_vertical_walls(t_data *data, int y, int x);
int			check_map_val(t_data *data, char **map_val);
int			handle_input(int key, t_data *data);
int			move_n(t_data *data);
int			move_s(t_data *data);
int			move_w(t_data *data);
int			move_e(t_data *data);
int			count_lines(char *file_path);
int			put_wall_bottom(t_data *data, int i, int x, int y);
int			check_rec(t_data *data);
int			check_walls(t_data *data);
int			handle_keypress(int key, t_data *info);
int			check_if_file_exists(char *file_path);

void		flood_fill(char **map_val, int y, int x);
void		get_map_size(t_map *map);
void		put_to_window(t_data *data, int i, int loc);
void		put_wall_top(t_data *data, int i, int x, int y);
void		check_collectibles(int collects, t_data *data);
void		free_map(t_data *data);
void		validate_map_file(char *file_path, t_data *data);
void		put_asset(t_data *data, char *asset, int y_img, int x_img);
void		initial_render(t_data *data);
void		check_win_condition(t_data *data);
void		render_ground(t_data *data);
void		render_crates(t_data *data);
void		render_exit(t_data *data);
void		render_collectibles(t_data *data);
void		render_player(t_data *data);
void		free_map_val(t_data *data);
void		check_map(t_data *data, char **map_val);
void		init_window(t_data *data);

char		**read_map(t_data *data, char *file_path);

t_map		initiliaze_map(void);

t_player	get_init_player_pos(t_data *data);

t_data		*generate_t_data(void);

#endif
