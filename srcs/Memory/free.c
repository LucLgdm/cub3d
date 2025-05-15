/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:43:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/15 14:45:21 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_free_game(t_game *game)
{
	ft_free_image(game);
	// free(game->mlx->mlx);
	// free(game->mlx);
	ft_free_map(game->map);
	ft_free_player(game->player);
	// free(game);
}

void	ft_free_image(t_game *game)
{
	if (game->image)
	{
		free(game->image->wall_N);
		free(game->image->wall_S);
		free(game->image->wall_E);
		free(game->image->wall_W);
		free(game->image);
	}
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	if (!map || !map->map)
		return ;
	while (map->map[++i])
	{
		free(map->map[i]);
		map->height--;
	}
	free(map->map[i]);
	free(map->map);
	free(map);
	map = NULL;
}

void	ft_free_player(t_player *player)
{
	if (player)
		free(player);
}
