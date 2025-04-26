/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/26 11:28:32 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3d_H
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
 void	ft_map_initialisation(t_game *game, int fd);

/********************
 * 		Parsing
 ********************/

void	ft_parsing(t_game *game, char **argv);
void	ft_get_link_image(t_game *game, int fd);
bool	ft_is_link(char *line);
void	ft_fill_link(t_game *game, char *line);
 
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
void	ft_free_map(t_game *game);

/********************
 * 		Error
 ********************/

void	ft_print_error_and_exit(char *error_message);
void	ft_print_image();
void	ft_print_game();

#endif