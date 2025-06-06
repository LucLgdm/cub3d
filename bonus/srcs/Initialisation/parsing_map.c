/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:54:21 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/06 16:01:23 by lde-merc         ###   ########.fr       */
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
	int		*tmp_len;
	char	**tmp;

	tmp_len = game->map->line_lengths;
	tmp = game->map->map;
	game->map->line_lengths = ft_calloc(game->map->height + 2, sizeof(int));
	if (!game->map->line_lengths)
		ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
	game->map->map = ft_calloc(game->map->height + 2, sizeof(char *));
	if (!game->map->map)
		ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
	i = -1;
	while (++i < game->map->height)
	{
		game->map->line_lengths[i] = tmp_len[i];
		game->map->map[i] = tmp[i];
	}
	game->map->line_lengths[i] = ft_strlen(line);
	game->map->map[i] = ft_strdup(line);
	if (!game->map->map[i])
		ft_exit_parsing(fd, line, "Error\nAllocation map failed\n");
	free(tmp);
	free(tmp_len);
}

static t_map	*ft_init_transpose(t_game *game)
{
	t_map	*transposed_map;
	int		i;

	transposed_map = ft_calloc(1, sizeof(t_map));
	if (!transposed_map)
		ft_print_error_and_exit("Error malloc ft_check_map\n");
	transposed_map->map = ft_transpose_tab(game->map->map);
	if (!transposed_map->map)
	{
		ft_free_map(transposed_map);
		ft_print_error_and_exit("Error malloc ft_check_map\n");
	}
	transposed_map->height = game->map->width;
	transposed_map->width = game->map->height;
	transposed_map->line_lengths = ft_calloc(transposed_map->height + 2,
			sizeof(int));
	if (!transposed_map->line_lengths)
	{
		ft_free_map(transposed_map);
		ft_print_error_and_exit("Error malloc ft_check_map\n");
	}
	i = -1;
	while (++i < transposed_map->height)
		transposed_map->line_lengths[i] = ft_strlen(transposed_map->map[i]);
	return (transposed_map);
}

void	ft_check_map(t_game *game)
{
	t_map	*transposed_map;
	int		res;

	res = ft_check_border(game->map, true);
	if (res == 1)
		ft_print_error_and_exit("Error\nMap not closed\n");
	else if (res == 2)
		ft_print_error_and_exit("Error\nInvalid character in map\n");
	transposed_map = ft_init_transpose(game);
	res = ft_check_border(transposed_map, false);
	ft_free_map(transposed_map);
	if (res == 1)
		ft_print_error_and_exit("Error\nMap not closed\n");
	else if (res == 2)
		ft_print_error_and_exit("Error\nInvalid character in map\n");
}

int	ft_check_border(t_map *map, bool fill_struct)
{
	int	i;
	int	res;

	i = -1;
	while (map->map[++i])
	{
		if (map->width < map->line_lengths[i])
			map->width = map->line_lengths[i];
		res = ft_check_wall(map->map[i], map->line_lengths[i]);
		if (res)
			return (1);
		if (fill_struct)
		{
			res = ft_check_content(map->map[i], i, map->line_lengths[i]);
			if (res)
				return (2);
		}
	}
	return (0);
}
