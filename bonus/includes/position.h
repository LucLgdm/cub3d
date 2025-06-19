/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:33:25 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/19 12:44:45 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

typedef struct s_position
{
	double			x;
	double			y;
}	t_position;

typedef struct s_los
{
	float	dx;
	float	dy;
	float	dist;
	int		steps;
	float	step_x;
	float	step_y;
	float	x;
	float	y;
	int		mx;
	int		my;
	int		i;
}	t_los;

#endif