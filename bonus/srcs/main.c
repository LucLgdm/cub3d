/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/07/01 07:55:17 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

void	ft_loop_mlx(t_game *game)
{
	mlx_hook(game->mlx->win, 17, 1L << 19, ft_close_window, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, ft_key_pressed, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, ft_key_release, game);
	mlx_hook(game->mlx->win, 6, 1L << 6, ft_mouse_handle, game);
	mlx_loop_hook(game->mlx->mlx, ft_game_loop, game);
	mlx_loop(game->mlx->mlx);
}

void	ft_game(void)
{
	t_game	*game;
	t_mlx	*mlx;

	game = ft_get_game();
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		ft_print_error_and_exit("Error\nAllocation failed\n");
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_print_error_and_exit("Error\nAllocationion mlx failed\n");
	mlx_get_screen_size(mlx->mlx, &game->width_w, &game->height_w);
	mlx->win = mlx_new_window(mlx->mlx, game->width_w, game->height_w, "cub3D");
	mlx->img = mlx_new_image(mlx->mlx, game->width_w, game->height_w);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	game->mlx = mlx;
	game->zbuffer = ft_calloc(game->width_w, sizeof(double));
	if (!game->zbuffer)
		ft_print_error_and_exit("Error malloc zbuffer\n");
	game->mlx = mlx;
	ft_image_generator(game);
	ft_resize_all_images(game->image, game->image_resized);
	ft_display(game);
	ft_loop_mlx(game);
}

int	main(int argc, char **argv)
{
	ft_game_initialisation(argc, argv);
	ft_game();
	return (0);
}
