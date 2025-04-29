/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:42:12 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 15:20:11 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (counter != 4)
			{
				ft_putstr_fd("Error\nMissing, too much,", 2);
				ft_exit_parsing(fd, line, " or invalid link\n");
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
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

void	ft_fill_link(char *line, int *counter)
{
	t_game	*game;

	game = ft_get_game();
	(*counter)++;
	if (ft_strncmp(line + 3, "./", 2) != 0)
		ft_print_error_and_exit("Error\nPath must start with './'\n");
	if (line[0] == 'N')
		game->image->wall_N = ft_strdup(line + 3);
	else if (line[0] == 'S')
		game->image->wall_S = ft_strdup(line + 3);
	else if (line[0] == 'W')
		game->image->wall_W = ft_strdup(line + 3);
	else if (line[0] == 'E')
		game->image->wall_E = ft_strdup(line + 3);
	else
		ft_print_error_and_exit("Error\nInvalid path\n");
}

