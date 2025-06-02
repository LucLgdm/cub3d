/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:39:38 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/02 14:57:34 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



// void	ft_draw_floor(t_game *game, t_wall wp, t_raycasting *ray)
// {
// 	int	y;
// 	int		color;
// 	float	dist;
// 	float	weight;
// 	t_position pos_tex;
// 	t_position pos_floor;
// 	t_tex	*floor_tex = &game->image->floor;
	
// 	y = wp.start + wp.height - 1;
// 	while(++y < game->height_w)
// 	{
// 		dist = (float)game->height_w / (2.0f * (float)y - (float)game->height_w);
// 		weight = dist / ray->dist_min;
		
// 		pos_floor.x = weight * ray->final.x + (1.0f - weight) * game->player->pos.x;
//         pos_floor.y = weight * ray->final.y + (1.0f - weight) * game->player->pos.y;

//         pos_tex.x = (int)(pos_floor.x * floor_tex->width) % floor_tex->width;
//         pos_tex.y = (int)(pos_floor.y * floor_tex->height) % floor_tex->height;

		
//         color = ft_get_tex_pixel(floor_tex, (int)pos_tex.x, (int)pos_tex.y);

//         my_mlx_pixel_put(game->mlx, wp.column_x, y, color);
// 	}
// }

// void	ft_draw_floor(t_game *game, t_wall wp, t_raycasting *ray)
// {
//     int		y;
//     int		color;
//     float	dy, raFix, tx, ty;
//     t_tex	*floor_tex = &game->image->floor;
//     float	deg;
// 	float fov = 60.0f * PI / 180.0f;
// 	float dist_proj = (float)game->width_w / 2.0f / tan(fov / 2.0f);

//     y = wp.start + wp.height - 1;
//     while (++y < game->height_w)
//     {
//         dy = y - (float)game->height_w / 2.0f;
//         if (dy == 0)
//             continue;
//         deg = ray->angle;
//         raFix = cos(game->player->angle - ray->angle);
//         // Calcule la position au sol (tx, ty) correspondant au pixel (r, y)
//         ty = (float)game->player->pos.y / 2.0 - sin(deg) * dist_proj * (float)T_SIZE / (dy / raFix);
//         tx = (float)game->player->pos.x / 2.0 + cos(deg) * dist_proj * (float)T_SIZE / (dy / raFix);

//         int tex_x = ((int)tx) % floor_tex->width;
//         int tex_y = ((int)ty) % floor_tex->height;
//         if (tex_x < 0) tex_x += floor_tex->width;
//         if (tex_y < 0) tex_y += floor_tex->height;

//         color = ft_get_tex_pixel(floor_tex, tex_x, tex_y);

//         my_mlx_pixel_put(game->mlx, wp.column_x, y, color);
//     }
// }

