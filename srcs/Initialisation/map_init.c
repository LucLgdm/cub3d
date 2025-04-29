/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:57:41 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/28 14:23:54 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_initialisation(t_game *game, int fd, char *line)
{	
	game->map->map = (char **)ft_calloc(1, sizeof(char *));
	if (!game->map->map)
		ft_print_error_and_exit("Error: Memory allocation for map failed\n");
	if (game->map->height == 0)
	{
		game->map->map[0] = ft_strdup(line);
		if (!game->map->map[0])
			ft_print_error_and_exit("Error: Memory allocation for map failed\n");
		game->map->height++;
		free(line);
	}
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		
	}
	
}
