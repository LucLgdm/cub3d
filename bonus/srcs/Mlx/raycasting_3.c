/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:38:14 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 14:25:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fix_fisheyes(t_game *game, t_raycasting *ray)
{
	double	ca;

	ca = game->player->angle - ray->angle;
	if (ca > PI)
		ca -= 2 * PI;
	if (ca < -PI)
		ca += 2 * PI;
	ray->dist_min *= (double)cos(ca);
}

void	ft_set_ray_hit(t_raycasting *ray, t_game *game)
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
}

void	ft_set_ray_color(t_raycasting *ray)
{
	if (ray->hit_v)
	{
		if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
			ray->color = ft_create_color(255, 255, 0, 0);
		else
			ray->color = ft_create_color(255, 0, 255, 0);
	}
	else
	{
		if (ray->angle < PI)
			ray->color = ft_create_color(255, 25, 25, 135);
		else
			ray->color = ft_create_color(255, 155, 32, 137);
	}
}

void	ft_choose_ray(t_raycasting *ray, t_game *game)
{
	ft_set_ray_hit(ray, game);
	ft_set_ray_color(ray);
}
