/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:42:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/22 15:56:13 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_info(int fd)
{
	char *line;
	int counter = 0;

	line = get_next_line(fd);
	while(line){
		if (ft_is_link(line) || ft_is_color(line)){
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
			break;
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
	if (line[0] == 'N' && !game->image->wall_N)
		game->image->wall_N = ft_strdup(line + 3);
	else if (line[0] == 'S'&& !game->image->wall_S)
		game->image->wall_S = ft_strdup(line + 3);
	else if (line[0] == 'W'&& !game->image->wall_W)
		game->image->wall_W = ft_strdup(line + 3);
	else if (line[0] == 'E'&& !game->image->wall_E)
		game->image->wall_E = ft_strdup(line + 3);
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