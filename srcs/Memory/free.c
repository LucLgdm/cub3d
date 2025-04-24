/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:43:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/24 11:37:08 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_game(t_game *game)
{
	ft_free_mlx(game);
	ft_free_image(game);
	ft_free_map(game);
}
void	ft_free_mlx(t_game *game)
{
	// if (game->win)
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	// }
}

void	ft_free_image(t_game *game)
{
	if (game->image)
	{
		// mlx_destroy_image(game->mlx, game->image);
		free(game->image);
	}
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height_w)
		{
			if (game->map[i])
				free(game->map[i]);
		}
		free(game->map);
	}
}
