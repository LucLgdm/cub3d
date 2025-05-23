/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/23 13:45:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_create_color(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

void	ft_draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i < TILE_SIZE - 1)
	{
		j = 0;
		while (++j < TILE_SIZE - 1)
			my_mlx_pixel_put(game->mlx, x + j, y + i, color);
	}
}

void	ft_draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;

	dx = x2 - x1;
	dy = y2 - y1;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = x1;
	y = y1;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(mlx, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}

void	ft_draw_rectangle(t_mlx *mlx, int x, int y_start, int y_end, int width,
		int color)
{
	int	i;

	i = -1;
	while (++i < width)
		ft_draw_line(mlx, x + i, y_start, x + i, y_end, color);
}
