/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:45:29 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/06 15:33:18 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_horizontal_raycasting(t_raycasting *ray, t_game *game)
{
	float	atan;

	atan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)game->player->pos.y >> ray->p) << ray->p) - 0.0001f;
		ray->pos.x = (game->player->pos.y - ray->pos.y) * atan
			+ game->player->pos.x;
		ray->next.y = -T_SIZE;
		ray->next.x = -ray->next.y * atan;
	}
	if (ray->angle < PI)
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
		ray->dof = 50;
	}
}

void	ft_vertical_raycasting(t_raycasting *ray, t_game *game)
{
	float	ntan;

	ntan = -tan(ray->angle);
	if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> ray->p) << ray->p) - 0.0001f;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * ntan
			+ game->player->pos.y;
		ray->next.x = -T_SIZE;
		ray->next.y = -ray->next.x * ntan;
	}
	else if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
	{
		ray->pos.x = (((int)game->player->pos.x >> ray->p) << ray->p) + T_SIZE;
		ray->pos.y = (game->player->pos.x - ray->pos.x) * ntan
			+ game->player->pos.y;
		ray->next.x = T_SIZE;
		ray->next.y = -ray->next.x * ntan;
	}
	else
	{
		ray->pos.x = game->player->pos.x;
		ray->pos.y = game->player->pos.y;
		ray->dof = 50;
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

	while (ray->dof < 50)
	{
		map_x = (int)(ray->pos.x) >> ray->p;
		map_y = (int)(ray->pos.y) >> ray->p;
		if (map_x < 0 || map_y < 0 || map_y >= game->map->height
			|| map_x >= game->map->line_lengths[map_y])
			break ;
		if (ft_check(map_x, map_y))
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
