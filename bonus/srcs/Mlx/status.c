/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:51:53 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/27 15:53:19 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	ft_handle_key(game);
	return (0);
}
