/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/22 10:12:22 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
