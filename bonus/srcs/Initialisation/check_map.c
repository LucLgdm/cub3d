/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:04:54 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/06 15:56:33 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(char *line, int size)
{
	int	i;

	i = 0;
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

static void	ft_d_t(char c, int i, int j)
{
	t_game	*game;

	game = ft_get_game();
	if (c == 'D')
		ft_fill_door(i, j, game);
	if (c == 'T')
		ft_fill_teleporter(i, j, game);
}

int	ft_check_content(char *line, int i, int size)
{
	int		j;
	t_game	*game;

	j = -1;
	game = ft_get_game();
	while (++j < size && ft_is_good_char(line[j]))
	{
		ft_d_t(line[j], i, j);
		if (line[j] != '0' && line[j] != '1' && line[j] != ' ' && line[j] != 'D'
			&& line[j] != 'T' && !game->player)
		{
			ft_fill_player(line[j], i, j, game);
			line[j] = '0';
		}
		else if (line[j] != '0' && line[j] != '1' && line[j] != ' '
			&& line[j] != 'D' && line[j] != 'T' && game->player)
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
		|| c == ' ' || c == 'D' || c == 'T');
}
