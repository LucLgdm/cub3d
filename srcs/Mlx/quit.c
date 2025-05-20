/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:15:37 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/20 13:37:43 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	ft_free_game(game);
	ft_printf("\033[32mClosing window... End of the game !\033[0m\n");
	exit(0);
}
