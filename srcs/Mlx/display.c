/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/06 17:45:47 by lde-merc         ###   ########.fr       */
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
		{
			if (game->map->map[y / 64][x / 64] == '1')
				my_mlx_pixel_put(game->mlx, x + j, y + i, color);
			else if (game->map->map[y / 64][x / 64] == ' ')
				my_mlx_pixel_put(game->mlx, x + j, y + i, color);
		}
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
				ft_draw_square(game, j * 64, i * 64, create_color(255, 0, 0, 0));
			else if (game->map->map[i][j] == '0')
				ft_draw_square(game, j * 64, i * 64, create_color(255, 255, 255, 255));
		}
	}
	
 
	// Player
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			my_mlx_pixel_put(game->mlx, game->player->pos.x + i, game->player->pos.y + j, create_color(255, 255, 255, 0));
		}
	}

	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
}
