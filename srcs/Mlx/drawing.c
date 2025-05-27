/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:41 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/27 16:00:19 by lde-merc         ###   ########.fr       */
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
	while (++i < T_SIZE - 1)
	{
		j = 0;
		while (++j < T_SIZE - 1)
			my_mlx_pixel_put(game->mlx, x + j, y + i, color);
	}
}

void	ft_draw_line(t_mlx *mlx, t_position x1, t_position x2, int color)
{
	t_position	dxdy;
	t_position	inc;
	t_position	current;
	int			steps;
	int			i;

	dxdy.x = x2.x - x1.x;
	dxdy.y = x2.y - x1.y;
	if (abs((int)dxdy.x) > abs((int)dxdy.y))
		steps = abs((int)dxdy.x);
	else
		steps = abs((int)dxdy.x);
	inc.x = dxdy.x / (float)steps;
	inc.y = dxdy.y / (float)steps;
	current.x = x1.x;
	current.y = x1.y;
	i = -1;
	while (++i < steps)
	{
		my_mlx_pixel_put(mlx, (int)current.x, (int)current.y, color);
		current.x += inc.x;
		current.y += inc.y;
	}
}

void	ft_draw_rectangle(t_position start, int height, int width, int color)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	mlx = ft_get_game()->mlx;
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			my_mlx_pixel_put(mlx, start.x + i, start.y + j, color);
	}
}
