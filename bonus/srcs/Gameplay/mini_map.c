/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:40:04 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 17:04:39 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_init_mini_map(t_game *game, t_mini_map *map)
{
	map->dist = sqrtf(map->dx * map->dx + map->dy * map->dy) * 2.0f
		* MINIMAP_RADIUS / (2 * MINIMAP_RADIUS);
	map->angle = atan2f(map->dy, map->dx) + game->player->angle + PI / 2;
	map->map_x = game->player->pos.x / T_SIZE + cosf(map->angle) * map->dist
		* 0.15f;
	map->map_y = game->player->pos.y / T_SIZE + sinf(map->angle) * map->dist
		* 0.15f;
	map->cell_x = (int)map->map_x;
	map->cell_y = (int)map->map_y;
	map->center_x = MINIMAP_RADIUS + 50;
	map->center_y = game->height_w - MINIMAP_RADIUS - 100;
}

static void	ft_color_mini_map(t_game *game, t_mini_map *map)
{
	unsigned int	color;
	char			c;

	color = 0x000000;
	if (map->cell_x >= 0 && map->cell_y >= 0 && map->cell_y < game->map->height
		&& map->cell_x < game->map->line_lengths[map->cell_y])
	{
		c = game->map->map[map->cell_y][map->cell_x];
		if (c == '1')
			color = 0x888888;
		else if (c == '0')
			color = 0x333333;
		else if (c == 'D')
			color = 0xFFAA00;
		else if (c == 'T')
			color = 0x00FFFF;
	}
	my_mlx_pixel_put(game->mlx, map->center_x + map->dx, map->center_y
		+ map->dy, color);
}

void	ft_draw_minimap(t_game *game)
{
	t_mini_map	*map;
	int			mx;
	int			my;

	map = game->mini_map;
	my = -1;
	while (++my < 2 * MINIMAP_RADIUS)
	{
		mx = -1;
		while (++mx < 2 * MINIMAP_RADIUS)
		{
			map->dx = mx - MINIMAP_RADIUS;
			map->dy = my - MINIMAP_RADIUS;
			if (map->dx * map->dx + map->dy * map->dy > MINIMAP_RADIUS
				* MINIMAP_RADIUS)
				continue ;
			ft_init_mini_map(game, map);
			ft_color_mini_map(game, map);
		}
	}
	ft_draw_player_mini(game);
}

static void	ft_fill_triangle(t_game *game, t_position a, t_position b, t_position c, int color)
{
    t_position pts[3] = {a, b, c};
    int i, j;

	for (i = 0; i < 3; i++)
        for (j = i + 1; j < 3; j++)
            if (pts[i].y > pts[j].y) {
                t_position tmp = pts[i];
                pts[i] = pts[j];
                pts[j] = tmp;
            }
    double x1, x2, y;
    for (y = pts[0].y; y <= pts[2].y; y++) {
        if (y < pts[1].y) {
            x1 = pts[0].x + (pts[1].x - pts[0].x) * (y - pts[0].y) / (pts[1].y - pts[0].y + 0.0001);
            x2 = pts[0].x + (pts[2].x - pts[0].x) * (y - pts[0].y) / (pts[2].y - pts[0].y + 0.0001);
        } else {
            x1 = pts[1].x + (pts[2].x - pts[1].x) * (y - pts[1].y) / (pts[2].y - pts[1].y + 0.0001);
            x2 = pts[0].x + (pts[2].x - pts[0].x) * (y - pts[0].y) / (pts[2].y - pts[0].y + 0.0001);
        }
        if (x1 > x2) {
            double tmp = x1; x1 = x2; x2 = tmp;
        }
        for (int x = (int)x1; x <= (int)x2; x++)
            my_mlx_pixel_put(game->mlx, x, (int)y, color);
    }
}

void	ft_draw_player_mini(t_game *game)
{
    t_position	a, b, c, d;
    double		front = 8;

    c.x = game->mini_map->center_x;
    c.y = game->mini_map->center_y;

	a.x = game->mini_map->center_x;
	a.y = game->mini_map->center_y - front;

	b.x = game->mini_map->center_x + 3 * front / 5;
	b.y = game->mini_map->center_y + 2 * front / 3;

	d.x = game->mini_map->center_x - 3 * front / 5;
	d.y = game->mini_map->center_y + 2 * front / 3;

	ft_fill_triangle(game, a, b, c, 0xFF0000);
	ft_fill_triangle(game, a, c, d, 0xFF0000);
}


void	ft_draw_enemy_mini(t_game *game, t_enemy *enemy){

}