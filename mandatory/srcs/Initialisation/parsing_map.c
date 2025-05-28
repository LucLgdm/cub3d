/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:21 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 12:24:50 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_map(t_game *game, int fd, char *line)
{
	while (line && ft_strncmp(line, "\n", 2))
	{
		if (game->map->height == 0)
		{
			game->map->map = ft_calloc(game->map->height + 2, sizeof(char *));
			if (!game->map->map)
				ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_new_line(fd, line, game);
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	while (line && ft_strncmp(line, "\n", 2) == 0)
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
	while (++i < game->map->height)
		game->map->map[i] = tmp[i];
	game->map->map[i] = ft_strdup(line);
	if (!game->map->map[i])
		ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
	free(tmp);
}

void	ft_check_map(t_game *game)
{
	t_map	*transposed_map;
	int		res;

	res = ft_check_border(game->map);
	if (res == 1)
		ft_print_error_and_exit("Error\nMap not closed\n");
	else if (res == 2)
		ft_print_error_and_exit("Error\nInvalid character in map\n");
	transposed_map = ft_calloc(1, sizeof(t_map));
	if (!transposed_map)
		ft_print_error_and_exit("Error malloc ft_check_map\n");
	transposed_map->map = ft_transpose_tab(game->map->map);
	if (!transposed_map->map)
	{
		free(transposed_map);
		ft_print_error_and_exit("Error malloc ft_check_map\n");
	}
	transposed_map->height = game->map->width;
	transposed_map->width = game->map->height;
	res = ft_check_border(transposed_map);
	ft_free_map(transposed_map);
	if (res == 1)
		ft_print_error_and_exit("Error\nMap not closed\n");
	else if (res == 2)
		ft_print_error_and_exit("Error\nInvalid character in map\n");
}

int	ft_check_border(t_map *map)
{
	int	i;
	int	res;

	i = -1;
	while (map->map[++i])
	{
		if (map->width < (int)ft_strlen(map->map[i]))
			map->width = (int)ft_strlen(map->map[i]);
		res = ft_check_wall(map->map[i]);
		if (res)
			return (1);
		res = ft_check_content(map->map[i], i);
		if (res)
			return (2);
	}
	return (0);
}
