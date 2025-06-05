/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:40:04 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/05 10:11:26 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define MINIMAP_RADIUS 80
#define MINIMAP_CENTER_X (MINIMAP_RADIUS + 50)
#define MINIMAP_CENTER_Y (game->height_w - MINIMAP_RADIUS - 100)

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
}

static void	ft_color_mini_map(t_game *game, t_mini_map *map)
{
	unsigned int	color;
	char			c;

	color = 0x000000;
	if (map->cell_x >= 0 && map->cell_y >= 0 && map->cell_y < game->map->height
		&& map->cell_x < (int)ft_strlen(game->map->map[map->cell_y]))
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
	my_mlx_pixel_put(game->mlx, MINIMAP_CENTER_X + map->dx, MINIMAP_CENTER_Y
		+ map->dy, color);
}

void	draw_minimap(t_game *game)
{
	t_mini_map	*map;
	int			mx;
	int			my;

	map = ft_calloc(1, sizeof(t_mini_map));
	if (!map)
		ft_print_error_and_exit("Error\nAllocation failed for minimap\n");
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

void	ft_draw_player_mini(t_game *game)
{
	t_position	player_icon;
	t_position	dir_start;
	t_position	dir_end;

	player_icon.x = MINIMAP_CENTER_X - 3;
	player_icon.y = MINIMAP_CENTER_Y - 3;
	ft_draw_rectangle(player_icon, 6, 6, 0xFF0000);
	dir_start.x = MINIMAP_CENTER_X;
	dir_start.y = MINIMAP_CENTER_Y;
	dir_end.x = MINIMAP_CENTER_X;
	dir_end.y = MINIMAP_CENTER_Y - 20;
	ft_draw_line(game->mlx, dir_start, dir_end, 0xFF0000);
}
