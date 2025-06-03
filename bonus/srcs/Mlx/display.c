/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/03 13:53:08 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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


static void	ft_draw_floor_and_ceiling(t_game *game)
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


void	ft_display(t_game *game)
{
	t_raycasting	ray;
	t_mlx			*mlx;

	mlx = game->mlx;
	ft_draw_floor_and_ceiling(game);
	ft_ray_casting(&ray, game);
	mlx_do_sync(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	ft_ray_casting(t_raycasting *ray, t_game *game)
{
	int	r;

	ft_init_ray(ray, game);
	r = -1;
	while (++r < ray->num_rays)
	{
		ray->dof = 0;
		ft_horizontal_raycasting(ray, game);
		ft_dda_loop(ray, game, 1);
		ray->dof = 0;
		ft_vertical_raycasting(ray, game);
		ft_dda_loop(ray, game, 2);
		if (ray->pos.y > game->height_w)
			ray->pos.y = game->height_w;
		if (ray->pos.y < 0)
			ray->pos.y = 0;
		ft_choose_ray(ray, game);
		ft_draw_3d(ray, game, r);
		ft_update_angle(ray);
	}
}

void	ft_init_ray(t_raycasting *ray, t_game *game)
{
	ray->num_rays = game->width_w;
	ray->dof = 0;
	ray->angle = game->player->angle - 30 * PI / 180;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
	ray->width = (float)game->width_w / ray->num_rays;
	ray->p = (int)(log2((double)T_SIZE));
}
