# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:49:27 by luclgdm           #+#    #+#              #
#    Updated: 2025/06/20 12:24:03 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs

NAME = cub3d

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
	map/invalid_map/inexistant_map.cub


# Liste des fichiers source
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)$(MEM_DIR)free.c \
			$(SRC_DIR)$(MEM_DIR)malloc.c \
			$(SRC_DIR)$(INI_DIR)game_init.c \
			$(SRC_DIR)$(INI_DIR)parsing.c \
			$(SRC_DIR)$(INI_DIR)parsing_link.c \
			$(SRC_DIR)$(INI_DIR)parsing_color.c \
			$(SRC_DIR)$(INI_DIR)parsing_map.c \
			$(SRC_DIR)$(INI_DIR)check_map.c \
			$(SRC_DIR)$(INI_DIR)image_generator.c \
			$(SRC_DIR)$(ERR_DIR)error.c \
			$(SRC_DIR)$(ERR_DIR)print.c \
			$(SRC_DIR)$(MLX_DIR)hook.c \
			$(SRC_DIR)$(MLX_DIR)quit.c \
			$(SRC_DIR)$(MLX_DIR)display.c \
			$(SRC_DIR)$(MLX_DIR)correction.c \
			$(SRC_DIR)$(MLX_DIR)drawing.c \
			$(SRC_DIR)$(MLX_DIR)raycasting.c \
			$(SRC_DIR)$(MLX_DIR)raycasting_2.c \
			$(SRC_DIR)$(MLX_DIR)raycasting_3.c \
			$(SRC_DIR)$(MLX_DIR)usefull.c \
			$(SRC_DIR)$(MLX_DIR)draw_world.c \
			$(SRC_DIR)$(MLX_DIR)status.c \
			$(SRC_DIR)$(MLX_DIR)move.c
			
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
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map/invalid_map/missing_player.cub || true

test: all
	@for file in $(INVALID_MAPS); do \
		echo ""; \
		echo "Testing $$file..."; \
		./$(NAME) $$file || true; \
	done
	@echo ""; echo "Testing without arguments..."; \
	./$(NAME) || true

.PHONY: all clean fclean re