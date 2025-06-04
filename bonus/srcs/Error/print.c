/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:56:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/04 09:29:18 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_game(void)
{
	t_game	*game;

	printf("ft_print_game\n");
	game = ft_get_game();
	printf("Game: %p\n", game);
	printf("Mlx: %p\n", game->mlx->mlx);
	printf("Win: %p\n", game->mlx->win);
	printf("Map: %p\n", game->map);
	printf("Image: %p\n", game->image);
	printf("Height_w: %d\n", game->height_w);
	printf("Width_w: %d\n", game->width_w);
	printf("Player_x: %f\n", game->player->pos.x);
	printf("Player_y: %f\n", game->player->pos.y);
	printf("Player_dir: %c\n", game->player->direction);
	printf("\n");
}

void	ft_print_image(void)
{
	t_game	*game;

	printf("ft_print_image\n");
	game = ft_get_game();
	printf("Path south: %s\n", game->image->south.path);
	printf("Path east: %s\n", game->image->east.path);
	printf("Path north: %s\n", game->image->north.path);
	printf("Path west: %s\n", game->image->west.path);
	printf("Path floor: %s\n", game->image->floor.path);
	printf("Path ceiling: %s\n", game->image->ceiling.path);
	printf("\n");
}

void	ft_print_map(void)
{
	t_game	*game;
	int		i;

	game = ft_get_game();
	printf("ft_print_map\n");
	printf("height: %d\n", game->map->height);
	printf("width : %d\n", game->map->width);
	i = -1;
	while (++i < game->map->height)
		printf("%s\n", game->map->map[i]);
}

void	ft_print_teleporter()
{
	int i = -1;
	t_position *teleport;

	teleport = ft_get_game()->map->teleporters;
	
	printf("ft_print_teleporter\n");
	while (++i < ft_get_game()->map->num_teleporters)
	{
		printf("Teleporter %d: x = %.2f, y = %.2f\n", i,
			teleport[i].x, teleport[i].y);
	}
}

void	ft_print_doors()
{
	int i = -1;
	t_door *doors;

	doors = ft_get_game()->map->doors;
	printf("ft_print_doors\n");
	while (++i < ft_get_game()->map->num_doors)
	{
		printf("Door %d: x = %d, y = %d, is_open = %s\n", i,
			doors[i].x, doors[i].y, doors[i].is_open ? "true" : "false");
	}
}