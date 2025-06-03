/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:50:03 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/03 14:15:25 by lde-merc         ###   ########.fr       */
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
