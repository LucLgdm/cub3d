/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/26 11:52:29 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_game *game, char **argv){
	int	fd;

	printf("ft_parsing game address: %p\n", game);
	ft_malloc_image(game);
	if(!game->image)
		ft_print_error_and_exit("Error: Memory allocation for image failed\n");
	// ft_malloc_map(game);
	fd = open(argv[1], O_RDONLY);
	ft_get_link_image(game, fd);
	// ft_map_initialisation(game, fd);
}

void ft_get_link_image(t_game *game, int fd){
	char *line;
	
	line = get_next_line(fd);
	while (line)
	{
		if(ft_is_link(line))
			ft_fill_link(game, line);
		else if(ft_strncmp(line, "\n", 1) == 0)
			;
		else
		{
			free(line);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
}

bool	ft_is_link(char *line){
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 ||
		ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

void	ft_fill_link(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->image->wall_N = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->image->wall_S = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->image->wall_W = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->image->wall_E = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->image->floor = ft_strdup(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->image->ceiling = ft_strdup(line + 2);
}
