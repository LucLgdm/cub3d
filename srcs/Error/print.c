/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:56:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/05 10:35:27 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_game(void)
{
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

void	ft_print_image(void)
{
	t_game	*game;

	printf("ft_print_image\n");
	game = ft_get_game();
	printf("Wall_N: %s\n", (char *)game->image->wall_N);
	printf("Wall_S: %s\n", (char *)game->image->wall_S);
	printf("Wall_E: %s\n", (char *)game->image->wall_E);
	printf("Wall_W: %s\n", (char *)game->image->wall_W);
	printf("Floor: %i\n", game->image->floor.value);
	printf("  red  : %i\n", game->image->floor.s_channel.r);
	printf("  green: %i\n", game->image->floor.s_channel.g);
	printf("  blue : %i\n", game->image->floor.s_channel.b);
	printf("Ceiling: %i\n", game->image->ceiling.value);
	printf("  red    : %i\n", game->image->ceiling.s_channel.r);
	printf("  green  : %i\n", game->image->ceiling.s_channel.g);
	printf("  blue   : %i\n", game->image->ceiling.s_channel.b);
	printf("\n");
}

void	ft_print_map(void)
{
	t_game	*game;
	int		i;

	printf("ft_print_map\n");
	game = ft_get_game();
	i = -1;
	while (++i < game->map->height)
		printf("%s\n", game->map->map[i]);
}
