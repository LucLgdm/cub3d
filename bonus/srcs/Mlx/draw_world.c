/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:36:26 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 14:25:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_wall_column(t_game *game, t_tex *tex, t_wall *wp,
		int tex_x)
{
	double	ty;
	int		screen_y;
	int		tex_y;
	char	*dst;
	int		y;

	y = -1;
	ty = wp->ty_off * wp->ty_step;
	while (++y < (int)wp->height)
	{
		screen_y = wp->start + y;
		if (screen_y < 0 || screen_y >= game->height_w)
			continue ;
		tex_y = (int)ty;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		dst = tex->addr + (tex_y * tex->line_length + tex_x
				* (tex->bits_per_pixel / 8));
		my_mlx_pixel_put(game->mlx, wp->column_x, screen_y,
			*(unsigned int *)dst);
		ty += wp->ty_step;
	}
}
