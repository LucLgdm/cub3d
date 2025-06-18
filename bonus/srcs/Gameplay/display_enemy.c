/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:02:39 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 14:09:13 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_sprite(t_game *game)
{
	int	i;

	i = -1;
	while(++i < game->map->num_enemy)
	{
		ft_move_enemy(game, &game->map->enemy[i]);
		ft_draw_enemy(game, game->map->enemy[i]);
	}
}

void	ft_draw_enemy(t_game *game, t_enemy enemy)
{
    double	dx = enemy.pos.x - game->player->pos.x;
    double	dy = enemy.pos.y - game->player->pos.y;
    double	dist = sqrt(dx * dx + dy * dy);

    double angle = atan2(dy, dx) - game->player->angle;
    while (angle > PI)
        angle -= 2 * PI;
    while (angle < -PI)
        angle += 2 * PI;

    double fov = 60 * PI / 180;
    if (fabs(angle) < fov / 2)
    {
        int screen_x = (int)((angle / (fov / 2)) * (game->width_w / 2) + (game->width_w / 2));
        int sprite_size = (int)(T_SIZE * game->height_w / dist);

        int y_start = game->height_w / 2 - sprite_size / 2;
        int y_end = y_start + sprite_size;
        int x_start = screen_x - sprite_size / 2;
        int x_end = x_start + sprite_size;

		t_tex *tex = &game->image->vilain;

        for (int x = x_start; x < x_end; x++)
        {
            if (x < 0 || x >= game->width_w || dist >= game->zbuffer[x])
                continue;
            int tex_x = (int)((double)(x - x_start) / sprite_size * tex->width);
            for (int y = y_start; y < y_end; y++)
            {
                if (y < 0 || y >= game->height_w)
                    continue;
                int tex_y = (int)((double)(y - y_start) / sprite_size * tex->height);
                int color = *(int *)(tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8)));
                if ((color & 0x00FFFFFF) != 0x00FF00FF)
                	my_mlx_pixel_put(game->mlx, x, y, color);
            }
        }
    }
}
