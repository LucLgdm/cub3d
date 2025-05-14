/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:45:29 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/14 14:17:22 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_casting(t_raycasting *ray, t_game *game)
{
	int	r;

	ft_init_ray(ray, game);
	ray->num_rays = 60;
	r = -1;
	while (++r < ray->num_rays)
	{
		ray->dof = 0;
		ft_horizontal_raycasting(ray, game);
		ft_calcul_loop(ray, game, 1);
		ray->dof = 0;
		ft_vertical_raycasting(ray, game);
		ft_calcul_loop(ray, game, 2);
		if (ray->pos.y > game->height_w)
			ray->pos.y = game->height_w;
		if (ray->pos.y < 0)
			ray->pos.y = 0;
		ft_choose_ray(ray, game);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 10,
		10);
}

void	ft_init_ray(t_raycasting *ray, t_game *game)
{
	ray->color =ft_create_color(255, 0, 255, 0);
	ray->dof = 0;
	ray->angle = game->player->angle - 30 * PI / 180;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
}

void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game)
{
	float	atan;

	atan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> 6) << 6) - 0.0001;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = -64;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle < PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> 6) << 6) + 64;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = 64;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 8;
	}
}

void	ft_vertical_raycasting(t_raycasting *ray, t_game *game)
{
	float	atan;

	atan = -tan(ray->angle);
	if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> 6) << 6) - 0.0001;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * atan
			+ game->player->pos.y;
		ray->next.x = -64;
		ray->next.y = -ray->next.x * atan;
	}
	else if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> 6) << 6) + 64;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * atan
			+ game->player->pos.y;
		ray->next.x = 64;
		ray->next.y = -ray->next.x * atan;
	}
	else
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 8;
	}
}


void	ft_calcul_loop(t_raycasting *ray, t_game *game, int flag)
{
	int	map_x;
	int	map_y;

	while (ray->dof < 8)
	{
		map_x = (int)ray->pos.x >> 6;
		map_y = (int)ray->pos.y >> 6;
		if (map_x < 0 || map_x >= game->map->width || map_y < 0
			|| map_y >= game->map->height)
			break ;
		if (game->map->map[map_y][map_x] == '1')
			ray->dof = 8;
		else
		{
			ray->pos.x += ray->next.x;
			ray->pos.y += ray->next.y;
			ray->dof++;
		}
	}
	if (flag == 1)
	{
		ray->distH = ft_distance(&game->player->pos, &ray->pos);
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
	}
}

void	ft_choose_ray(t_raycasting *ray, t_game *game)
{
	// int	distmin;
	float	angle_increment;
	
	ray->distV = ft_distance(&game->player->pos, &ray->pos);
	if (ray->distH > ray->distV)
	{
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
	}
	ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y,
			ray->final.x, ray->final.y, ray->color);
	angle_increment = (60 * PI / 180) / ray->num_rays;
	ray->angle += angle_increment;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
}
