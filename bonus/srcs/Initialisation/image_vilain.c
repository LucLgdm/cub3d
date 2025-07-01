/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_vilain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:02 by lde-merc          #+#    #+#             */
/*   Updated: 2025/07/01 15:46:20 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_image_vilain(void *mlx, t_tex *vilain)
{
	t_game	*game;

	game = ft_get_game();
	vilain->img = mlx_xpm_file_to_image(mlx, vilain->path, &(vilain->width),
			&(vilain->height));
	if (!vilain->img)
		ft_print_error_and_exit("Vilain image failed\n");
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

void	ft_image_vilain_2(void *mlx, t_tex *vilain)
{
	t_game	*game;

	game = ft_get_game();
	vilain->img = mlx_xpm_file_to_image(mlx, vilain->path, &(vilain->width),
			&(vilain->height));
	if (!vilain->img)
		ft_print_error_and_exit("Vilain_2 image failed\n");
	vilain->addr = mlx_get_data_addr(vilain->img, &(vilain->bits_per_pixel),
			&(vilain->line_length), &(vilain->endian));
	game->image_resized->vilain_2.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->vilain_2.addr = mlx_get_data_addr(
			game->image_resized->vilain_2.img,
			&game->image_resized->vilain_2.bits_per_pixel,
			&game->image_resized->vilain_2.line_length,
			&game->image_resized->vilain_2.endian);
	game->image_resized->vilain_2.width = 32;
	game->image_resized->vilain_2.height = 32;
}

void	ft_image_vilain_3(void *mlx, t_tex *vilain)
{
	t_game	*game;

	game = ft_get_game();
	vilain->img = mlx_xpm_file_to_image(mlx, vilain->path, &(vilain->width),
			&(vilain->height));
	if (!vilain->img)
		ft_print_error_and_exit("Vilain_2 image failed\n");
	vilain->addr = mlx_get_data_addr(vilain->img, &(vilain->bits_per_pixel),
			&(vilain->line_length), &(vilain->endian));
	game->image_resized->vilain_3.img = mlx_new_image(mlx, 32, 32);
	game->image_resized->vilain_3.addr = mlx_get_data_addr(
			game->image_resized->vilain_3.img,
			&game->image_resized->vilain_3.bits_per_pixel,
			&game->image_resized->vilain_3.line_length,
			&game->image_resized->vilain_3.endian);
	game->image_resized->vilain_3.width = 32;
	game->image_resized->vilain_3.height = 32;
}
