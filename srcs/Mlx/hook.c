/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/27 16:00:19 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PLAYER_RADIUS 10.0f

int	ft_key_handle(int key, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key == 65307)
		ft_close_window(game);
	ft_move_player(game, key);
	return (0);
}

int	ft_is_wall_at(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / T_SIZE);
	map_y = (int)(y / T_SIZE);
	return (game->map->map[map_y][map_x] != '0');
}

int	ft_can_move_to(t_game *game, float x, float y)
{
	if (ft_is_wall_at(game, x + PLAYER_RADIUS, y))
		return (0);
	if (ft_is_wall_at(game, x - PLAYER_RADIUS, y))
		return (0);
	if (ft_is_wall_at(game, x, y + PLAYER_RADIUS))
		return (0);
	if (ft_is_wall_at(game, x, y - PLAYER_RADIUS))
		return (0);
	return (1);
}

void	ft_handle_left(t_game *game)
{
	game->player->angle -= 0.1;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
}

void	ft_handle_right(t_game *game)
{
	game->player->angle += 0.1;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
}
