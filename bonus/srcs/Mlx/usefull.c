/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:02:27 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 14:25:48 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_distance(t_position *pos1, t_position *pos2)
{
	return (sqrt(pow((pos2->x - pos1->x), 2) + pow((pos2->y - pos1->y), 2)));
}
