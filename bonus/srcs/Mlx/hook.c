/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/28 15:15:16 by lde-merc         ###   ########.fr       */
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
	mlx_mouse_move(game->mlx->mlx, game->mlx->win, game->width_w / 2,
		game->height_w / 2);
	game->mouse_prev_x = game->width_w / 2;
	return (0);
}
