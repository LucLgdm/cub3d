/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:23:13 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/05 10:35:23 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_image_doors(void *mlx, t_tex *doors)
{
	t_game	*game;

	game = ft_get_game();
	doors->img = mlx_xpm_file_to_image(mlx, doors->path, &(doors->width),
			&(doors->height));
	doors->addr = mlx_get_data_addr(doors->img, &(doors->bits_per_pixel),
			&(doors->line_length), &(doors->endian));
	game->image_resized->doors.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->doors.addr = mlx_get_data_addr(game->image_resized->doors.img,
			&game->image_resized->doors.bits_per_pixel,
			&game->image_resized->doors.line_length,
			&game->image_resized->doors.endian);
	game->image_resized->doors.width = 32;
	game->image_resized->doors.height = 32;
}

void	ft_image_floor(void *mlx, t_tex *floor)
{
	t_game	*game;

	game = ft_get_game();
	floor->img = mlx_xpm_file_to_image(mlx, floor->path, &(floor->width),
			&(floor->height));
	floor->addr = mlx_get_data_addr(floor->img, &(floor->bits_per_pixel),
			&(floor->line_length), &(floor->endian));
	game->image_resized->floor.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->floor.addr = mlx_get_data_addr(game->image_resized->floor.img,
			&game->image_resized->floor.bits_per_pixel,
			&game->image_resized->floor.line_length,
			&game->image_resized->floor.endian);
	game->image_resized->floor.width = 32;
	game->image_resized->floor.height = 32;
}

void	ft_image_ceiling(void *mlx, t_tex *ceiling)
{
	t_game	*game;

	game = ft_get_game();
	ceiling->img = mlx_xpm_file_to_image(mlx, ceiling->path, &(ceiling->width),
			&(ceiling->height));
	ceiling->addr = mlx_get_data_addr(ceiling->img, &(ceiling->bits_per_pixel),
			&(ceiling->line_length), &(ceiling->endian));
	game->image_resized->ceiling.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->ceiling.addr = mlx_get_data_addr(game->image_resized->ceiling.img,
			&game->image_resized->ceiling.bits_per_pixel,
			&game->image_resized->ceiling.line_length,
			&game->image_resized->ceiling.endian);
	game->image_resized->ceiling.width = 32;
	game->image_resized->ceiling.height = 32;
}
