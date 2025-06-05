/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:39:57 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/04 10:49:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_player_on_door(t_game *game)
{
	t_position	check_pos;
	t_position	door_pos;
	t_door		*door;
	int			i;

	check_pos.x = game->player->pos.x + cos(game->player->angle) * (2
			* PLAYER_RADIUS);
	check_pos.y = game->player->pos.y + sin(game->player->angle) * (2
			* PLAYER_RADIUS);
	door_pos.x = (int)(check_pos.x / T_SIZE);
	door_pos.y = (int)(check_pos.y / T_SIZE);
	game->player->on_door = false;
	i = -1;
	while (++i < game->map->num_doors)
	{
		door = &game->map->doors[i];
		if (door->is_open && door->x == (int)door_pos.x
			&& door->y == (int)door_pos.y)
		{
			game->player->on_door = true;
			break ;
		}
	}
}

void	ft_handle_door(t_game *game)
{
	t_door		*door;
	t_position	door_c;
	t_position	delta;
	float		dist;
	int			i;

	ft_player_on_door(game);
	i = -1;
	while (++i < game->map->num_doors)
	{
		door = &game->map->doors[i];
		if (door->is_open)
		{
			door_c.x = door->x * T_SIZE + T_SIZE / 2;
			door_c.y = door->y * T_SIZE + T_SIZE / 2;
			delta.x = game->player->pos.x - door_c.x;
			delta.y = game->player->pos.y - door_c.y;
			dist = sqrtf(delta.x * delta.x + delta.y * delta.y);
			if (dist > PLAYER_RADIUS + T_SIZE / 2)
			{
				door->is_open = false;
				game->map->map[door->y][door->x] = 'D';
			}
		}
	}
}
