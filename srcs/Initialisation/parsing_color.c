/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:44:36 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/27 12:14:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_game_color(char *line, t_color *color)
{
	t_game	*game;

	game = ft_get_game();
	if (line[0] == 'F')
		ft_get_game()->image->floor.value = color->value;
	else if (line[0] == 'C')
		ft_get_game()->image->ceiling.value = color->value;
}

char	**ft_fill_color_2(char *line, int fd)
{
	char	**splited;

	splited = ft_split(line + 2, ',');
	if (!splited)
		ft_exit_parsing(fd, line, "Error\nMemory allocation failed\n");
	if (ft_arraylen(splited) != 3)
	{
		ft_free_array(splited);
		ft_exit_parsing(fd, line, "Error\nProblem with the color\n");
	}
	return (splited);
}

void	ft_fill_color(char *line, int fd)
{
	t_color	color;
	int		i;
	char	**splited;

	splited = ft_fill_color_2(line, fd);
	color.value = 0;
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(splited[i]) < 0 || ft_atoi(splited[i]) > 255)
		{
			ft_free_array(splited);
			ft_exit_parsing(fd, line, "Error\nProblem with the color\n");
		}
		if (i == 0)
			color.s_channel.r = ft_atoi(splited[i]);
		else if (i == 1)
			color.s_channel.g = ft_atoi(splited[i]);
		else if (i == 2)
			color.s_channel.b = ft_atoi(splited[i]);
	}
	ft_fill_game_color(line, &color);
	ft_free_array(splited);
}

bool	ft_is_color(char *line)
{
	if (ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "F ", 2) == 0)
		return (true);
	return (false);
}
