/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:04:54 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/02 09:16:28 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_wall(char *line){}

void	ft_check_content(char *line, int i)
{
	int	j;
	int	size;

	j = -1;
	size = ft_strlen(line);
	while(++j < size && ft_is_good_char(line[j]))
		// if(line[j] != '0' && line[j] != '1'){
		
		// }
		;
	if (j != size)
		ft_print_error_and_exit("Error\nInvalid character in map");
}

bool	ft_is_good_char(char c)
{
	return (c == 1 || c == 0 || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}