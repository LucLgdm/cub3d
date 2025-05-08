/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/08 16:39:55 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color){
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	create_color(int t, int r, int g, int b){
	return (t << 24) | (r << 16) | (g << 8) | b;
}


static void	ft_draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 63)
	{
		j = 0;
		while (++j < 63)
			my_mlx_pixel_put(game->mlx, x + j, y + i, color);
	}
}

static void	ft_draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2, int color)
{
    int	dx;
    int	dy;
    int	steps;
    float	x_inc;
    float	y_inc;
    float	x;
    float	y;

    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Nombre de pas nécessaires
    x_inc = dx / (float)steps; // Incrément en x
    y_inc = dy / (float)steps; // Incrément en y
    x = x1;
    y = y1;
    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(mlx, (int)x, (int)y, color); // Dessiner le pixel
        x += x_inc;
        y += y_inc;
    }
}

void	ft_display(t_game *game)
{
	int color = create_color(255, 255 / 3, 255 / 3, 255 / 3);
	// Background
	for(int x = 0; x <= game->width_w; x++){
		for(int y = 0; y <= game->height_w; y++){
			my_mlx_pixel_put(game->mlx, x, y, color);
		}
	}
	
	// Map
	int i, j;
	i = -1;
	while(++i < game->map->height){
		j = -1;
		while(++j < game->map->width){
			if (game->map->map[i][j] == '1')
				ft_draw_square(game, j * 64, i * 64, create_color(255, 255, 255, 255));
			if (game->map->map[i][j] == '0')
				ft_draw_square(game, j * 64, i * 64, create_color(255, 0, 0, 0));
		}
	}
	
	
	// Player
	for(int i = -5; i < 6; i++){
		for(int j = -5; j < 6; j++){
			my_mlx_pixel_put(game->mlx, game->player->pos.x + i, game->player->pos.y + j, create_color(255, 255, 255, 0));
		}
	}
	
	// Player direction line
	int line_color = create_color(255, 255, 255, 0); // Vert
	int x1 = game->player->pos.x;
	int y1 = game->player->pos.y;
	int x2 = x1 + 5 * game->player->dx;
	int y2 = y1 + 5 * game->player->dy;
	ft_draw_line(game->mlx, x1, y1, x2, y2, line_color);
	
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
}
