/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:23:35 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/28 12:24:50 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_image_generator(t_game *game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	ft_image_north(mlx->mlx, &game->image->north);
	ft_image_south(mlx->mlx, &game->image->south);
	ft_image_east(mlx->mlx, &game->image->east);
	ft_image_west(mlx->mlx, &game->image->west);
}

void	ft_image_north(void *mlx, t_tex *north)
{
	north->img = mlx_xpm_file_to_image(mlx, (char *)(north->path),
			&(north->width), &(north->height));
	north->addr = mlx_get_data_addr(north->img, &(north->bits_per_pixel),
			&(north->line_length), &(north->endian));
}

void	ft_image_south(void *mlx, t_tex *south)
{
	south->img = mlx_xpm_file_to_image(mlx, (char *)(south->path),
			&(south->width), &(south->height));
	south->addr = mlx_get_data_addr(south->img, &(south->bits_per_pixel),
			&(south->line_length), &(south->endian));
}

void	ft_image_east(void *mlx, t_tex *east)
{
	east->img = mlx_xpm_file_to_image(mlx, (char *)(east->path), &(east->width),
			&(east->height));
	east->addr = mlx_get_data_addr(east->img, &(east->bits_per_pixel),
			&(east->line_length), &(east->endian));
}

void	ft_image_west(void *mlx, t_tex *west)
{
	west->img = mlx_xpm_file_to_image(mlx, (char *)(west->path), &(west->width),
			&(west->height));
	west->addr = mlx_get_data_addr(west->img, &(west->bits_per_pixel),
			&(west->line_length), &(west->endian));
}
