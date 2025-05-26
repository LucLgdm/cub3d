/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/26 16:03:53 by lde-merc         ###   ########.fr       */
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

void	ft_move_player(t_game *game, int key)
{
	if (key == 119)
		game->buttons.w.pressed = 1;
	if (key == 115)
		game->buttons.s.pressed = 1;
	if (key == 97)
		game->buttons.a.pressed = 1;
	if (key == 100)
		game->buttons.d.pressed = 1;
	if (key == 65361)
		game->buttons.left.pressed = 1;
	if (key == 65363)
		game->buttons.right.pressed = 1;
}

int	ft_game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	ft_handle_key(game);
	return (0);
}

void	ft_handle_key(t_game *game)
{
	if (game->buttons.w.pressed)
		ft_handle_w(game);
	if (game->buttons.s.pressed)
		ft_handle_s(game);
	if (game->buttons.a.pressed)
		ft_handle_a(game);
	if (game->buttons.d.pressed)
		ft_handle_d(game);
	if (game->buttons.left.pressed)
		ft_handle_left(game);
	if (game->buttons.right.pressed)
		ft_handle_right(game);
	ft_display(game, (int)game->correction);
}

static int	ft_is_wall_at(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	return (game->map->map[map_y][map_x] != '0');
}

static int	ft_can_move_to(t_game *game, float x, float y)
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

void	ft_handle_w(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 1.0f;
	new_x = game->player->pos.x + game->player->dx * off
		* game->player->velocity;
	new_y = game->player->pos.y + game->player->dy * off
		* game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
}

void	ft_handle_s(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 1.0f;
	new_x = game->player->pos.x - game->player->dx * off
		* game->player->velocity;
	new_y = game->player->pos.y - game->player->dy * off
		* game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
}

void	ft_handle_a(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 1.0f;
	new_x = game->player->pos.x + game->player->dy * off
		* game->player->velocity;
	new_y = game->player->pos.y - game->player->dx * off
		* game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
}

void	ft_handle_d(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 1.0f;
	new_x = game->player->pos.x - game->player->dy * off
		* game->player->velocity;
	new_y = game->player->pos.y + game->player->dx * off
		* game->player->velocity;
	if (ft_can_move_to(game, new_x, game->player->pos.y))
		game->player->pos.x = new_x;
	if (ft_can_move_to(game, game->player->pos.x, new_y))
		game->player->pos.y = new_y;
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

int	ft_key_release(int key, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key == 119)
		game->buttons.w.pressed = 0;
	if (key == 115)
		game->buttons.s.pressed = 0;
	if (key == 97)
		game->buttons.a.pressed = 0;
	if (key == 100)
		game->buttons.d.pressed = 0;
	if (key == 65361)
		game->buttons.left.pressed = 0;
	if (key == 65363)
		game->buttons.right.pressed = 0;
	return (0);
}
