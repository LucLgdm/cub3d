/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:44:36 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 15:38:09 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_color(int fd, char *line)
{
	char	**splitted;
	int		counter;

	counter = 0;
	if (line[0] != 'F' && line[0] != 'C')
		ft_exit_parsing(fd, line, "Error\nColor doesn't exist or at the wrong place\n");
	while(1)
	{
		if (line[0] == 'F' || line[0] == 'C')
		{
			counter++;
			splitted = ft_split(line + 2, ',');
			if (!splitted)
				ft_exit_parsing(fd, line, "Error\nMemory allocation failed\n");
			if (!ft_fill_color(line[0], splitted))
				ft_exit_parsing(fd, line, "Error\nInvalid color format\n");
		}
		else if(ft_strncmp(line, "\n", 1) != 0)
		{
			if(counter != 2)
				ft_exit_parsing(fd, line, "Error\nMissing, too much color\n");
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

bool	ft_fill_color(char c, char **splitted)
{
	int		i;
	t_color	color;
	
	i = -1;
	if (ft_arraylen(splitted) != 3)
		return (ft_free_array(splitted), false);
	color.value = 0;
	while (++i < 3)
	{
		if (ft_isdigit(splitted[i][0]) == 0)
			return (ft_free_array(splitted), false);
		if (ft_atoi(splitted[i]) < 0 || ft_atoi(splitted[i]) > 255)
			return (ft_free_array(splitted), false);
		if (i == 0)
			color.s_channel.r = ft_atoi(splitted[i]);
		else if (i == 1)
			color.s_channel.g = ft_atoi(splitted[i]);
		else if (i == 2)
			color.s_channel.b = ft_atoi(splitted[i]);
	}
	if (c == 'F')
		ft_get_game()->image->floor.value = color.value;
	else if (c == 'C')
		ft_get_game()->image->ceiling.value = color.value;
	return (ft_free_array(splitted), true);
}
