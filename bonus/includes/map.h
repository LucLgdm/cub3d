/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/30 16:25:03 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "position.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

# define MINIMAP_RADIUS 80

typedef struct s_wall
{
	double		height;
	double		start;
	int			column_x;
	double		ty_step;
	double		ty_off;
}	t_wall;

typedef struct s_door
{
	int			x;
	int			y;
	bool		is_open;
}	t_door;

typedef struct s_enemy
{
	t_position	pos;
	t_position	dxdy;
	double		speed;
}	t_enemy;

typedef struct s_player
{
	t_position	pos;
	char		direction;
	double		angle;
	double		dx;
	double		dy;
	double		velocity;
	double		base_velocity;
	double		rotation_speed;
	bool		can_teleport;
	bool		on_door;
}	t_player;

typedef struct s_map
{
	t_position	*teleporters;
	t_door		*doors;
	t_enemy		*enemy;
	char		**map;
	int			*line_lengths;
	int			height;
	int			width;
	int			num_teleporters;
	int			num_doors;
	int			num_enemy;
	bool		one_or_two;
}	t_map;

typedef struct s_mini_map
{
	int			dx;
	int			dy;
	double		dist;
	double		angle;
	double		map_x;
	double		map_y;
	int			cell_x;
	int			cell_y;
	int			center_x;
	int			center_y;
}	t_mini_map;

#endif