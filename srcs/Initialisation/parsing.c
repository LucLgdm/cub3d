/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 10:38:35 by luclgdm          ###   ########.fr       */
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
	// ft_map_initialisation(game, fd, line);
	free(line);
}

char	*ft_get_link_image(int fd){
	char	*line;
	int		counter;
	
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if(ft_is_link(line))
		{
			line[ft_strlen(line) - 1] = '\0';
			ft_fill_link(line, &counter);
		}
		else if(ft_strncmp(line, "\n", 1) != 0)
		{
			if (counter != 6)
			{
				ft_putstr_fd("Error\nMissing, dopple,", 2);
				ft_print_error_and_exit(" invalid character link image\n");
				return (free(line), NULL);
			}
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

bool	ft_is_link(char *line){
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 ||
		ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

void	ft_fill_link(char *line, int *counter)
{
	(*counter)++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		ft_check_path(line, 3, 'N');
	else if (ft_strncmp(line, "SO ", 3) == 0)
		ft_check_path(line, 3, 'S');
	else if (ft_strncmp(line, "WE ", 3) == 0)
		ft_check_path(line, 3, 'W');
	else if (ft_strncmp(line, "EA ", 3) == 0)
		ft_check_path(line, 3, 'E');
	else if (ft_strncmp(line, "F ", 2) == 0)
		ft_check_path(line, 2, 'F');
	else if (ft_strncmp(line, "C ", 2) == 0)
		ft_check_path(line, 2, 'C');
	else
		(*counter)--;
}

void	ft_check_path(char *line, int start, char c)
{
	t_game	*game;

	game = ft_get_game();
	if (start != 2 && ft_strncmp(line + start, "./", 2) != 0)
		ft_print_error_and_exit("Error\nPath must start with './'\n");
	if (c == 'N')
		game->image->wall_N = ft_strdup(line + 3);
	else if (c == 'S')
		game->image->wall_S = ft_strdup(line + 3);
	else if (c == 'W')
		game->image->wall_W = ft_strdup(line + 3);
	else if (c == 'E')
		game->image->wall_E = ft_strdup(line + 3);
	else if (c == 'F')
		game->image->floor = ft_strdup(line + 2);
	else if (c == 'C')
		game->image->ceiling = ft_strdup(line + 2);
	else
		ft_print_error_and_exit("Error\nInvalid path\n");
}
