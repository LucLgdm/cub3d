/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/13 15:10:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_player(t_game *game, int key)
{
	if (key == 119) // W
	{
		game->player->pos.x += game->player->dx;
		game->player->pos.y += game->player->dy;
	}
	else if (key == 115) // S
	{
		game->player->pos.x -= game->player->dx;
		game->player->pos.y -= game->player->dy;
	}
	else if (key == 97) // A
	{
		game->player->pos.x += game->player->dy;
		game->player->pos.y -= game->player->dx;
	}
		
	else if (key == 100) // D
	{
		game->player->pos.x -= game->player->dy;
		game->player->pos.y += game->player->dx;
	}
	else if (key == 65361) // Left Arrow
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->dx = 5 * cos(game->player->angle);
		game->player->dy = 5 * sin(game->player->angle);
	}
	else if (key == 65363) // Right Arrow
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->dx = 5 * cos(game->player->angle);
		game->player->dy = 5 * sin(game->player->angle);
	}
	ft_display_correction(game);
}
