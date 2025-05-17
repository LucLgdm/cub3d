/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:44 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/17 11:15:24 by luclgdm          ###   ########.fr       */
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
	ft_handle_key(game);
	ft_display(game, (int)game->correction);
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
}

static bool ft_is_wall(t_map *map, float x, float y)
{
	int	i;
	int	j;

	i = (int)(y / TILE_SIZE);
	j = (int)(x / TILE_SIZE);
	if (i < 0 || i >= map->height || j < 0 || j >= map->width)
		return (true);
	return (map->map[i][j] == '1');
}


void	ft_handle_w(t_game *game)
{
	float	tmpx;
	float	tmpy;

	tmpx = game->player->pos.x + game->player->dx;
	tmpy = game->player->pos.y + game->player->dy;
	if (!ft_is_wall(game->map, tmpx, game->player->pos.y))
		game->player->pos.x += game->player->dx;
	if (!ft_is_wall(game->map, game->player->pos.x, tmpy))
		game->player->pos.y += game->player->dy;
}

void	ft_handle_s(t_game *game)
{
	float	tmpx;
	float	tmpy;
	// float	x0;
	// float	y0;

	// x0 = 0;
	// y0 = 0;
	// if (game->player->dx < 0)
	// 	x0 = 5;
	// else
	// 	x0 = -5;
	// if (game->player->dy < 0)
	// 	y0 = -5;
	// else
	// 	y0 = 5;
	tmpx = game->player->pos.x - game->player->dx;
	tmpy = game->player->pos.y - game->player->dy;
	if (!ft_is_wall(game->map, tmpx, game->player->pos.y))
		game->player->pos.x -= game->player->dx;
	if (!ft_is_wall(game->map, game->player->pos.x, tmpy))
		game->player->pos.y -= game->player->dy;
		
	// game->player->pos.x -= game->player->dx;
	// game->player->pos.y -= game->player->dy;
}

void	ft_handle_a(t_game *game)
{
    float	tmpx = game->player->pos.x + game->player->dy;
    float	tmpy = game->player->pos.y - game->player->dx;

    if (!ft_is_wall(game->map, tmpx, game->player->pos.y))
        game->player->pos.x += game->player->dy;
    if (!ft_is_wall(game->map, game->player->pos.x, tmpy))
        game->player->pos.y -= game->player->dx;
}

void	ft_handle_d(t_game *game)
{
    float	tmpx = game->player->pos.x - game->player->dy;
    float	tmpy = game->player->pos.y + game->player->dx;

    if (!ft_is_wall(game->map, tmpx, game->player->pos.y))
        game->player->pos.x -= game->player->dy;
    if (!ft_is_wall(game->map, game->player->pos.x, tmpy))
        game->player->pos.y += game->player->dx;
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
	t_game *game;
	
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
