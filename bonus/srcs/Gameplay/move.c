/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:50:03 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 14:25:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_handle_w(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos.x + game->player->dx * game->player->velocity;
	new_y = game->player->pos.y + game->player->dy * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	ft_handle_door(game);
	ft_handle_teleport(game);
	game->need_redraw = true;
}

void	ft_handle_s(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos.x - game->player->dx * game->player->velocity;
	new_y = game->player->pos.y - game->player->dy * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	ft_handle_door(game);
	ft_handle_teleport(game);
	game->need_redraw = true;
}

void	ft_handle_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos.x + game->player->dy * game->player->velocity;
	new_y = game->player->pos.y - game->player->dx * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	ft_handle_door(game);
	ft_handle_teleport(game);
	game->need_redraw = true;
}

void	ft_handle_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos.x - game->player->dy * game->player->velocity;
	new_y = game->player->pos.y + game->player->dx * game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
	ft_handle_door(game);
	ft_handle_teleport(game);
	game->need_redraw = true;
}
