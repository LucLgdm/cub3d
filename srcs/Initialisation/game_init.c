/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:27:09 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/23 13:57:13 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_initialisation(int argc, char **argv)
{
	t_game	*game;
	int		size;

	if (argc != 2)
		ft_print_error_and_exit("Usage: ./cub3D <map.cub>\n");
	size = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + size - 4, ".cub", 4) != 0)
		ft_print_error_and_exit("Error\nInvalid file extension: .cub\n");
	game = ft_get_game();
	ft_parsing(game, argv);
	ft_check_player(game);
}

void	ft_check_player(t_game *game)
{
	if (!game->player)
		ft_print_error_and_exit("Error\nNo player found\n");
	if (game->player->direction == 'N')
		game->player->angle = 3 * PI / 2;
	else if (game->player->direction == 'S')
		game->player->angle = PI / 2;
	else if (game->player->direction == 'E')
		game->player->angle = 0;
	else if (game->player->direction == 'W')
		game->player->angle = PI;
	game->player->dx = 5 * cos(game->player->angle);
	game->player->dy = 5 * sin(game->player->angle);
}

void	ft_image_generator(t_game *game)
{
	t_mlx	*mlx;
	int		height;
	int		width;

	mlx = game->mlx;
	height = game->image->img_height;
	width = game->image->img_width;
	
	game->image->wall_N = mlx_xpm_file_to_image(game->mlx->mlx, (char *)(game->image->wall_N), &width, &height);
	game->image->wall_S = mlx_xpm_file_to_image(game->mlx->mlx, (char *)(game->image->wall_S), &width, &height);
	game->image->wall_E = mlx_xpm_file_to_image(game->mlx->mlx, (char *)(game->image->wall_E), &width, &height);
	game->image->wall_W = mlx_xpm_file_to_image(game->mlx->mlx, (char *)(game->image->wall_W), &width, &height);
	
	game->image->add_N = mlx_get_data_addr(game->image->wall_N, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
	game->image->add_S = mlx_get_data_addr(game->image->wall_S, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
	game->image->add_E = mlx_get_data_addr(game->image->wall_E, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
	game->image->add_W = mlx_get_data_addr(game->image->wall_W, &(mlx->bits_per_pixel), &(mlx->line_length), &(mlx->endian));
}
