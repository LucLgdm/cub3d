/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:02:39 by lde-merc          #+#    #+#             */
/*   Updated: 2025/07/01 15:47:39 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_sprite(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map->num_enemy)
	{
		ft_move_enemy(game, &game->map->enemy[i]);
		ft_draw_enemy(game, game->map->enemy[i]);
	}
}

void	ft_draw_enemy(t_game *game, t_enemy enemy)
{
	t_position	dxdy;
	double		dist;
	double		angle;
	double		fov;

	dxdy.x = enemy.pos.x - game->player->pos.x;
	dxdy.y = enemy.pos.y - game->player->pos.y;
	dist = sqrt(dxdy.x * dxdy.x + dxdy.y * dxdy.y);
	angle = atan2(dxdy.y, dxdy.x) - game->player->angle;
	while (angle > PI)
		angle -= 2 * PI;
	while (angle < -PI)
		angle += 2 * PI;
	fov = 60 * PI / 180;
	if (fabs(angle) < fov / 2)
		ft_render_enemy_sprite(game, dist, angle, fov);
}

void	ft_render_enemy_sprite(t_game *game, double dist, double angle,
		double fov)
{
	int			screen_x;
	int			sprite_size;
	t_position	start;
	t_position	end;

	screen_x = (int)((angle / (fov / 2)) * (game->width_w / 2) + (game->width_w
				/ 2));
	sprite_size = (int)(T_SIZE * game->height_w / dist);
	start.y = game->height_w / 2 - sprite_size / 2;
	end.y = start.y + sprite_size;
	start.x = screen_x - sprite_size / 2;
	end.x = start.x + sprite_size;
	ft_draw_enemy_texture(game, (t_position[]){start, end}, sprite_size, dist);
}

static t_tex	*ft_choose_tex_enemy(t_game *game)
{
	if (game->map->one_or_two == 0)
		return (&game->image_resized->vilain);
	else if (game->map->one_or_two == 1)
		return (&game->image_resized->vilain_2);
	else
		return (&game->image_resized->vilain_3);
}

void	ft_draw_enemy_texture(t_game *game, t_position *pos, int size,
		double dist)
{
	int			x;
	int			y;
	t_position	texp;
	t_tex		*tex;
	int			color;

	tex = ft_choose_tex_enemy(game);
	x = pos[0].x - 1;
	while (++x < pos[1].x)
	{
		if (x < 0 || x >= game->width_w || dist >= game->zbuffer[x])
			continue ;
		texp.x = (int)((double)(x - pos[0].x) / size * tex->width);
		y = pos[0].y - 1;
		while (++y < pos[1].y)
		{
			if (y < 0 || y >= game->height_w)
				continue ;
			texp.y = (int)((double)(y - pos[0].y) / size * tex->height);
			color = *(int *)(tex->addr + ((int)texp.y * tex->line_length
						+ (int)texp.x * (tex->bits_per_pixel / 8)));
			if ((color & 0x00FFFFFF) != 0x00FF00FF)
				my_mlx_pixel_put(game->mlx, x, y, color);
		}
	}
}
