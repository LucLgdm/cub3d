/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:16 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 15:20:57 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static int	has_line_of_sight(t_game *game, float ex, float ey, float px, float py)
{
    float dx = px - ex;
    float dy = py - ey;
    float dist = sqrt(dx * dx + dy * dy);
    int steps = (int)dist;
    float step_x = dx / steps;
    float step_y = dy / steps;
    float x = ex, y = ey;
	
    for (int i = 0; i < steps; i++)
    {
        int mx = (int)x / T_SIZE;
        int my = (int)y / T_SIZE;
        if (game->map->map[my][mx] != '0')
            return (0);
        x += step_x;
        y += step_y;
    }
    return (1);
}

void	ft_move_enemy(t_game *game, t_enemy *enemy)
{
    float px = game->player->pos.x, py = game->player->pos.y;
    float ex = enemy->pos.x, ey = enemy->pos.y;
    float dx = px - ex, dy = py - ey;
    float dist = sqrt(dx * dx + dy * dy);

    if (dist > ENEMY_VIEW_RADIUS)
        return;
    if (!has_line_of_sight(game, ex, ey, px, py))
        return;

    float speed = 1.0f;

	if (dist != 0)
    {
        dx /= dist;
        dy /= dist;
    }
	
	float next_x = ex + dx * speed;
	int mx = (int)next_x / T_SIZE;
	int my = (int)ey / T_SIZE;
	if (game->map->map[my][mx] == '0')
		enemy->pos.x = next_x;
	float next_y = ey + dy * speed;
	mx = (int)ex / T_SIZE;
	my = (int)next_y / T_SIZE;
	if (game->map->map[my][mx] == '0')
		enemy->pos.y = next_y;
}
