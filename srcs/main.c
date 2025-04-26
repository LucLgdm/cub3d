/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/26 12:00:05 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

int main(int argc, char **argv){
	// t_game	*game;

	ft_game_initialisation(argc, argv);
	// game = ft_get_game();
	ft_print_game();
	ft_print_image();
	// game->mlx = mlx_init();
	// mlx_get_screen_size(game->mlx, &game->width_w, &game->height_w);
	// game->win = mlx_new_window(game->mlx, game->width_w, game->height_w, "cub3D");
	ft_free_game(ft_get_game());
	return (0);	
}