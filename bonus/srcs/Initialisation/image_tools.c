/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:23:13 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/04 10:23:24 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_image_doors(void *mlx, t_tex *doors)
{
	doors->img = mlx_xpm_file_to_image(mlx, doors->path, &(doors->width),
			&(doors->height));
	doors->addr = mlx_get_data_addr(doors->img, &(doors->bits_per_pixel),
			&(doors->line_length), &(doors->endian));
}

void	ft_image_floor(void *mlx, t_tex *floor)
{
	floor->img = mlx_xpm_file_to_image(mlx, floor->path, &(floor->width),
			&(floor->height));
	floor->addr = mlx_get_data_addr(floor->img, &(floor->bits_per_pixel),
			&(floor->line_length), &(floor->endian));
}

void	ft_image_ceiling(void *mlx, t_tex *ceiling)
{
	ceiling->img = mlx_xpm_file_to_image(mlx, ceiling->path, &(ceiling->width),
			&(ceiling->height));
	ceiling->addr = mlx_get_data_addr(ceiling->img, &(ceiling->bits_per_pixel),
			&(ceiling->line_length), &(ceiling->endian));
}
