/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:21 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/02 09:09:28 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_map(t_game *game, int fd, char *line)
{
	while(line && ft_strncmp(line, "\n", 2))
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
	while(line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		ft_exit_parsing(fd, line, "Error\nTo much element in file\n");
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

void ft_check_map(t_game *game)
{
	t_map	*transposed_map;
	
	transposed_map->map = ft_transpose_tab(game->map->map);
	transposed_map->height = game->map->width;
	transposed_map->width = game->map->height;
	ft_check_border(game->map);
	ft_check_border(transposed_map);
}

void	ft_check_border(t_map *map)
{
	int	i;

	i = -1;
	while(++i < map->height)
	{
		ft_check_wall(map->map[i]);
		ft_check_content(map->map[i], i);
	}
}
