# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:45:44 by tabreia-          #+#    #+#              #
#    Updated: 2023/03/30 16:55:23 by tabreia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

DEPS = minilibx-linux/mlx.h libft/libft.a

NAME = so_long

BONUS_NAME = so_long_bonus

SRC = check_map.c check_map_utils2.c check_map_utils.c count_lines.c \
free.c move_player.c puts.c render.c render_utils.c so_long.c walls.c \
handle_keypress.c

OBJ = $(SRC:.c=.o)

BONUS = ./bonus/animations.c ./bonus/check_map_bonus.c \
./bonus/check_map_utils2.c ./bonus/check_map_utils.c ./bonus/checks.c \
./bonus/count_lines.c ./bonus/enemys.c ./bonus/extra.c ./bonus/free.c \
./bonus/generate_enemys.c ./bonus/handle_data.c ./bonus/handle_keypress.c \
./bonus/initialize_sprites.c ./bonus/initialize_window.c ./bonus/move_player.c \
./bonus/puts.c ./bonus/render.c ./bonus/render_counter.c ./bonus/render_utils.c \
./bonus/render_walls.c ./bonus/so_long_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) $@ -C ./libft
	$(MAKE) $@ -C ./minilibx-linux
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME) $(BONUS_NAME)

bonus: bonus_deps $(BONUS_NAME)
bonus_deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
$(BONUS_NAME): $(BONUS_OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(MLXFLAGS) -o $(BONUS_NAME)

re: fclean all
	$(MAKE) re -C ./libft
	$(MAKE) re -C ./minilibx-linux