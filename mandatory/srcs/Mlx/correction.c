/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:37:39 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/19 09:23:28 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
				ft_draw_square(game, j * T_SIZE, i * T_SIZE,
					ft_create_color(255, 255, 255, 255));
			else if (game->map->map[i][j] == '0')
				ft_draw_square(game, j * T_SIZE, i * T_SIZE,
					ft_create_color(255, 0, 0, 0));
		}
	}
}

void	ft_display_player(t_game *game)
{
	t_position	pos;
	t_position	pos_next;
	t_position	tmp;
	int			color;

	color = ft_create_color(255, 255, 255, 0);
	pos.x = -5;
	while (++(pos.x) < 6)
	{
		pos.y = -5;
		while (++(pos.y) < 6)
		{
			tmp.x = game->player->pos.x + pos.x;
			tmp.y = game->player->pos.y + pos.y;
			my_mlx_pixel_put(game->mlx, tmp.x, tmp.y, color);
		}
	}
	pos.x = game->player->pos.x;
	pos.y = game->player->pos.y;
	pos_next.x = pos.x + 5 * game->player->dx;
	pos_next.y = pos.y + 5 * game->player->dy;
	ft_draw_line(game->mlx, pos, pos_next, color);
}
