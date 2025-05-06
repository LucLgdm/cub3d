/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/06 17:45:58 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_player(t_game *game, int key)
{
	if (key == 119) // W
		game->player->pos.y -= 5;
	else if (key == 115) // S
		game->player->pos.y += 5;
	else if (key == 97) // A
		game->player->pos.x -= 5;
	else if (key == 100) // D
		game->player->pos.x += 5;
	ft_display(game);
}