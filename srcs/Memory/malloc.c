/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:36:24 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/25 16:07:05 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_malloc_game(t_game *game)
{
	ft_malloc_image(game);
	ft_malloc_map(game);
}

void	ft_malloc_mlx(t_game *game)
{
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->width_w, &game->height_w);
	game->win = mlx_new_window(game->mlx, game->width_w, game->height_w, "cub3D");
}

void	ft_malloc_image(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if (!game->image)
	{
		fprintf(stderr, "Error malloc image: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void 	ft_malloc_map(t_game *game)
{
	int	i;

	i = -1;
	game->map = ft_calloc(game->height_w + 1, sizeof(char *));
	if (!game->map)
	{
		fprintf(stderr, "Error malloc map: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	game->map->map[game->height_w] = NULL;
	while(++i < game->height_w)
	{
		game->map->map[i] = ft_calloc(game->width_w + 1, sizeof(char));
		if (!game->map->map[i])
		{
			fprintf(stderr, "Error malloc map line: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		game->map->map[i][game->width_w] = '\0';
	}
}
