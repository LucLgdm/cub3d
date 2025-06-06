/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/06 15:27:46 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "position.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

#define MINIMAP_RADIUS 80
#define MINIMAP_CENTER_X (MINIMAP_RADIUS + 50)
#define MINIMAP_CENTER_Y (game->height_w - MINIMAP_RADIUS - 100)

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
	t_position	*teleporters;
	t_door		*doors;
	char		**map;
	int			*line_lengths;
	int			height;
	int			width;
	int			num_teleporters;
	int			num_doors;
}	t_map;

typedef struct s_mini_map
{
	int		dx;
	int		dy;
	float	dist;
	float	angle;
	float	map_x;
	float	map_y;
	int		cell_x;
	int		cell_y;
} t_mini_map;

#endif