/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:36:26 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/27 16:21:02 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_floor(int column_x, int wall_start, int wall_height,
		t_raycasting *ray)
{
	t_game		*game;
	t_position	floor;
	int			floor_height;
	int			color;

	game = ft_get_game();
	color = ft_create_color(255, (int)(game->image->floor.s_channel.r),
			(int)(game->image->floor.s_channel.g),
			(int)(game->image->floor.s_channel.b));
	floor.x = column_x;
	floor.y = wall_start + wall_height;
	floor_height = game->height_w - (wall_start + wall_height);
	ft_draw_rectangle(floor, floor_height, ray->width + 1, color);
}

void	ft_draw_ceiling(int column_x, int wall_start, t_raycasting *ray)
{
	t_game		*game;
	t_position	ceiling;
	int			color;

	game = ft_get_game();
	ceiling.x = column_x;
	ceiling.y = 0;
	color = ft_create_color(255, (int)(game->image->ceiling.s_channel.r),
			(int)(game->image->ceiling.s_channel.g),
			(int)(game->image->ceiling.s_channel.b));
	ft_draw_rectangle(ceiling, wall_start, ray->width + 1, color);
}

void	ft_draw_wall_column(t_game *game, t_tex *tex, t_wall_params wp,
		int tex_x)
{
	float	ty;
	int		screen_y;
	int		tex_y;
	char	*dst;
	int		y;

	y = -1;
	ty = wp.ty_off * wp.ty_step;
	while (++y < (int)wp.height)
	{
		screen_y = wp.start + y;
		if (screen_y < 0 || screen_y >= game->height_w)
			continue ;
		tex_y = (int)ty;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		dst = tex->addr + (tex_y * tex->line_length + tex_x
				* (tex->bits_per_pixel / 8));
		my_mlx_pixel_put(game->mlx, wp.column_x, screen_y,
			*(unsigned int *)dst);
		ty += wp.ty_step;
	}
}

void	ft_draw_ray(t_game *game, t_raycasting *ray)
{
	t_position	pos;
	t_position	ray_pos;

	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	ray_pos.x = ray->final.x;
	ray_pos.y = ray->final.y;
	ft_draw_line(game->mlx, pos, ray_pos, ray->color);
}
