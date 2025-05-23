/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:52 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/23 16:06:33 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_choose_ray(t_raycasting *ray, t_game *game, int flag)
{
	ray->dist_v = ft_distance(&game->player->pos, &ray->pos);
	if (ray->dist_h > ray->dist_v)
	{
		ray->color = ft_create_color(255, 0.9 * 150, 0.9 * 150, 0.9 * 0);
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
		ray->dist_min = ray->dist_v;
		ray->hit_v = true;
	}
	else
	{
		ray->color = ft_create_color(255, 0.7 * 80, 0.7 * 130, 0.7 * 50);
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

	ca = game->player->angle - ray->angle;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	ray->dist_min *= cos(ca);
	wall_height = (game->height_w * TILE_SIZE) / ray->dist_min;
	if (wall_height > game->height_w)
		wall_height = game->height_w;
	wall_start = (game->height_w / 2) - (wall_height / 2);
	if (flag == 1)
		wall_offset = game->width_w / 2;
	else
		wall_offset = 0;
	column_x = r * ray->width + wall_offset;
		
		// On choisit la texture //

	// char *texture_data;

	// if (ray->hit_v)
	// {
	// 	if (ray->angle < PI)
	// 		texture_data = game->image->add_N;
	// 	else
	// 		texture_data = game->image->add_S;
	// }
	// else
	// {
	// 	if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	// 		texture_data = game->image->add_W;
	// 	else
	// 		texture_data = game->image->add_E;
	// }

	// 	// On calcule la position du pixel //

	// float wall_x;
	// float ray_dir_x = cos(ray->angle);
	// float ray_dir_y = sin(ray->angle);
	// int texture_width = game->image->img_width;

	// if (ray->hit_v)
	// 	wall_x = ray->pos.y / TILE_SIZE;
	// else
	// 	wall_x = ray->pos.x / TILE_SIZE;
	// wall_x -= floor(wall_x);
	// int tex_x = (int)(wall_x * texture_width);

	// if ((ray->hit_v && ray_dir_x < 0) || (!ray->hit_v && ray_dir_y > 0))
	// 	tex_x = texture_width - tex_x - 1;

	// int texture_height = game->image->img_height;
	// int bpp = game->mlx->bits_per_pixel;
	// int size_line = game->mlx->line_length;

	// for (int y = 0; y < wall_height; y++)
	// {
	// 	int screen_y = wall_start + y;
	// 	if (screen_y < 0 || screen_y >= game->height_w)
	// 		continue;

	// 	int tex_y = (int)((float)y / wall_height * texture_height);

	// 	// Sécurité bornes
	// 	if (tex_x < 0) tex_x = 0;
	// 	if (tex_x >= texture_width) tex_x = texture_width - 1;
	// 	if (tex_y < 0) tex_y = 0;
	// 	if (tex_y >= texture_height) tex_y = texture_height - 1;
	// 	if (!texture_data)
	// 		continue;

	// 	int color = *(int *)(texture_data + (tex_y * size_line + tex_x * (bpp / 8)));

	// 	my_mlx_pixel_put(game->mlx, column_x, screen_y, color);
	// }
		/////////////////////
		
	ft_draw_rectangle(game->mlx, column_x, wall_start, wall_start + wall_height,
		ray->width + 1, ray->color);
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
