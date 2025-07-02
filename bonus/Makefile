# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:49:27 by luclgdm           #+#    #+#              #
#    Updated: 2025/07/02 15:57:22 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs srcs/Error srcs/Gameplay srcs/Initialisation srcs/Memory srcs/Mlx

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -I $(INCLUDES)
FLAGS = $(LIBFT) $(MLX) -I mlx -Lmlx -lmlx -lX11 -lXext -lm

LIBFT = libft/libft.a
MLX = mlx/libmlx.a
INCLUDES = includes/
OBJ_DIR = objs/
SRC_DIR = srcs/
MEM_DIR = Memory/
INI_DIR = Initialisation/
ERR_DIR = Error/
MLX_DIR = Mlx/
GME_DIR = Gameplay/

# Liste des fichiers source
SRC_FILES = main.c free.c malloc.c 	game_init.c parsing.c parsing_link.c image_tools.c \
			parsing_map.c fill_struct.c check_map.c	image_generator.c error.c \
			print.c display.c correction.c drawing.c raycasting.c raycasting_2.c \
			raycasting_3.c usefull.c draw_world.c status.c quit.c extra.c \
			move.c doors.c move_use.c mini_map.c display_enemy.c mini_map_enemy.c \
			draw_geometrical.c move_enemy.c image_vilain.c
			
# Transforme chaque fichier source en un fichier objet dans $(OBJ_DIR)
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: mkdir_obj $(NAME)

# Compilation des fichiers .c en .o dans le dossier $(OBJ_DIR)
$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier objs/ et des sous-répertoires s'ils n'existent pas
mkdir_obj:
	@mkdir -p $(OBJ_DIR)

# Compilation finale
$(NAME): $(OBJS)
	@echo "\033[34mmlx en cours\033[0m"
	@make -C mlx all > /dev/null 2>&1
	@echo "\033[0;32mSUCCESS !\033[0m \033[0;33mmlx\033[0m"
	@echo "\033[34mlibft en cours\033[0m"
	@make -C libft all --silent
	@echo "\033[0;32mSUCCESS !\033[0m \033[0;33mlibft\033[0m"
	@echo "\033[34mCompilation $(NAME) en cours\033[0m"
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	@echo "\033[0;32mSUCCESS !\033[0m \033[0;33m$(NAME)\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;34mDeleting almost everything !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;35mDeleting everything !\033[0m"
	@make -C libft fclean --silent
	@make -C mlx clean > /dev/null 2>&1

re: fclean all

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map/map.cub

cal: re
	valgrind --tool=callgrind ./$(NAME) map/map.cub
	@echo "\033[0;32mCallgrind finished !\033[0m"
	@echo "\033[0;33mRunning: kcachegrind callgrind.out.*\033[0m"
	kcachegrind callgrind.out.*
.PHONY: all clean fclean re