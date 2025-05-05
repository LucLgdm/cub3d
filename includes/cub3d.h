/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/05 14:21:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

#include "image.h"
#include "map.h"

typedef struct s_game{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	*image;
	int		height_w;
	int		width_w;
} t_game;

/********************
 * 		Guetter
 ********************/

 t_game	*ft_get_game(void);

/********************
 * 	Initialisation
 ********************/

 void	ft_game_initialisation(int argc, char **argv);

/********************
 * 		Parsing
 ********************/

void	ft_parsing(t_game *game, char **argv);

	/*   LINK    */
char	*ft_get_link_image(int fd);
bool	ft_is_link(char *line);
void	ft_fill_link(char *line, int *counter);

	/*   COLOR   */
char	*ft_get_color(int fd, char *line);
bool	ft_fill_color(char c, char **splitted);

	/*    MAP    */
void	ft_get_map(t_game *game, int fd, char *line);
void	ft_new_line(int fd, char *line, t_game *game);
void	ft_check_map(t_game *game);
int		ft_check_border(t_map *map);
int		ft_check_content(char *line);
bool	ft_is_good_char(char c);
int		ft_check_wall(char *line);

/********************
 * 		Memory
 ********************/

void	ft_malloc_game(t_game *game);
void	ft_malloc_mlx(t_game *game);
void	ft_malloc_image(t_game *game);
void	ft_malloc_map(t_game *game);

void	ft_free_game(t_game *game);
void	ft_free_mlx(t_game *game);
void	ft_free_image(t_game *game);
void	ft_free_map(t_map *map);

/********************
 * 		Error
 ********************/

void	ft_print_error_and_exit(char *error_message);
void	ft_exit_parsing(int fd, char *line, char *error_message);
void	ft_print_image();
void	ft_print_game();
void	ft_print_map();

#endif