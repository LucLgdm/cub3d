/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 12:32:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}			t_map;

#endif