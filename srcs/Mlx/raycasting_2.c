/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:52 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/23 21:22:17 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_choose_ray(t_raycasting *ray, t_game *game, int flag)
{
	ray->dist_v = ft_distance(&game->player->pos, &ray->pos);
	if (ray->dist_h > ray->dist_v)
	{
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
		ray->dist_min = ray->dist_v;
		ray->hit_v = true;
	}
	else
	{
		ray->dist_min = ray->dist_h;
		ray->hit_v = false;
	}
	if (ray->hit_v){
		if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
			ray->color = ft_create_color(255, 255, 0, 0);
		else
			ray->color = ft_create_color(255, 0, 255, 0);
	}else{
		if (ray->angle < PI)
			ray->color = ft_create_color(255, 25, 25, 135);
		else
			ray->color = ft_create_color(255,  155, 32, 137);
	}
	
	if (flag == 1)
		ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y,
			ray->final.x, ray->final.y, ray->color);
}

void	ft_draw_3d(t_raycasting *ray, t_game *game, int r, int flag)
{
	float	ca;
	float	wall_height;
	float	wall_start;
	float	wall_offset;
	int		column_x;

	// On choisit la texture //

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
	
	ca = ray->angle - game->player->angle;
	if (ca > PI)
		ca -= 2 * PI;
	if (ca < -PI)
		ca += 2 * PI;
	ray->dist_min *= cos(ca);
	wall_height = (int)((game->height_w * tex->height) / ray->dist_min);
	if (wall_height > game->height_w)
		wall_height = game->height_w;
	wall_start = (game->height_w / 2) - (wall_height / 2);
	if (flag == 1)
		wall_offset = game->width_w / 2;
	else
		wall_offset = 0;
	column_x = r * ray->width + wall_offset;
		
		
	
	// Calcul de la coordonnée X sur la texture
	float wall_x;
	if (ray->hit_v)
		wall_x = ray->final.y / tex->width - floor(ray->final.y / tex->width);
	else
		wall_x = ray->final.x / tex->height - floor(ray->final.x / tex->height);
	int tex_x = (int)(wall_x * (float)tex->width);
	if (tex_x < 0) tex_x = 0;
	if (tex_x >= tex->width) tex_x = tex->width - 1;

	// Affichage de la colonne texturée
	for (int y = 0; y < wall_height; y++)
	{
		int screen_y = wall_start + y;
		if (screen_y < 0 || screen_y >= game->height_w)
			continue;
		int tex_y = (int)((float)y / wall_height * tex->height);

		char *dst = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8));
		unsigned int color = *(unsigned int*)dst;
		
		my_mlx_pixel_put(game->mlx, column_x, screen_y, color);
	}
		
	// ft_draw_rectangle(game->mlx, column_x, wall_start, wall_start + wall_height,
	// 	ray->width + 1, ray->color);
	ft_draw_rectangle(game->mlx, column_x, wall_start + wall_height,
		game->height_w, ray->width + 1, ft_create_color(255,
			(int)(game->image->floor.s_channel.r),
			(int)(game->image->floor.s_channel.g),
			(int)(game->image->floor.s_channel.b)));
	ft_draw_rectangle(game->mlx, column_x, 0, wall_start, ray->width + 1,
		ft_create_color(255, (int)(game->image->ceiling.s_channel.r),
			(int)(game->image->ceiling.s_channel.g),
			(int)(game->image->ceiling.s_channel.b)));
}

void	ft_update_angle(t_raycasting *ray)
{
	ray->angle += (60 * PI / 180) / ray->num_rays;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
}
