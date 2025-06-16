/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:15:37 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/16 12:26:34 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

extern double	g_current_time;

int	ft_close_window(t_game *game)
{
	struct timeval	tv;
	double			current_time_2;

	ft_free_game(game);
	ft_printf("\033[32mClosing window... End of the game !\033[0m\n");
	gettimeofday(&tv, NULL);
	current_time_2 = tv.tv_sec + tv.tv_usec / 1000000.0;
	printf("Temps joue = %fs\n", current_time_2 - g_current_time);
	exit(0);
}
