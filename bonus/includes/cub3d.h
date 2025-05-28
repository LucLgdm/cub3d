/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/27 16:21:16 by lde-merc         ###   ########.fr       */
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
# include "math.h"
# include "image.h"
# include "map.h"
# include "raycasting.h"

# define PI 3.1415926535
# define T_SIZE 32.0

typedef struct s_position{
	float	x;
	float	y;
} t_position;

typedef struct s_mlx{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_mlx;

typedef struct s_wall_params
{
	float	height;
	float	start;
	float	offset;
	int		column_x;
	float	ty_step;
	float	ty_off;
}	t_wall_params;

typedef struct s_raycasting
{
	int			num_rays;
	float		angle;
	float		dist;
	float 		width;
	t_position	pos;
	t_position	next;
	t_position	final;
	int			map_x;
	int			map_y;
	int			dof;
	int			color;
	float		dist_v;
	float		dist_h;
	float		dist_min;
	bool		hit_v;
	int			p;
}	t_raycasting;

typedef struct s_key{
	char 	*key;
	bool	pressed;
} t_key;

typedef struct s_buttons{
	t_key	a;
	t_key	d;
	t_key	w;
	t_key	s;
	t_key	left;
	t_key	right;
} t_buttons;

typedef struct s_player{
	t_position	pos;
	char		direction;
	float		angle;
	float		dx;
	float		dy;
	float		velocity;
	float		rotation_speed;
} t_player;

typedef struct s_game{
	t_mlx			*mlx;
	t_map			*map;
	t_image			*image;
	t_player		*player;
	t_raycasting	raycasting;
	t_buttons		buttons;
	int				height_w;
	int				width_w;
	bool			correction;
} t_game;

/********************
 * 		Guetter
 ********************/

 t_game	*ft_get_game(void);

/********************
 * 		Initialisation
 ********************/

void	ft_game_initialisation(int argc, char **argv);
void	ft_check_player(t_game *game);

/********************
 * 		Main
 ********************/

void	ft_game(int flag);

/********************
 * 		Parsing
 ********************/

void	ft_parsing(t_game *game, char **argv);
char	*ft_get_info(int fd);

	/*   LINK    */
bool	ft_is_link(char *line);
void	ft_fill_link(char *line, int fd);

	/*   COLOR   */
void	ft_fill_game_color(char *line, t_color *color);
char	**ft_fill_color_2(char *line, int fd);
void	ft_fill_color(char *line, int fd);
bool	ft_is_color(char *line);


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

	/*	GLOBAL		*/
int		ft_key_handle(int key, void *data);
int		ft_close_window(t_game *game);
void	ft_display(t_game *game, int flag);

	/*	IMAGE		*/
void	ft_image_generator(t_game *game);
void	ft_image_north(void *mlx, t_tex *north);
void	ft_image_south(void *mlx, t_tex *south);
void	ft_image_east(void *mlx, t_tex *east);
void	ft_image_west(void *mlx, t_tex *west);

	/*	DRAWING		*/
int		ft_create_color(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	ft_draw_square(t_game *game, int x, int y, int color);
void	ft_draw_line(t_mlx *mlx, t_position x1, t_position x2, int color);
void	ft_draw_rectangle(t_position start, int height, int width, int color);
void	ft_draw_wall_column(t_game *game, t_tex *tex, t_wall_params wp, int tex_x);
void	ft_draw_ceiling(int column_x, int wall_start, t_raycasting *ray);
void	ft_draw_floor(int column_x, int wall_start, int wall_height, t_raycasting *ray);
void	ft_draw_ray(t_game *game, t_raycasting *ray);


	/*	CORRECTION	*/
void	ft_display_all(t_game *game);
void	ft_display_background(t_game *game);
void	ft_display_map(t_game *game);
void	ft_display_player(t_game *game);

	/*	RAYCASTING	*/
void	ft_ray_casting(t_raycasting *ray, t_game *game, int flag);
void	ft_init_ray(t_raycasting *ray, t_game *game, int flag);
void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game);
void	ft_vertical_raycasting(t_raycasting *ray, t_game *game);
void	ft_dda_loop(t_raycasting *ray, t_game *game, int flag);
void	ft_choose_ray(t_raycasting *ray, t_game *game, int flag);
void	ft_set_ray_hit(t_raycasting *ray, t_game *game);
void	ft_set_ray_color(t_raycasting *ray);
void	ft_draw_3d(t_raycasting *ray, t_game * game, int r, int flag);
t_tex	*ft_choose_tex(t_game *game, t_raycasting *ray);
void	ft_fix_fisheyes(t_game *game, t_raycasting *ray);
t_wall_params	ft_calc_wall_params(t_tex *tex, t_raycasting *ray, int r, int flag);
int		ft_calc_tex_x(t_tex *tex, t_raycasting *ray);
void    ft_update_angle(t_raycasting *ray);

	/*	HOOK		*/
int		ft_can_move_to(t_game *game, float x, float y);
int		ft_is_wall_at(t_game *game, float x, float y);
void	ft_move_player(t_game *game, int key);
void	ft_handle_key(t_game *game);
void	ft_handle_w(t_game *game);
void	ft_handle_s(t_game *game);
void	ft_handle_a(t_game *game);
void	ft_handle_d(t_game *game);
void	ft_handle_left(t_game *game);
void	ft_handle_right(t_game *game);
int		ft_key_release(int key, void *data);
int		ft_game_loop(void *data);

/********************
 * 		Memory
 ********************/

void	ft_malloc_game(t_game *game);
void	ft_malloc_mlx(t_game *game);
void	ft_malloc_image(t_game *game);
void	ft_malloc_map(t_game *game);

void	ft_free_game(t_game *game);
void	ft_free_mlx(t_mlx *mlx);
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

/********************
 * 		Usefull
 ********************/

float	ft_distance(t_position *pos1, t_position *pos2);

#endif