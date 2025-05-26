/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:27:09 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/26 16:05:27 by lde-merc         ###   ########.fr       */
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

	mlx = game->mlx;
	ft_image_north(mlx->mlx, &game->image->north);
	ft_image_south(mlx->mlx, &game->image->south);
	ft_image_east(mlx->mlx, &game->image->east);
	ft_image_west(mlx->mlx, &game->image->west);
}

void	ft_image_north(void *mlx, t_tex *north)
{
	north->img = mlx_xpm_file_to_image(mlx, (char *)(north->path), &(north->width), &(north->height));
	north->addr = mlx_get_data_addr(north->img, &(north->bits_per_pixel), &(north->line_length), &(north->endian));
}

void	ft_image_south(void *mlx, t_tex *south)
{
	south->img = mlx_xpm_file_to_image(mlx, (char *)(south->path), &(south->width), &(south->height));
	south->addr = mlx_get_data_addr(south->img, &(south->bits_per_pixel), &(south->line_length), &(south->endian));
}

void	ft_image_east(void *mlx, t_tex *east)
{
	east->img = mlx_xpm_file_to_image(mlx, (char *)(east->path), &(east->width), &(east->height));
	east->addr = mlx_get_data_addr(east->img, &(east->bits_per_pixel), &(east->line_length), &(east->endian));
}

void	ft_image_west(void *mlx, t_tex *west)
{
	west->img = mlx_xpm_file_to_image(mlx, (char *)(west->path), &(west->width), &(west->height));
	west->addr = mlx_get_data_addr(west->img, &(west->bits_per_pixel), &(west->line_length), &(west->endian));
}
