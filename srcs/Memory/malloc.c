/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:24 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/06 16:21:05 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_malloc_game(t_game *game)
{
	ft_malloc_image(game);
	ft_malloc_map(game);
}

// void	ft_malloc_mlx(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	mlx_get_screen_size(game->mlx, &game->width_w, &game->height_w);
// 	game->win = mlx_new_window(game->mlx, game->width_w, game->height_w,
// 			"cub3D");
// }

void	ft_malloc_image(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if (!game->image)
	{
		fprintf(stderr, "Error malloc image: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	ft_malloc_map(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_print_error_and_exit("Error malloc t_map\n");
	game->map->height = 0;
	game->map->width = 0;
}
