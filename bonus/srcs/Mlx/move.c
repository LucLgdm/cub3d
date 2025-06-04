/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:50:03 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/04 09:53:20 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_handle_w(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->pos.x + game->player->dx * game->player->velocity;
	new_y = game->player->pos.y + game->player->dy * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;

	t_player	*player = game->player;
	float		check_x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	float		check_y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	int			door_x = (int)(check_x / T_SIZE);
	int			door_y = (int)(check_y / T_SIZE);
	
	game->player->on_door = false;
	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open && door->x == door_x && door->y == door_y)
		{
			game->player->on_door = true;
			break;
		}
	}

	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open)
		{
			float door_cx = door->x * T_SIZE + T_SIZE / 2;
			float door_cy = door->y * T_SIZE + T_SIZE / 2;
			float dx = game->player->pos.x - door_cx;
			float dy = game->player->pos.y - door_cy;
			float dist = sqrtf(dx * dx + dy * dy);

			// Ferme la porte seulement si le joueur est vraiment loin de la porte
			if (dist > PLAYER_RADIUS + T_SIZE / 2)
			{
				door->is_open = false;
				game->map->map[door->y][door->x] = 'D';
			}
		}
	}
	
	int			map_x = (int)(game->player->pos.x / T_SIZE);
	int			map_y = (int)(game->player->pos.y / T_SIZE);
	
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

	t_player	*player = game->player;
	float		check_x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	float		check_y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	int			door_x = (int)(check_x / T_SIZE);
	int			door_y = (int)(check_y / T_SIZE);
	
	game->player->on_door = false;
	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open && door->x == door_x && door->y == door_y)
		{
			game->player->on_door = true;
			break;
		}
	}

	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open)
		{
			float door_cx = door->x * T_SIZE + T_SIZE / 2;
			float door_cy = door->y * T_SIZE + T_SIZE / 2;
			float dx = game->player->pos.x - door_cx;
			float dy = game->player->pos.y - door_cy;
			float dist = sqrtf(dx * dx + dy * dy);

			// Ferme la porte seulement si le joueur est vraiment loin de la porte
			if (dist > PLAYER_RADIUS + T_SIZE / 2)
			{
				door->is_open = false;
				game->map->map[door->y][door->x] = 'D';
			}
		}
	}

	int			map_x = (int)(game->player->pos.x / T_SIZE);
	int			map_y = (int)(game->player->pos.y / T_SIZE);
	
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
	
	t_player	*player = game->player;
	float		check_x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	float		check_y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	int			door_x = (int)(check_x / T_SIZE);
	int			door_y = (int)(check_y / T_SIZE);
	
	game->player->on_door = false;
	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open && door->x == door_x && door->y == door_y)
		{
			game->player->on_door = true;
			break;
		}
	}

	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open)
		{
			float door_cx = door->x * T_SIZE + T_SIZE / 2;
			float door_cy = door->y * T_SIZE + T_SIZE / 2;
			float dx = game->player->pos.x - door_cx;
			float dy = game->player->pos.y - door_cy;
			float dist = sqrtf(dx * dx + dy * dy);

			// Ferme la porte seulement si le joueur est vraiment loin de la porte
			if (dist > PLAYER_RADIUS + T_SIZE / 2)
			{
				door->is_open = false;
				game->map->map[door->y][door->x] = 'D';
			}
		}
	}
	
	int			map_x = (int)(game->player->pos.x / T_SIZE);
	int			map_y = (int)(game->player->pos.y / T_SIZE);
	
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

	t_player	*player = game->player;
	float		check_x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	float		check_y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	int			door_x = (int)(check_x / T_SIZE);
	int			door_y = (int)(check_y / T_SIZE);
	
	game->player->on_door = false;
	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open && door->x == door_x && door->y == door_y)
		{
			game->player->on_door = true;
			break;
		}
	}
	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->is_open)
		{
			float door_cx = door->x * T_SIZE + T_SIZE / 2;
			float door_cy = door->y * T_SIZE + T_SIZE / 2;
			float dx = game->player->pos.x - door_cx;
			float dy = game->player->pos.y - door_cy;
			float dist = sqrtf(dx * dx + dy * dy);

			// Ferme la porte seulement si le joueur est vraiment loin de la porte
			if (dist > PLAYER_RADIUS + T_SIZE / 2)
			{
				door->is_open = false;
				game->map->map[door->y][door->x] = 'D';
			}
		}
	}

	int			map_x = (int)(game->player->pos.x / T_SIZE);
	int			map_y = (int)(game->player->pos.y / T_SIZE);
	
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

void	ft_handle_e(t_game *game)
{
	t_player	*player = game->player;
	float check_x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	float check_y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	int			door_x = (int)(check_x / T_SIZE);
	int			door_y = (int)(check_y / T_SIZE);

	for (int i = 0; i < game->map->num_doors; i++)
	{
		t_door *door = &game->map->doors[i];
		if (door->x == door_x && door->y == door_y)
		{
			if (!door->is_open)
			{
				door->is_open = true;
				game->map->map[door_y][door_x] = '0';
			}
			break;
		}
	}
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
