/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:37:39 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/15 13:31:10 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_all(t_game *game)
{
	ft_display_background(game);
	ft_display_map(game);
	ft_display_player(game);
}

void	ft_display_background(t_game *game)
{
	int	color;
	int	i;
	int	j;

	color = ft_create_color(255, 85, 85, 85);
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	i = -1;
	while (++i < game->height_w)
	{
		j = -1;
		while (++j < game->width_w)
			my_mlx_pixel_put(game->mlx, j, i, color);
	}
}

void	ft_display_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->map[i][j] == '1')
				ft_draw_square(game, j * 64, i * 64, ft_create_color(255, 255,
						255, 255));
			if (game->map->map[i][j] == '0')
				ft_draw_square(game, j * 64, i * 64, ft_create_color(255, 0, 0,
						0));
		}
	}
}

void	ft_display_player(t_game *game)
{
	int	i;
	int	j;
	int	x2;
	int	y2;

	i = -5;
	while (++i < 6)
	{
		j = -5;
		while (++j < 6)
		{
			my_mlx_pixel_put(game->mlx, game->player->pos.x + i,
				game->player->pos.y + j, ft_create_color(255, 255, 255, 0));
		}
	}
	i = game->player->pos.x;
	j = game->player->pos.y;
	x2 = i + 5 * game->player->dx;
	y2 = j + 5 * game->player->dy;
	ft_draw_line(game->mlx, i, j, x2, y2, ft_create_color(255, 255, 255, 0));
}
