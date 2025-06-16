/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 12:31:46 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouse_handle(int x, int y, void *data)
{
	t_game	*game;
	int		delta_x;

	game = (t_game *)data;
	(void)y;
	delta_x = x - game->mouse_prev_x;
	if (delta_x != 0)
	{
		game->player->angle += delta_x * game->player->rotation_speed;
		game->player->dx = 5 * cos(game->player->angle);
		game->player->dy = 5 * sin(game->player->angle);
	}
	if (abs(x - game->width_w / 2) > 20)
	{
		mlx_mouse_move(game->mlx->mlx, game->mlx->win, game->width_w / 2,
			game->height_w / 2);
		game->mouse_prev_x = game->width_w / 2;
	}
	game->need_redraw = true;
	return (0);
}

void	ft_handle_teleport(t_game *game)
{
	int	map_x;
	int	map_y;

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

void	ft_handle_e(t_game *game, t_player *player)
{
	t_position	check_pos;
	t_position	door_pos;
	t_door		*door;
	int			i;

	check_pos.x = player->pos.x + cos(player->angle) * (2 * PLAYER_RADIUS);
	check_pos.y = player->pos.y + sin(player->angle) * (2 * PLAYER_RADIUS);
	door_pos.x = (int)(check_pos.x / T_SIZE);
	door_pos.y = (int)(check_pos.y / T_SIZE);
	i = -1;
	while (++i < game->map->num_doors)
	{
		door = &game->map->doors[i];
		if (door->x == (int)door_pos.x && door->y == (int)door_pos.y)
		{
			if (!door->is_open)
			{
				door->is_open = true;
				game->map->map[(int)door_pos.y][(int)door_pos.x] = '0';
			}
			break ;
		}
	}
	game->need_redraw = true;
}

void	ft_teleport_player(t_game *game)
{
	t_position	*teleporters;
	int			num_teleporters;
	t_position	cur_pos;
	int			i;
	int			next;

	teleporters = game->map->teleporters;
	num_teleporters = game->map->num_teleporters;
	cur_pos.x = game->player->pos.x / T_SIZE;
	cur_pos.y = game->player->pos.y / T_SIZE;
	i = -1;
	while (++i < num_teleporters)
	{
		if (teleporters[i].x == (int)cur_pos.x
			&& teleporters[i].y == (int)cur_pos.y)
		{
			next = (i + 1) % num_teleporters;
			game->player->pos.x = teleporters[next].x * T_SIZE + T_SIZE / 2;
			game->player->pos.y = teleporters[next].y * T_SIZE + T_SIZE / 2;
			return ;
		}
	}
}
