/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 17:16:14 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display(t_game *game, int flag)
{
	t_raycasting	ray;
	t_mlx			*mlx;

	mlx = game->mlx;
	if (flag)
		ft_display_all(game);
	ft_ray_casting(&ray, game, flag);
	mlx_do_sync(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	ft_ray_casting(t_raycasting *ray, t_game *game, int flag)
{
	int	r;

	ft_init_ray(ray, game, flag);
	r = -1;
	while (++r < ray->num_rays)
	{
		ray->dof = 0;
		ft_horizontal_raycasting(ray, game);
		ft_dda_loop(ray, game, 1);
		ray->dof = 0;
		ft_vertical_raycasting(ray, game);
		ft_dda_loop(ray, game, 2);
		ft_choose_ray(ray, game, flag);
		ft_draw_3d(ray, game, r, flag);
		ft_update_angle(ray);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
}

void	ft_init_ray(t_raycasting *ray, t_game *game, int flag)
{
	ray->num_rays = game->width_w;
	ray->dof = 0;
	ray->angle = game->player->angle - 30 * PI / 180;
	if (ray->angle < 0)
		ray->angle += 2 * PI;
	if (ray->angle > 2 * PI)
		ray->angle -= 2 * PI;
	if (flag == 1)
		ray->width = ((double)game->width_w / 2) / ray->num_rays;
	else
		ray->width = (double)game->width_w / ray->num_rays;
	ray->p = (int)(log2((double)T_SIZE));
}
