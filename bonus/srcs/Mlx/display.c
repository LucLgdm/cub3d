/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/17 15:15:49 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display(t_game *game)
{
	t_mlx			*mlx;
	t_raycasting	*ray;

	mlx = game->mlx;
	if (!game->raycasting)
	{
		game->raycasting = ft_calloc(1, sizeof(t_raycasting));
		if (!game->raycasting)
			ft_print_error_and_exit("Error\nAllocation raycasting failed\n");
	}
	ray = game->raycasting;
	ft_ray_casting(ray, game);
	ft_draw_sprite(game);
	ft_draw_minimap(game);
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
		ft_choose_ray(ray, game);
		game->zbuffer[r] = ray->dist_min;
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
	ray->width = (double)game->width_w / ray->num_rays;
	ray->p = (int)(log2((double)T_SIZE));
}
