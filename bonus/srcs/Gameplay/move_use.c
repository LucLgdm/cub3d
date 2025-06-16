/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:31:26 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 12:35:43 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_wall_at(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / T_SIZE);
	map_y = (int)(y / T_SIZE);
	if (map_x < 0 || map_y < 0 || map_y >= game->map->height
		|| map_x >= game->map->width)
		return (1);
	return (game->map->map[map_y][map_x] != '0'
		&& game->map->map[map_y][map_x] != 'T');
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
	game->player->angle -= 100 *game->player->rotation_speed;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
	game->need_redraw = true;
}

void	ft_handle_right(t_game *game)
{
	game->player->angle += 100 * game->player->rotation_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
	game->need_redraw = true;
}

void	ft_handle_shift(t_game *game)
{
	if (game->buttons->shift.pressed)
		game->player->velocity = game->player->base_velocity * 1.5;
	else
		game->player->velocity = game->player->base_velocity;
}
