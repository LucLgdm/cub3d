/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:40 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/23 14:20:24 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parsing(t_game *game, char **argv)
{
	int		fd;
	char	*line;

	ft_malloc_image(game);
	if (!game->image)
		ft_print_error_and_exit("Error: Memory allocation for image failed\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_print_error_and_exit("Error: File doesn't exist !\n");
	line = ft_get_info(fd);
	if (!line)
	{
		free(line);
		ft_print_error_and_exit("Error: No map in file\n");
	}
	ft_malloc_map(game);
	if (!game->map)
		ft_print_error_and_exit("Error: Memory allocation for map failed\n");
	ft_get_map(game, fd, line);
	ft_check_map(game);
}
