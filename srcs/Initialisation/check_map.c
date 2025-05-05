/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:04:54 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/02 16:47:41 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_wall(char *line)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_strlen(line);
	if ((line[0] != '1' && line[0] != ' ') || (line[size - 1] != '1' && line[size - 1] != ' '))
	{
		free(line);
		ft_print_error_and_exit("Error\nInvalid line\n");
	}
	while(++i < size - 2)
	{
		if (line[i] == ' ' && (!((line[i -1]) == ' ' || line[i - 1] == '1')
				|| !(line[i + 1] == ' ' || line[i + 1] == '1')))
		{
			free(line);
			ft_print_error_and_exit("Error\nInvalid charatere in line\n");
		}
	}
}

void	ft_check_content(char *line)
{
	int		j;
	int		size;
	// t_game	*game;

	j = -1;
	size = ft_strlen(line);
	// game = ft_get_game();
	while(++j < size && ft_is_good_char(line[j]))
		// if(line[j] != '0' && line[j] != '1'){
		
		// }
		;
	if (j != size)
		ft_print_error_and_exit("Error\nInvalid character in map\n");
}

bool	ft_is_good_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W' || c == ' ');
}
