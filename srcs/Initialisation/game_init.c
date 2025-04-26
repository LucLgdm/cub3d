/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:27:09 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/26 11:51:58 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_initialisation(int argc, char **argv){
	t_game	*game;
	int		size;

	if (argc != 2)
		ft_print_error_and_exit("Usage: ./cub3D <map.cub>\n");
	size = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + size - 4, ".cub", 4) != 0)
		ft_print_error_and_exit("Error: Invalid file extension: .cub\n");
	game = ft_get_game();
	printf("ft_game_initialisation game address: %p\n", game);
	ft_parsing(game, argv);
}

