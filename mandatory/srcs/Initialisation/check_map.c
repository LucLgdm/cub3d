/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:04:54 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/16 17:16:14 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line);
	if ((line[0] != '1' && line[0] != ' ') || (line[size - 1] != '1'
			&& line[size - 1] != ' '))
		return (1);
	while (++i < size - 2)
	{
		if (line[i] == ' ' && (!((line[i - 1]) == ' ' || line[i - 1] == '1')
				|| !(line[i + 1] == ' ' || line[i + 1] == '1')))
			return (1);
	}
	return (0);
}

int	ft_check_content(char *line, int i)
{
	int		j;
	int		size;
	t_game	*game;

	j = -1;
	size = ft_strlen(line);
	game = ft_get_game();
	while (++j < size && ft_is_good_char(line[j]))
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != ' ' && !game->player)
		{
			ft_fill_player(line[j], i, j, game);
			line[j] = '0';
		}
		else if (line[j] != '0' && line[j] != '1' && line[j] != ' '
			&& game->player)
			return (1);
		continue ;
	}
	if (j != size)
		return (1);
	return (0);
}

bool	ft_is_good_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

void	ft_fill_player(char c, int i, int j, t_game *game)
{
	if (!game->player)
	{
		game->player = ft_calloc(1, sizeof(t_player));
		if (!game->player)
			ft_print_error_and_exit("Error: Memory allocation player failed\n");
	}
	game->player->pos.x = (double)j;
	game->player->pos.y = (double)i;
	game->player->pos.x = T_SIZE * game->player->pos.x + T_SIZE / 2;
	game->player->pos.y = T_SIZE * game->player->pos.y + T_SIZE / 2;
	game->player->direction = c;
}
