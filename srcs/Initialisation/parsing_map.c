/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:21 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/30 11:24:50 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_map(t_game *game, int fd, char *line)
{
	while(line)
	{
		if (game->map->height == 0)
		{
			game->map->map = ft_calloc(game->map->height + 2, sizeof(char *));
			if (!game->map->map)
				ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
		}
		line[ft_strlen(line) - 1] = '\0';
		ft_new_line(fd, line, game);		
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
}

void	ft_new_line(int fd, char *line, t_game *game)
{
	int		i;
	char	**tmp;

	tmp = game->map->map;
	game->map->map = ft_calloc(game->map->height + 2, sizeof(char *));
	if (!game->map->map)
		ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
	i = -1;
	while(++i < game->map->height)
		game->map->map[i] = tmp[i];
	game->map->map[i] = ft_strdup(line);
	free(tmp);
}
