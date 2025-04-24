/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/24 15:01:22 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
}	t_map;


#endif