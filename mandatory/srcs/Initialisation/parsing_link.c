/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:42:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 12:24:50 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_get_info(int fd)
{
	char	*line;
	int		counter;

	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_is_link(line) || ft_is_color(line))
		{
			counter++;
			if (ft_is_link(line))
				ft_fill_link(line, fd);
			else
				ft_fill_color(line, fd);
		}
		else if (ft_strncmp(line, "\n", 2) != 0)
		{
			if (counter != 6)
				ft_exit_parsing(fd, line, "Error\nToo much or few info\n");
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	ft_fill_link(char *line, int fd)
{
	t_game	*game;

	game = ft_get_game();
	line[ft_strlen(line) - 1] = '\0';
	if (ft_strncmp(line + 3, "./", 2) != 0)
		ft_exit_parsing(fd, line, "Error\nPath must start with './'\n");
	if (line[0] == 'N' && !game->image->north.path)
		game->image->north.path = ft_strdup(line + 3);
	else if (line[0] == 'S' && !game->image->south.path)
		game->image->south.path = ft_strdup(line + 3);
	else if (line[0] == 'W' && !game->image->west.path)
		game->image->west.path = ft_strdup(line + 3);
	else if (line[0] == 'E' && !game->image->east.path)
		game->image->east.path = ft_strdup(line + 3);
	else
		ft_exit_parsing(fd, line, "Error\nToo much texture\n");
}

bool	ft_is_link(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}
