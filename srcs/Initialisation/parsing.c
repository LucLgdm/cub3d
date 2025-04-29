/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 11:38:13 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_game *game, char **argv){
	int	fd;
	char	*line;
	
	ft_malloc_image(game);
	if(!game->image)
		ft_print_error_and_exit("Error: Memory allocation for image failed\n");
	ft_malloc_map(game);
	if(!game->map)
		ft_print_error_and_exit("Error: Memory allocation for map failed\n");
	fd = open(argv[1], O_RDONLY);
	line = ft_get_link_image(fd);
	line = ft_get_color(fd, line);
	// ft_map_initialisation(game, fd, line);
	free(line);
}

