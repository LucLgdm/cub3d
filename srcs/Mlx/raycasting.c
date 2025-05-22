/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:45:29 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/22 15:25:25 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_casting(t_raycasting *ray, t_game *game, int flag)
{
	int	r;

	ft_init_ray(ray, game, flag);
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
		ft_choose_ray(ray, game, flag);
		ft_draw_3d(ray, game, r, flag);
		ft_update_angle(ray);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
}

void	ft_init_ray(t_raycasting *ray, t_game *game, int flag)
{
	ray->num_rays = game->width_w;
	ray->color = ft_create_color(255, 150, 150, 0);
	ray->dof = 0;
	ray->angle = game->player->angle - 30 * PI / 180;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
	if (flag == 1)
		ray->width = ((float)game->width_w / 2) / ray->num_rays;
	else
		ray->width = (float)game->width_w / ray->num_rays;
}

void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game)
{
	float	atan;

	atan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> (int)(log2((double)TILE_SIZE))) << (int)(log2((double)TILE_SIZE))) - 0.0001;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = -TILE_SIZE;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle < PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> (int)(log2((double)TILE_SIZE))) << (int)(log2((double)TILE_SIZE))) + TILE_SIZE;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = TILE_SIZE;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 50;
	}
}

void	ft_vertical_raycasting(t_raycasting *ray, t_game *game)
{
	float	ntan;

	ntan = -tan(ray->angle);
	if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> (int)(log2((double)TILE_SIZE))) << (int)(log2((double)TILE_SIZE))) - 0.0001;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * ntan
			+ game->player->pos.y;
		ray->next.x = -TILE_SIZE;
		ray->next.y = -ray->next.x * ntan;
	}
	else if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> (int)(log2((double)TILE_SIZE))) << (int)(log2((double)TILE_SIZE))) + TILE_SIZE;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * ntan
			+ game->player->pos.y;
		ray->next.x = TILE_SIZE;
		ray->next.y = -ray->next.x * ntan;
	}
	else
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 50;
	}
}

void	ft_calcul_loop(t_raycasting *ray, t_game *game, int flag)
{
	int	map_x;
	int	map_y;

	while (ray->dof < 50)
	{
		map_x = (int)ray->pos.x / TILE_SIZE;
		map_y = (int)ray->pos.y / TILE_SIZE;
		if (map_x < 0 || map_x >= game->map->width || map_y < 0
			|| map_y >= game->map->height)
			break ;
		if (game->map->map[map_y][map_x] == '1')
			ray->dof = 50;
		else
		{
			ray->pos.x += ray->next.x;
			ray->pos.y += ray->next.y;
			ray->dof++;
		}
	}
	if (flag == 1)
	{
		ray->dist_h = ft_distance(&game->player->pos, &ray->pos);
		ray->final.x = ray->pos.x;
		ray->final.y = ray->pos.y;
	}
}
