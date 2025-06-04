/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/03 15:23:35 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "position.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>


typedef struct s_wall
{
	float	height;
	float	start;
	int		column_x;
	float	ty_step;
	float	ty_off;
}	t_wall;

typedef struct s_door
{
	int		x;
	int		y;
	bool	is_open;
}	t_door;


typedef struct s_player
{
	t_position	pos;
	char		direction;
	float		angle;
	float		dx;
	float		dy;
	float		velocity;
	float		base_velocity;
	float		rotation_speed;
	bool		can_teleport;
	bool		on_door;
}	t_player;


typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	t_position	*teleporters;
	int			num_teleporters;
	t_door		*doors;
	int			num_doors;
}	t_map;

#endif