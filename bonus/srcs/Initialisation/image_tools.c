/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:23:13 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 10:41:10 by lde-merc         ###   ########.fr       */
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
	game->image_resized->doors.addr = mlx_get_data_addr(
			game->image_resized->doors.img,
			&game->image_resized->doors.bits_per_pixel,
			&game->image_resized->doors.line_length,
			&game->image_resized->doors.endian);
	game->image_resized->doors.width = 32;
	game->image_resized->doors.height = 32;
}

void	ft_image_vilain(void *mlx, t_tex *vilain)
{
	t_game	*game;

	game = ft_get_game();
	vilain->img = mlx_xpm_file_to_image(mlx, vilain->path, &(vilain->width),
			&(vilain->height));
	vilain->addr = mlx_get_data_addr(vilain->img, &(vilain->bits_per_pixel),
			&(vilain->line_length), &(vilain->endian));
	game->image_resized->vilain.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->vilain.addr = mlx_get_data_addr(
			game->image_resized->vilain.img,
			&game->image_resized->vilain.bits_per_pixel,
			&game->image_resized->vilain.line_length,
			&game->image_resized->vilain.endian);
	game->image_resized->vilain.width = 32;
	game->image_resized->vilain.height = 32;
}

void	resize_tex(t_tex *src, t_tex *dst)
{
	t_position	index;
	t_position	src_pos;
	char		*src_pixel;
	char		*dst_pixel;
	int			b;

	index.y = -1;
	while (++index.y < dst->height)
	{
		index.x = -1;
		while (++index.x < dst->width)
		{
			src_pos.x = (int)index.x * src->width / dst->width;
			src_pos.y = (int)index.y * src->height / dst->height;
			src_pixel = src->addr + ((int)src_pos.y * src->line_length
					+ (int)src_pos.x * (src->bits_per_pixel / 8));
			dst_pixel = dst->addr + ((int)index.y * dst->line_length
					+ (int)index.x * (dst->bits_per_pixel / 8));
			b = -1;
			while (++b < dst->bits_per_pixel / 8)
				dst_pixel[b] = src_pixel[b];
		}
	}
}

void	ft_resize_all_images(t_image *source, t_image *dest)
{
	resize_tex(&source->north, &dest->north);
	resize_tex(&source->south, &dest->south);
	resize_tex(&source->east, &dest->east);
	resize_tex(&source->west, &dest->west);
	resize_tex(&source->doors, &dest->doors);
	resize_tex(&source->vilain, &dest->vilain);
}
