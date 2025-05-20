/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:52:52 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/20 10:00:51 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_choose_ray(t_raycasting *ray, t_game *game, int flag)
{
	ray->dist_v = ft_distance(&game->player->pos, &ray->pos);
	if (ray->dist_h > ray->dist_v)
	{
        ray->color = ft_create_color(255, 0.9 * 20, 0.9 * 30, 0.9 * 150);
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
		ray->dist_min = ray->dist_v;
	}
	else
    {
        ray->color = ft_create_color(255, 0.7 * 20, 0.7 * 30, 0.7 * 150);
    	ray->dist_min = ray->dist_h;
    }
    if (flag == 1)
	    ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y,
			ray->final.x, ray->final.y, ray->color);
	
}

void	ft_draw_3d(t_raycasting *ray, t_game *game, int r, int flag)
{
    float ca;
    float wall_height;
    float wall_start;
    float wall_offset;
    int   column_x;

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
    ft_draw_rectangle(game->mlx, column_x, wall_start,
        wall_start + wall_height, ray->width + 1, ray->color);
}

void    ft_update_angle(t_raycasting *ray)
{
    ray->angle += (60 * PI / 180) / ray->num_rays;
    if (ray->angle < 0)
        ray->angle += 2 * PI;
    if (ray->angle > 2 * PI)
        ray->angle -= 2 * PI;
}
