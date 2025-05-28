/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:52 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 14:44:02 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_tex	*ft_choose_tex(t_game *game, t_raycasting *ray)
{
	t_tex	*tex;

	if (ray->hit_v)
	{
		if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
			tex = &game->image->north;
		else
			tex = &game->image->south;
	}
	else
	{
		if (ray->angle < PI)
			tex = &game->image->west;
		else
			tex = &game->image->east;
	}
	return (tex);
}

t_wall	ft_calc_wall_params(t_tex *tex, t_raycasting *ray, int r,
		int flag)
{
	t_game			*game;
	t_wall	wp;

	game = ft_get_game();
	wp.height = (game->height_w * tex->height) / ray->dist_min;
	wp.ty_step = tex->height / wp.height;
	wp.ty_off = 0.0f;
	if (wp.height > game->height_w)
	{
		wp.ty_off = (wp.height - game->height_w) / 2.0f;
		wp.height = game->height_w;
	}
	wp.start = (game->height_w / 2) - (wp.height / 2);
	if (flag == 1)
		wp.offset = game->width_w / 2;
	else
		wp.offset = 0;
	wp.column_x = r * ray->width + wp.offset;
	return (wp);
}

int	ft_calc_tex_x(t_tex *tex, t_raycasting *ray)
{
	float	wall_x;
	int		tex_x;

	if (ray->hit_v)
		wall_x = ray->final.y / tex->width - floor(ray->final.y / tex->width);
	else
		wall_x = ray->final.x / tex->height - floor(ray->final.x / tex->height);
	tex_x = (int)(wall_x * (float)tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

void	ft_draw_3d(t_raycasting *ray, t_game *game, int r, int flag)
{
	t_tex			*tex;
	int				tex_x;
	t_wall	wp;

	tex = ft_choose_tex(game, ray);
	ft_fix_fisheyes(game, ray);
	wp = ft_calc_wall_params(tex, ray, r, flag);
	tex_x = ft_calc_tex_x(tex, ray);
	ft_draw_wall_column(game, tex, wp, tex_x);
	ft_draw_floor(wp.column_x, wp.start, wp.height, ray);
	ft_draw_ceiling(wp.column_x, wp.start, ray);
}

void	ft_update_angle(t_raycasting *ray)
{
	ray->angle += (60 * PI / 180) / ray->num_rays;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
}
