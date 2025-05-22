/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:27:09 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/22 15:52:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_initialisation(int argc, char **argv)
{
	t_game	*game;
	int		size;

	if (argc != 2)
		ft_print_error_and_exit("Usage: ./cub3D <map.cub>\n");
	size = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + size - 4, ".cub", 4) != 0)
		ft_print_error_and_exit("Error\nInvalid file extension: .cub\n");
	game = ft_get_game();
	ft_parsing(game, argv);
	ft_check_player(game);
}

void	ft_check_player(t_game *game)
{
	if (!game->player)
		ft_print_error_and_exit("Error\nNo player found\n");
	if (game->player->direction == 'N')
		game->player->angle = 3 * PI / 2;
	else if (game->player->direction == 'S')
		game->player->angle = PI / 2;
	else if (game->player->direction == 'E')
		game->player->angle = 0;
	else if (game->player->direction == 'W')
		game->player->angle = PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
}
