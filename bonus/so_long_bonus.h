/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:28:42 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/10 15:47:45 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <time.h>

typedef struct s_sprites
{
	char		**player_n;
	char		**player_s;
	char		**player_w;
	char		**player_e;
	char		**numbers;
	char		*player;
	char		*ground;
	char		*wall;
	char		*danger;
	char		*hud_back;
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
	int			dangers;
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
	int			x_pos_arr;
	int			y_pos_arr;
	int			x_pos_img;
	int			y_pos_img;
	int			collects_in_inventory;
	int			moves;
	char		dir;
	t_point		player_start;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**pos_enemy;
	t_img		img;
	t_player	player;
	t_sprites	sprites;
	t_map		map;
	t_point		window;
}	t_data;

int			handle_input(int key, t_data *data);
int			render(t_data *data);
int			render_walls(t_data *data);
int			check_rec(t_data *data);
int			put_wall_left(t_data *data, int i, int y);
int			put_wall_right(t_data *data, int i, int x, int y);
int			put_wall_bottom(t_data *data, int i, int x, int y);
int			erase_assets(t_data *data);
int			count_n_of_digits(int moves);
int			move_n(t_data *info);
int			move_s(t_data *info);
int			move_e(t_data *info);
int			move_w(t_data *info);
int			handle_keypress(int key, t_data *info);
int			check_map_val(t_data *data, char **map_val);
int			check_if_stuck(t_data *data, int y_enemy, int x_enemy);
int			free_game(t_data *data);
int			check_elements(t_data *data);
int			check_walls(t_data *data);
int			count_lines(char *file_path);

void		flood_fill(char **map_val, int y, int x);
void		get_map_size(t_map *map);
void		get_enemy_pos(t_data *data);
void		put_to_window(t_data *data, int i, int loc);
void		put_wall_top(t_data *data, int i, int x, int y);
void		put_hud_back(t_data *data, int i, int x, int y);
void		move_enemys(t_data *data, int y_enemy, int x_enemy, int index);
void		initial_render(t_data *data);
void		render_crates(t_data *data);
void		render_exit(t_data *data);
void		render_player(t_data *data);
void		render_collectibles(t_data *data);
void		render_assets(t_data *data);
void		render_enemys(t_data *data);
void		render_n_of_moves(t_data *data, int moves, int digits);
void		check_collectibles(int collects, t_data *data);
void		check_win_condition(t_data *data);
void		check_if_die(t_data *data);
void		anim_n(t_data *data);
void		anim_s(t_data *data);
void		anim_w(t_data *data);
void		anim_e(t_data *data);
void		generate_enemys(t_map *map);
void		init_anim_sprites(t_data *data);
void		init_window(t_data *data);
void		free_map(t_data *data);
void		free_numbers(t_data *data);
void		free_sprites(t_data *data);
void		put_asset(t_data *data, char *asset, int y_img, int x_img);
void		free_map_val(t_data *data);

char		**read_map(t_data *data, char *file_path);

t_map		initiliaze_map(void);
void		validate_map_file(char *file_path, t_data *data);

t_player	get_init_player_pos(t_data *data);

#endif
