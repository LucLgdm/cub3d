/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/20 09:53:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

void	ft_game(int flag)
{
	t_game	*game;

	game = ft_get_game();
	game->correction = flag;
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!game->mlx)
		ft_print_error_and_exit("Error\nAllocation failed\n");
		
	game->mlx->mlx = mlx_init();
	mlx_get_screen_size(game->mlx->mlx, &game->width_w, &game->height_w);
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->width_w, game->height_w, "cub3D");

	game->mlx->img = mlx_new_image(game->mlx->mlx, game->width_w, game->height_w);
    game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);
	
	ft_display(game, flag);
	mlx_hook(game->mlx->win, 17, 1L << 19, ft_close_window, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, ft_key_handle, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, ft_key_release, game);
	mlx_loop_hook(game->mlx->mlx, ft_game_loop, game);
	mlx_loop(game->mlx->mlx);
}

int	main(int argc, char **argv)
{
	ft_game_initialisation(argc, argv);

	ft_game(1);

	return (0);
}
