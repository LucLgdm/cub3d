/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/20 17:04:08 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	// ft_handle_key(game);
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

// static bool ft_is_wall(t_map *map, float x, float y)
// {
// 	int	i;
// 	int	j;

// 	i = (int)(y / TILE_SIZE);
// 	j = (int)(x / TILE_SIZE);
// 	if (i < 0 || i >= map->height || j < 0 || j >= map->width)
// 		return (true);
// 	return (map->map[i][j] == '1');
// }

void	ft_handle_w(t_game *game)
{
	float	off = 10.0f;
    float	new_x = game->player->pos.x + game->player->dx * off * game->player->velocity;
    float	new_y = game->player->pos.y + game->player->dy * off * game->player->velocity;

    // Vérifie X seul
    if (game->map->map[(int)(game->player->pos.y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '0')
        game->player->pos.x = new_x;
    // Vérifie Y seul
    if (game->map->map[(int)(new_y / TILE_SIZE)][(int)(game->player->pos.x / TILE_SIZE)] == '0')
        game->player->pos.y = new_y;
		
	// t_position	offset;
	// t_position	add_off;
	// t_position	player;

	// offset.x = 0;
	// offset.y = 0;
	// if (game->player->dx < 0)
	// 	offset.x = -10;
	// else
	// 	offset.x = 10;
	// if (game->player->dy < 0)
	// 	offset.y = -10;
	// else
	// 	offset.y = 10;
	// player.x = game->player->pos.x / TILE_SIZE;
	// player.y = game->player->pos.y / TILE_SIZE;
	// add_off.x = (game->player->pos.x + offset.x) / TILE_SIZE;
	// add_off.y = (game->player->pos.y + offset.y) / TILE_SIZE;
	// if (game->map->map[(int)player.y][(int)add_off.x] == '0')
	// 	game->player->pos.x += game->player->dx * game->player->velocity;
	// if (game->map->map[(int)add_off.y][(int)player.x] == '0')
	// 	game->player->pos.y += game->player->dy * game->player->velocity;
}

void	ft_handle_s(t_game *game)
{
	float	off = 10.0f;
    float	new_x = game->player->pos.x - game->player->dx * off * game->player->velocity;
    float	new_y = game->player->pos.y - game->player->dy * off * game->player->velocity;

    // Vérifie X seul
    if (game->map->map[(int)(game->player->pos.y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '0')
        game->player->pos.x = new_x;
    // Vérifie Y seul
    if (game->map->map[(int)(new_y / TILE_SIZE)][(int)(game->player->pos.x / TILE_SIZE)] == '0')
        game->player->pos.y = new_y;
		
	// t_position	offset;
	// t_position	sub_off;
	// t_position	player;

	// offset.x = 0;
	// offset.y = 0;
	// if (game->player->dx < 0)
	// 	offset.x = -10;
	// else
	// 	offset.x = 10;
	// if (game->player->dy < 0)
	// 	offset.y = -10;
	// else
	// 	offset.y = 10;
	// player.x = game->player->pos.x / TILE_SIZE;
	// player.y = game->player->pos.y / TILE_SIZE;
	// sub_off.x = (game->player->pos.x - offset.x) / TILE_SIZE;
	// sub_off.y = (game->player->pos.y - offset.y) / TILE_SIZE;
	// if (game->map->map[(int)player.y][(int)sub_off.x] == '0')
	// 	game->player->pos.x -= game->player->dx * game->player->velocity;
	// if (game->map->map[(int)sub_off.y][(int)player.x] == '0')
	// 	game->player->pos.y -= game->player->dy * game->player->velocity;
}

void	ft_handle_a(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 10.0f;
	new_x = game->player->pos.x + game->player->dy * off
		* game->player->velocity;
	new_y = game->player->pos.y - game->player->dx * off
		* game->player->velocity;
	// Vérifie X seul
	if (game->map->map[(int)(game->player->pos.y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '0')
		game->player->pos.x = new_x;
	// Vérifie Y seul
	if (game->map->map[(int)(new_y / TILE_SIZE)][(int)(game->player->pos.x / TILE_SIZE)] == '0')
		game->player->pos.y = new_y;

	// t_position	offset;
	// t_position	add_off;
	// t_position	player;
	// offset.x = 0;
	// offset.y = 0;
	// if (game->player->dy < 0)
	// 	offset.x = -10;
	// else
	// 	offset.x = 10;
	// if (game->player->dx > 0)
	// 	offset.y = -10;
	// else
	// 	offset.y = 10;
	// player.x = game->player->pos.x / TILE_SIZE;
	// player.y = game->player->pos.y / TILE_SIZE;
	// add_off.x = (game->player->pos.x + offset.x) / TILE_SIZE;
	// add_off.y = (game->player->pos.y - offset.y) / TILE_SIZE;
	// if (game->map->map[(int)player.y][(int)add_off.x] == '0')
	// 	game->player->pos.x += game->player->dy * game->player->velocity;
	// if (game->map->map[(int)add_off.y][(int)player.x] == '0')
	// 	game->player->pos.y -= game->player->dx * game->player->velocity;
	
}

void	ft_handle_d(t_game *game)
{
	float	off;
	float	new_x;
	float	new_y;

	off = 10.0f;
	new_x = game->player->pos.x - game->player->dy * off
		* game->player->velocity;
	new_y = game->player->pos.y + game->player->dx * off
		* game->player->velocity;
	// Vérifie X seul
	if (game->map->map[(int)(game->player->pos.y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '0')
		game->player->pos.x = new_x;
	// Vérifie Y seul
	if (game->map->map[(int)(new_y / TILE_SIZE)][(int)(game->player->pos.x / TILE_SIZE)] == '0')
		game->player->pos.y = new_y;
}


	// void	ft_handle_d(t_game *game)
	// {
	// 	t_position	offset;
	// 	t_position	add_off;
	// 	t_position	player;

	// 	offset.x = 0;
	// 	offset.y = 0;
	// 	if (game->player->dy < 0)
	// 		offset.x = -10;
	// 	else
	// 		offset.x = 10;
	// 	if (game->player->dx > 0)
	// 		offset.y = -10;
	// 	else
	// 		offset.y = 10;
	// 	player.x = game->player->pos.x / TILE_SIZE;
	// 	player.y = game->player->pos.y / TILE_SIZE;
	// 	add_off.x = (game->player->pos.x - offset.x) / TILE_SIZE;
	// 	add_off.y = (game->player->pos.y + offset.y) / TILE_SIZE;
	// 	if (game->map->map[(int)player.y][(int)add_off.x] == '0')
	// 		game->player->pos.x -= game->player->dy * game->player->velocity;
	// 	if (game->map->map[(int)add_off.y][(int)player.x] == '0')
	// 		game->player->pos.y += game->player->dx * game->player->velocity;
	// }

	void
	ft_handle_left(t_game *game)
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
