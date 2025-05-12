/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/12 13:35:29 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

static void	ft_game(void)
{
	t_game	*game;

	game = ft_get_game();
	
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!game->mlx)
		ft_print_error_and_exit("Error\nAllocation failed\n");
		
	game->mlx->mlx = mlx_init();
	mlx_get_screen_size(game->mlx->mlx, &game->width_w, &game->height_w);
	// game->width_w = 3 * game->width_w / 4;
	// game->height_w = 3 * game->height_w / 4;
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->width_w, game->height_w, "cub3D");

	game->mlx->img = mlx_new_image(game->mlx->mlx, game->width_w, game->height_w);
    game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);


	
	
	ft_display(game);
	mlx_hook(game->mlx->win, 17, 1L << 19, ft_close_window, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, ft_key_handle, game);
	mlx_loop(game->mlx->mlx);
}



int	main(int argc, char **argv)
{
	ft_game_initialisation(argc, argv);

	ft_game();

	return (0);
}
