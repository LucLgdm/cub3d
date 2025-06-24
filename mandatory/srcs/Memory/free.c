/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:43:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/24 15:16:16 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_game(t_game *game)
{
	ft_free_image(game);
	ft_free_mlx(game->mlx);
	ft_free_map(game->map);
	if (game->player)
		free(game->player);
}

static void	ft_destroy_image(t_game *game)
{
	if (game->mlx->img)
		mlx_destroy_image(game->mlx->mlx, game->mlx->img);
	if (game->image->north.img)
		mlx_destroy_image(game->mlx->mlx, game->image->north.img);
	if (game->image->south.img)
		mlx_destroy_image(game->mlx->mlx, game->image->south.img);
	if (game->image->west.img)
		mlx_destroy_image(game->mlx->mlx, game->image->west.img);
	if (game->image->east.img)
		mlx_destroy_image(game->mlx->mlx, game->image->east.img);
	if (game->image_resized->north.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->north.img);
	if (game->image_resized->south.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->south.img);
	if (game->image_resized->west.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->west.img);
	if (game->image_resized->east.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->east.img);
}

void	ft_free_image(t_game *game)
{
	if (game->image && game->image_resized)
	{
		if (game->mlx)
			ft_destroy_image(game);
		free(game->image->north.path);
		free(game->image->south.path);
		free(game->image->east.path);
		free(game->image->west.path);
		free(game->image);
		free(game->image_resized);
	}
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free(mlx);
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
}
