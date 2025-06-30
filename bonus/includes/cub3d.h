/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/30 16:09:27 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "image.h"
# include "map.h"
# include "math.h"
# include "position.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define PI 3.1415926535
# define T_SIZE 32.0
# define PLAYER_RADIUS 10.0f
# define ENEMY_VIEW_RADIUS 600.0f
# define EPSILON 0.0001

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx;

typedef struct s_raycasting
{
	int				num_rays;
	double			angle;
	double			width;
	t_position		pos;
	t_position		next;
	t_position		final;
	int				map_x;
	int				map_y;
	int				dof;
	int				color;
	double			dist_v;
	double			dist_h;
	double			dist_min;
	bool			hit_v;
	int				p;
}	t_raycasting;

typedef struct s_key
{
	char			*key;
	bool			pressed;
}	t_key;

typedef struct s_buttons
{
	t_key			a;
	t_key			d;
	t_key			w;
	t_key			s;
	t_key			e;
	t_key			left;
	t_key			right;
	t_key			shift;
	t_key			ctrl;
}	t_buttons;

typedef struct s_game
{
	t_mlx			*mlx;
	t_map			*map;
	t_image			*image;
	t_image			*image_resized;
	t_player		*player;
	t_raycasting	*raycasting;
	t_buttons		*buttons;
	t_mini_map		*mini_map;
	int				*zbuffer;
	int				mouse_prev_x;
	int				height_w;
	int				width_w;
	bool			need_redraw;
}	t_game;

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

void	ft_game(void);
void	ft_loop_mlx(t_game *game);

/********************
 * 		Parsing
 ********************/

void	ft_parsing(t_game *game, char **argv);
char	*ft_get_info(int fd);

/*	LINK		*/
bool	ft_is_link(char *line);
void	ft_fill_link(char *line, int fd);

/*	MAP			*/
void	ft_get_map(t_game *game, int fd, char *line);
void	ft_new_line(int fd, char *line, t_game *game);
void	ft_check_map(t_game *game);
int		ft_check_border(t_map *map, bool fill_struct);
int		ft_check_content(char *line, int i, int size);
int		ft_check_wall(char *line, int size);
void	ft_fill_player(char c, int i, int j, t_game *game);
bool	ft_is_good_char(char c);
/*	EXTRA		*/
void	ft_fill_teleporter(int i, int j, t_game *game);
void	ft_fill_door(int i, int j, t_game *game);
void	ft_fill_enemy(int i, int j, t_game *game);

/********************
 * 		Mlx
 ********************/

/*	GLOBAL		*/
int		ft_key_pressed(int key, void *data);
int		ft_close_window(t_game *game);
void	ft_display(t_game *game);

/*	IMAGE		*/
void	ft_image_generator(t_game *game);
void	ft_image_north(void *mlx, t_tex *north);
void	ft_image_south(void *mlx, t_tex *south);
void	ft_image_east(void *mlx, t_tex *east);
void	ft_image_west(void *mlx, t_tex *west);
void	ft_image_doors(void *mlx, t_tex *doors);
void	ft_image_vilain(void *mlx, t_tex *vilain);
void	ft_image_vilain_2(void *mlx, t_tex *vilain);
void	resize_tex(t_tex *src, t_tex *dst);
void	ft_resize_all_images(t_image *source, t_image *dest);

/*	DRAWING		*/
int		ft_create_color(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	ft_draw_square(t_game *game, int x, int y, int color);
void	ft_draw_line(t_mlx *mlx, t_position x1, t_position x2,
			int color);
void	ft_draw_rectangle(t_position start, int height, int width,
			int color);
void	ft_draw_wall_column(t_game *game, t_tex *tex, t_wall *wp,
			int tex_x);
void	ft_draw_enemy(t_game *game, t_enemy enemy);
void	ft_render_enemy_sprite(t_game *g, double dist, double angle,
			double fov);
void	ft_draw_enemy_texture(t_game *g, t_position *pos, int size,
			double dist);

/*	CORRECTION	*/
void	ft_display_all(t_game *game);
void	ft_display_background(t_game *game);
void	ft_display_map(t_game *game);
void	ft_display_player(t_game *game);

/*	RAYCASTING	*/
void	ft_ray_casting(t_raycasting *ray, t_game *game);
void	ft_init_ray(t_raycasting *ray, t_game *game);
void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game);
void	ft_vertical_raycasting(t_raycasting *ray, t_game *game);
void	ft_dda_loop(t_raycasting *ray, t_game *game, int flag);
void	ft_choose_ray(t_raycasting *ray, t_game *game);
void	ft_set_ray_hit(t_raycasting *ray, t_game *game);
void	ft_set_ray_color(t_raycasting *ray);
void	ft_draw_3d(t_raycasting *ray, t_game *game, int r);
t_tex	*ft_choose_tex(t_game *game, t_raycasting *ray);
void	ft_fix_fisheyes(t_game *game, t_raycasting *ray);
t_wall	*ft_calc_wall_params(t_tex *tex, t_raycasting *ray, int r);
int		ft_calc_tex_x(t_tex *tex, t_raycasting *ray);
void	ft_update_angle(t_raycasting *ray);

/*	GAMEPLAY	*/
int		ft_game_loop(void *data);
// USEFULL
int		ft_can_move_to(t_game *game, double x, double y);
int		ft_is_wall_at(t_game *game, double x, double y);
// HOOK
void	ft_handle_key(t_game *game);
int		ft_key_release(int key, void *data);
void	ft_handle_w(t_game *game);
void	ft_handle_s(t_game *game);
void	ft_handle_a(t_game *game);
void	ft_handle_d(t_game *game);
void	ft_handle_e(t_game *game, t_player *player);
void	ft_handle_left(t_game *game);
void	ft_handle_right(t_game *game);
void	ft_handle_shift(t_game *game);
int		ft_mouse_handle(int x, int y, void *data);
// EVENT
void	ft_handle_teleport(t_game *game);
void	ft_teleport_player(t_game *game);
void	ft_handle_door(t_game *game);
void	ft_move_enemy(t_game *game, t_enemy *enemy);
void	ft_move_enemy_step(t_game *game, t_enemy *enemy,
			t_position delta, double dist);
void	ft_move_enemy_y(t_game *game, t_enemy *enemy,
			t_position delta, double speed);
/*	MINI MAP	*/
void	ft_draw_minimap(t_game *game);
void	ft_draw_sprite(t_game *game);
void	ft_draw_player_mini(t_game *game);
void	ft_draw_enemy_mini(t_game *game);
void	ft_draw_one_enemy(t_game *game, t_enemy *enemy);
void	ft_draw_enemy_on_minimap(t_game *game, double dx, double dy);
// GEOMETRY
void	ft_fill_triangle(t_position a, t_position b, t_position c, int color);
void	ft_put_octogone(double x, double y);
/********************
 * 		Memory
 ********************/

void	ft_malloc_game(t_game *game);
void	ft_malloc_mlx(t_game *game);
void	ft_malloc_image(t_game *game);
void	ft_malloc_map(t_game *game);
void	ft_free_game(t_game *game);
void	ft_free_image(t_game *game);
void	ft_destroy_image(t_game *game);
void	ft_destroy_resized_image(t_game *game);
void	ft_free_map(t_map *map);

/********************
 * 		Error
 ********************/

void	ft_print_error_and_exit(char *error_message);
void	ft_exit_parsing(int fd, char *line, char *error_message);
void	ft_print_image(void);
void	ft_print_map(void);
void	ft_print_game(void);
void	ft_print_teleporter(void);
void	ft_print_doors(void);

/********************
 * 		Usefull
 ********************/

double	ft_distance(t_position *pos1, t_position *pos2);

#endif