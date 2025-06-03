/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:50:03 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/03 14:53:22 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_handle_w(t_game *game)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	new_x = game->player->pos.x + game->player->dx * game->player->velocity;
	new_y = game->player->pos.y + game->player->dy * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;

	map_x = (int)(game->player->pos.x / T_SIZE);
    map_y = (int)(game->player->pos.y / T_SIZE);
	
	if (game->map->map[map_y][map_x] == 'T')
	{
		if (game->player->can_teleport)
		{
			ft_teleport_player(game);
			game->player->can_teleport = false;
		}
	}
	else
		game->player->can_teleport = true;
}

void	ft_handle_s(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->pos.x - game->player->dx * game->player->velocity;
	new_y = game->player->pos.y - game->player->dy * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	if (game->map->map[(int)(game->player->pos.y / T_SIZE)]
		[(int)(game->player->pos.x / T_SIZE)] == 'T')
	{
		if (game->player->can_teleport)
		{
			ft_teleport_player(game);
			game->player->can_teleport = false;
		}
	}
	else
		game->player->can_teleport = true;
}

void	ft_handle_a(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->pos.x + game->player->dy * game->player->velocity;
	new_y = game->player->pos.y - game->player->dx * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	if (game->map->map[(int)(game->player->pos.y / T_SIZE)]
		[(int)(game->player->pos.x / T_SIZE)] == 'T')
	{
		if (game->player->can_teleport)
		{
			ft_teleport_player(game);
			game->player->can_teleport = false;
		}
	}
	else
		game->player->can_teleport = true;
}

void	ft_handle_d(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->pos.x - game->player->dy * game->player->velocity;
	new_y = game->player->pos.y + game->player->dx * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	if (game->map->map[(int)(game->player->pos.y / T_SIZE)]
		[(int)(game->player->pos.x / T_SIZE)] == 'T')
	{
		if (game->player->can_teleport)
		{
			ft_teleport_player(game);
			game->player->can_teleport = false;
		}
	}
	else
		game->player->can_teleport = true;
}

void	ft_handle_e(t_game *game)
{
	t_position	check;
	t_player	*player;
	t_position	door;
	
	player = game->player;
	check.x = game->player->pos.x + cos(player->angle) * 5 * PLAYER_RADIUS;
	check.y = game->player->pos.y + sin(player->angle) * 5 * PLAYER_RADIUS;
	door.x = check.x / T_SIZE;
	door.y = check.y / T_SIZE;
	if (game->map->map[(int)door.y][(int)door.x] == 'D')
		game->map->map[(int)door.y][(int)door.x] = '0';
}

void	ft_teleport_player(t_game *game)
{
	t_position	*teleporters = game->map->teleporters;
    int			num_teleporters = game->map->num_teleporters;
    int			cur_x = (int)(game->player->pos.x / T_SIZE);
    int			cur_y = (int)(game->player->pos.y / T_SIZE);
    int			i, next;

    for (i = 0; i < num_teleporters; i++)
    {
        if (teleporters[i].x == cur_x && teleporters[i].y == cur_y)
        {
            next = (i + 1) % num_teleporters;
            game->player->pos.x = teleporters[next].x * T_SIZE + T_SIZE / 2;
            game->player->pos.y = teleporters[next].y * T_SIZE + T_SIZE / 2;
            return;
        }
    }
}
