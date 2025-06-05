/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:39:38 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/04 12:25:22 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*

void	ft_draw_floor(t_game *game, t_wall wp, t_raycasting *ray)
{
	int	y;
	int		color;
	float	dist;
	float	weight;
	t_position pos_tex;
	t_position pos_floor;
	t_tex	*floor_tex = &game->image->floor;
	
	y = wp.start + wp.height - 1;
	while(++y < game->height_w)
	{
		dist = (float)game->height_w / (2.0f * (float)y - (float)game->height_w);
		weight = dist / ray->dist_min;
		
		pos_floor.x = weight * ray->final.x + (1.0f - weight) * game->player->pos.x;
        pos_floor.y = weight * ray->final.y + (1.0f - weight) * game->player->pos.y;

        pos_tex.x = (int)(pos_floor.x * floor_tex->width) % floor_tex->width;
        pos_tex.y = (int)(pos_floor.y * floor_tex->height) % floor_tex->height;

		
        color = ft_get_tex_pixel(floor_tex, (int)pos_tex.x, (int)pos_tex.y);

        my_mlx_pixel_put(game->mlx, wp.column_x, y, color);
	}
}

void	ft_draw_floor(t_game *game, t_wall wp, t_raycasting *ray)
{
    int		y;
    int		color;
    float	dy, raFix, tx, ty;
    t_tex	*floor_tex = &game->image->floor;
    float	deg;
	float fov = 60.0f * PI / 180.0f;
	float dist_proj = (float)game->width_w / 2.0f / tan(fov / 2.0f);

    y = wp.start + wp.height - 1;
    while (++y < game->height_w)
    {
        dy = y - (float)game->height_w / 2.0f;
        if (dy == 0)
            continue;
        deg = ray->angle;
        raFix = cos(game->player->angle - ray->angle);
        // Calcule la position au sol (tx, ty) correspondant au pixel (r, y)
        ty = (float)game->player->pos.y / 2.0 - sin(deg) * dist_proj * (float)T_SIZE / (dy / raFix);
        tx = (float)game->player->pos.x / 2.0 + cos(deg) * dist_proj * (float)T_SIZE / (dy / raFix);

        int tex_x = ((int)tx) % floor_tex->width;
        int tex_y = ((int)ty) % floor_tex->height;
        if (tex_x < 0) tex_x += floor_tex->width;
        if (tex_y < 0) tex_y += floor_tex->height;

        color = ft_get_tex_pixel(floor_tex, tex_x, tex_y);

        my_mlx_pixel_put(game->mlx, wp.column_x, y, color);
    }
}

*/

static unsigned int	ft_get_tex_pixel(t_tex *tex, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_draw_floor_and_ceiling(t_game *game)
{
    {
    int		y, x;
    float	rayDirX0, rayDirY0, rayDirX1, rayDirY1;
    float	rowDistance, floorStepX, floorStepY, floorX, floorY;
    float	posZ = 0.5f * game->height_w;
    float	dirX = cos(game->player->angle);
    float	dirY = sin(game->player->angle);
    float	planeX = cos(game->player->angle + PI / 2) * 0.60f; // 0.66 = fov
    float	planeY = sin(game->player->angle + PI / 2) * 0.60f;
    t_tex	*floor_tex = &game->image->floor;
    t_tex	*ceil_tex = &game->image->ceiling; // si tu as une texture plafond

    for (y = game->height_w / 2 + 1; y < game->height_w; ++y)
    {
        int p = y - game->height_w / 2;
        rowDistance = posZ / p;

        rayDirX0 = dirX - planeX;
        rayDirY0 = dirY - planeY;
        rayDirX1 = dirX + planeX;
        rayDirY1 = dirY + planeY;

        floorStepX = rowDistance * (rayDirX1 - rayDirX0) / game->width_w;
        floorStepY = rowDistance * (rayDirY1 - rayDirY0) / game->width_w;

        floorX = game->player->pos.x + rowDistance * rayDirX0;
        floorY = game->player->pos.y + rowDistance * rayDirY0;

        for (x = 0; x < game->width_w; ++x)
        {
            int cellX = (int)floorX;
            int cellY = (int)floorY;

            int tex_x = (int)(floor_tex->width * (floorX - cellX)) & (floor_tex->width - 1);
            int tex_y = (int)(floor_tex->height * (floorY - cellY)) & (floor_tex->height - 1);

            unsigned int color = ft_get_tex_pixel(floor_tex, tex_x, tex_y);
            my_mlx_pixel_put(game->mlx, x, y, color);

            // Plafond symétrique (optionnel)
            if (ceil_tex)
            {
                unsigned int ceil_color = ft_get_tex_pixel(ceil_tex, tex_x, tex_y);
                my_mlx_pixel_put(game->mlx, x, game->height_w - y - 1, ceil_color);
            }

            floorX += floorStepX;
            floorY += floorStepY;
        }
    }
}
}
