/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/06 17:42:58 by lde-merc         ###   ########.fr       */
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

typedef struct s_mlx{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_mlx;

typedef struct s_position{
	int		x;
	int		y;
} t_position;

typedef struct s_player{
	t_position	pos;
	char		direction;
} t_player;

typedef struct s_game{
	t_mlx		*mlx;
	t_map		*map;
	t_image		*image;
	t_player	*player;
	int			height_w;
	int			width_w;
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
int		ft_check_content(char *line, int i);
bool	ft_is_good_char(char c);
int		ft_check_wall(char *line);
void	ft_fill_player(char c, int i, int j, t_game *game);


/********************
 * 		Mlx
 ********************/

	/*	GLOBAL	*/
int		ft_key_handle(int key, void *data);
int		ft_close_window(t_game *game);
void	ft_display(t_game *game);
int	create_color(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

	/*	HOOK	*/
void	ft_move_player(t_game *game, int key);

/********************
 * 		Memory
 ********************/

void	ft_malloc_game(t_game *game);
void	ft_malloc_mlx(t_game *game);
void	ft_malloc_image(t_game *game);
void	ft_malloc_map(t_game *game);

void	ft_free_game(t_game *game);
void	ft_free_player(t_player *player);
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