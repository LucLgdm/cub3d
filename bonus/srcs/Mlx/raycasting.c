/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:45:29 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/17 11:25:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game)
{
	double	atan;

	atan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> ray->p) << ray->p) - 0.0001f;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = -T_SIZE;
		ray->next.x = -ray->next.y * atan;
	}
	else if (ray->angle < PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> ray->p) << ray->p) + T_SIZE;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = T_SIZE;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 1024;
	}
}

void	ft_vertical_raycasting(t_raycasting *ray, t_game *game)
{
	if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	{
		ray->pos.x = floor(game->player->pos.x / T_SIZE) * T_SIZE - EPSILON;
		ray->pos.y = game->player->pos.y + (game->player->pos.x - ray->pos.x)
			* -tan(ray->angle);
		ray->next.x = -T_SIZE;
		ray->next.y = -ray->next.x * -tan(ray->angle);
	}
	else if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
	{
		ray->pos.x = floor(game->player->pos.x / T_SIZE) * T_SIZE + T_SIZE;
		ray->pos.y = game->player->pos.y + (game->player->pos.x - ray->pos.x)
			* -tan(ray->angle);
		ray->next.x = T_SIZE;
		ray->next.y = -ray->next.x * -tan(ray->angle);
	}
	else
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 1024;
	}
}

static bool	ft_check(int map_x, int map_y)
{
	t_game	*game;

	game = ft_get_game();
	return (game->map->map[map_y][map_x] == '1'
		|| game->map->map[map_y][map_x] == 'D');
}

void	ft_dda_loop(t_raycasting *ray, t_game *game, int flag)
{
	int	map_x;
	int	map_y;

	while (ray->dof < 1024)
	{
		map_x = (int)(ray->pos.x / T_SIZE);
		map_y = (int)(ray->pos.y / T_SIZE);
		if (map_x < 0 || map_y < 0 || map_y >= game->map->height
			|| map_x >= game->map->line_lengths[map_y])
			break ;
		if (ft_check(map_x, map_y))
			ray->dof = 1024;
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
