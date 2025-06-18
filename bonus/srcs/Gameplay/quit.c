/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:15:37 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 14:59:42 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close_window(t_game *game)
{
	ft_free_game(game);
	ft_printf("\033[32mClosing window... End of the game !\033[0m\n");
	exit(0);
}
