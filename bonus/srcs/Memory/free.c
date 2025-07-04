/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:43:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/07/01 08:45:51 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_game(t_game *game)
{
	ft_free_image(game);
	ft_free_map(game->map);
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
		free(game->mlx);
	}
	if (game->player)
		free(game->player);
	if (game->raycasting)
		free(game->raycasting);
	if (game->buttons)
		free(game->buttons);
	if (game->mini_map)
		free(game->mini_map);
	if (game->zbuffer)
		free(game->zbuffer);
}

void	ft_free_image(t_game *game)
{
	if (game->image && game->image)
	{
		if (game->mlx)
			ft_destroy_image(game);
		free(game->image->north.path);
		free(game->image->south.path);
		free(game->image->east.path);
		free(game->image->west.path);
		free(game->image->doors.path);
		free(game->image->vilain.path);
		free(game->image->vilain_2.path);
		free(game->image->vilain_3.path);
		free(game->image_resized);
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
	if (map->teleporters)
		free(map->teleporters);
	if (map->doors)
		free(map->doors);
	if (map->line_lengths)
		free(map->line_lengths);
	if (map->enemy)
		free(map->enemy);
	free(map);
}

void	ft_destroy_image(t_game *game)
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
	if (game->image->doors.img)
		mlx_destroy_image(game->mlx->mlx, game->image->doors.img);
	if (game->image->vilain.img)
		mlx_destroy_image(game->mlx->mlx, game->image->vilain.img);
	if (game->image->vilain_2.img)
		mlx_destroy_image(game->mlx->mlx, game->image->vilain_2.img);
	if (game->image->vilain_3.img)
		mlx_destroy_image(game->mlx->mlx, game->image->vilain_3.img);
	ft_destroy_resized_image(game);
}

void	ft_destroy_resized_image(t_game *game)
{
	if (game->image_resized->north.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->north.img);
	if (game->image_resized->south.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->south.img);
	if (game->image_resized->west.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->west.img);
	if (game->image_resized->east.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->east.img);
	if (game->image_resized->doors.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->doors.img);
	if (game->image_resized->vilain.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->vilain.img);
	if (game->image->vilain_2.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->vilain_2.img);
	if (game->image_resized->vilain_3.img)
		mlx_destroy_image(game->mlx->mlx, game->image_resized->vilain_3.img);
}
