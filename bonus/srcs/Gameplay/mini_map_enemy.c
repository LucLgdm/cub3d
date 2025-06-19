/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:00:32 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/19 12:17:34 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_one_enemy(t_game *game, t_enemy *enemy)
{
	t_position	rel;
	double		dist;
	double		angle;
	double		dx;
	double		dy;

	rel.x = (enemy->pos.x - game->player->pos.x) * 0.15f;
	rel.y = (enemy->pos.y - game->player->pos.y) * 0.15f;
	dist = sqrtf(rel.x * rel.x + rel.y * rel.y);
	if (dist > MINIMAP_RADIUS)
		return ;
	angle = atan2f(rel.y, rel.x) - game->player->angle - PI / 2;
	dx = cosf(angle) * dist;
	dy = sinf(angle) * dist;
	ft_draw_enemy_on_minimap(game, dx, dy);
}

void	ft_draw_enemy_on_minimap(t_game *game, double dx, double dy)
{
	double	screen_x;
	double	screen_y;

	screen_x = game->mini_map->center_x + dx;
	screen_y = game->mini_map->center_y + dy;
	ft_put_octogone(screen_x, screen_y);
}

void	ft_draw_enemy_mini(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->num_enemy)
	{
		ft_draw_one_enemy(game, &game->map->enemy[i]);
		i++;
	}
}

void	ft_put_octogone(double x, double y)
{
	t_position	point[8];
	double		front;
	int			i;

	front = 4;
	i = -1;
	while (++i < 8)
	{
		point[i].x = x + front * cos(i * PI / 4);
		point[i].y = y - front * sin(i * PI / 4);
	}
	i = -1;
	while (++i < 8)
		ft_fill_triangle((t_position){x, y}, point[i], point[(i
				+ 1) % 8], 0x00FF00);
}
