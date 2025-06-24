# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:49:27 by luclgdm           #+#    #+#              #
#    Updated: 2025/06/24 15:04:49 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs srcs/Error srcs/Initialisation srcs/Memory srcs/Mlx 

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I $(INCLUDES)
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

INVALID_MAPS = \
	map/invalid_map/additionnal_element.cub \
	map/invalid_map/doople_element.cub \
	map/invalid_map/doople_F_C.cub \
	map/invalid_map/invalid_path.cub \
	map/invalid_map/invalid_path_2.cub \
	map/invalid_map/lower_case.cub \
	map/invalid_map/missing_F_C.cub \
	map/invalid_map/missing_link.cub \
	map/invalid_map/missing_player.cub \
	map/invalid_map/wrong_border.cub \
	map/invalid_map/wrong_border_2.cub \
	map/invalid_map/wrong_char.cub \
	map/invalid_map/wrong_color.cub \
	map/invalid_map/map.txt \
	map/invalid_map/inexistant_map.cub \
	map/invalid_map/invalid_texture.cub \
	map/invalid_map/vide.cub \
	map/invalid_map/wrong_color_2.cub 


# Liste des fichiers source
SRC_FILES = main.c free.c malloc.c game_init.c parsing.c parsing_link.c \
			parsing_color.c parsing_map.c check_map.c image_generator.c \
			error.c print.c hook.c quit.c display.c correction.c \
			drawing.c raycasting.c raycasting_2.c raycasting_3.c \
			usefull.c draw_world.c status.c move.c 
			
# Transforme chaque fichier source en un fichier objet dans $(OBJ_DIR)
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: mkdir_obj $(NAME)

# Compilation des fichiers .c en .o dans le dossier $(OBJ_DIR)
$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier objs/ et des sous-répertoires s'ils n'existent pas
mkdir_obj:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)$(MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)$(INI_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)$(ERR_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)$(MLX_DIR)

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

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map/valid_map/map_3.cub || true

test: all
	@for file in $(INVALID_MAPS); do \
		echo ""; \
		echo "Testing $$file..."; \
		./$(NAME) $$file || true; \
	done
	@echo ""; echo "Testing without arguments..."; \
	./$(NAME) || true

.PHONY: all clean fclean re
