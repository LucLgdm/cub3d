/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_geometrical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:03:30 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/19 12:17:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_sort_triangle_points(t_position *pts)
{
	int			i;
	int			j;
	t_position	tmp;

	i = -1;
	while (++i < 3)
	{
		j = i;
		while (++j < 3)
		{
			if (pts[i].y > pts[j].y)
			{
				tmp = pts[i];
				pts[i] = pts[j];
				pts[j] = tmp;
			}
		}
	}
}

static void	ft_draw_scanline(t_game *game, t_position pos, int y, int color)
{
	int	x;

	if (pos.x > pos.y)
	{
		x = pos.x;
		pos.x = pos.y;
		pos.y = x;
	}
	x = pos.x;
	while (x <= pos.y)
	{
		my_mlx_pixel_put(game->mlx, x, y, color);
		x++;
	}
}

static double	ft_lerp(double x0, double x1, double t)
{
	return (x0 + (x1 - x0) * t);
}

static void	ft_fill_triangle_area(t_game *game, t_position *p, int color)
{
	t_position	x;
	double		y;
	double		t;

	y = p[0].y;
	while (y <= p[2].y)
	{
		if (y < p[1].y)
		{
			t = (y - p[0].y) / (p[1].y - p[0].y + 0.0001);
			x.x = ft_lerp(p[0].x, p[1].x, t);
			t = (y - p[0].y) / (p[2].y - p[0].y + 0.0001);
			x.y = ft_lerp(p[0].x, p[2].x, t);
		}
		else
		{
			t = (y - p[1].y) / (p[2].y - p[1].y + 0.0001);
			x.x = ft_lerp(p[1].x, p[2].x, t);
			t = (y - p[0].y) / (p[2].y - p[0].y + 0.0001);
			x.y = ft_lerp(p[0].x, p[2].x, t);
		}
		ft_draw_scanline(game, x, (int)y, color);
		y++;
	}
}

void	ft_fill_triangle(t_position a, t_position b, t_position c, int color)
{
	t_game		*game;
	t_position	pts[3];

	game = ft_get_game();
	pts[0] = a;
	pts[1] = b;
	pts[2] = c;
	ft_sort_triangle_points(pts);
	ft_fill_triangle_area(game, pts, color);
}
