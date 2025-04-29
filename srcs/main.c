/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 15:31:50 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

int main(int argc, char **argv){
	t_game	*game;

	game = ft_get_game();
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->width_w, &game->height_w);
	game->win = mlx_new_window(game->mlx, game->width_w, game->height_w, "cub3D");
	ft_game_initialisation(argc, argv);
	
	ft_print_game();
	ft_print_image();
	ft_print_map();
	
	ft_free_game(game);
	return (0);	
}
