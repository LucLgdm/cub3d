/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:23:35 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/05 10:33:23 by lde-merc         ###   ########.fr       */
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
	ft_image_floor(mlx->mlx, &game->image->floor);
	ft_image_ceiling(mlx->mlx, &game->image->ceiling);
	ft_image_doors(mlx->mlx, &game->image->doors);
}

void	ft_image_north(void *mlx, t_tex *north)
{
	t_game	*game;

	game = ft_get_game();
	north->img = mlx_xpm_file_to_image(mlx, north->path, &(north->width),
			&(north->height));
	north->addr = mlx_get_data_addr(north->img, &(north->bits_per_pixel),
			&(north->line_length), &(north->endian));
	game->image_resized->north.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->north.addr = mlx_get_data_addr(game->image_resized->north.img,
			&game->image_resized->north.bits_per_pixel,
			&game->image_resized->north.line_length,
			&game->image_resized->north.endian);
	game->image_resized->north.width = 32;
	game->image_resized->north.height = 32;
}

void	ft_image_south(void *mlx, t_tex *south)
{
	t_game	*game;

	game = ft_get_game();
	south->img = mlx_xpm_file_to_image(mlx, south->path, &(south->width),
			&(south->height));
	south->addr = mlx_get_data_addr(south->img, &(south->bits_per_pixel),
			&(south->line_length), &(south->endian));
	game->image_resized->south.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->south.addr = mlx_get_data_addr(game->image_resized->south.img,
			&game->image_resized->south.bits_per_pixel,
			&game->image_resized->south.line_length,
			&game->image_resized->south.endian);
	game->image_resized->south.width = 32;
	game->image_resized->south.height = 32;
}

void	ft_image_east(void *mlx, t_tex *east)
{
	t_game	*game;

	game = ft_get_game();
	east->img = mlx_xpm_file_to_image(mlx, east->path, &(east->width),
			&(east->height));
	east->addr = mlx_get_data_addr(east->img, &(east->bits_per_pixel),
			&(east->line_length), &(east->endian));
	game->image_resized->east.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->east.addr = mlx_get_data_addr(game->image_resized->east.img,
			&game->image_resized->east.bits_per_pixel,
			&game->image_resized->east.line_length,
			&game->image_resized->east.endian);
	game->image_resized->east.width = 32;
	game->image_resized->east.height = 32;
}

void	ft_image_west(void *mlx, t_tex *west)
{
	t_game	*game;

	game = ft_get_game();
	west->img = mlx_xpm_file_to_image(mlx, west->path, &(west->width),
			&(west->height));
	west->addr = mlx_get_data_addr(west->img, &(west->bits_per_pixel),
			&(west->line_length), &(west->endian));
	game->image_resized->west.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->west.addr = mlx_get_data_addr(game->image_resized->west.img,
			&game->image_resized->west.bits_per_pixel,
			&game->image_resized->west.line_length,
			&game->image_resized->west.endian);
	game->image_resized->west.width = 32;
	game->image_resized->west.height = 32;
}
