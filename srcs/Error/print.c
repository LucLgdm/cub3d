/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:56:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/28 14:14:05 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_print_game(){
	t_game	*game;

	printf("ft_print_game\n");
	game = ft_get_game();
	printf("Game: %p\n", game);
	printf("Mlx: %p\n", game->mlx);
	printf("Win: %p\n", game->win);
	printf("Map: %p\n", game->map);
	printf("Image: %p\n", game->image);
	printf("Height_w: %d\n", game->height_w);
	printf("Width_w: %d\n", game->width_w);
	printf("\n");
}

void ft_print_image(){
	t_game	*game;

	printf("ft_print_image\n");
	game = ft_get_game();
	printf("Wall_N: %s\n", (char *)game->image->wall_N);
	printf("Wall_S: %s\n", (char *)game->image->wall_S);
	printf("Wall_E: %s\n", (char *)game->image->wall_E);
	printf("Wall_W: %s\n", (char *)game->image->wall_W);
	printf("Floor: %s\n", (char *)game->image->floor);
	printf("Ceiling: %s\n", (char *)game->image->ceiling);
	printf("\n");
}

void	ft_print_map(){
	t_game	*game;
	int		i;

	printf("ft_print_map\n");
	game = ft_get_game();
	i = -1;
	while (++i < game->map->height)
	{
		printf("%s\n", game->map->map[i]);
	}
	printf("\n");
}
