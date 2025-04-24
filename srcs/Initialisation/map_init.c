/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:57:41 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/24 15:10:30 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_initialisation(t_game *game, int fd)
{
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_print_error_and_exit("Error: Memory allocation for map failed\n");
	game->map->map = (char **)ft_calloc(1, sizeof(char *));
	if (!game->map->map)
		ft_print_error_and_exit("Error: Memory allocation for map failed\n");
	game->map->height = 0;
}