/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/06/16 13:06:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

static void	resize_tex(t_tex *src, t_tex *dst)
{
	t_position	index;
	t_position	src_pos;
	char		*src_pixel;
	char		*dst_pixel;
	int			b;

	index.y = -1;
	while (++index.y < dst->height)
	{
		index.x = -1;
		while (++index.x < dst->width)
		{
			src_pos.x = (int)index.x * src->width / dst->width;
			src_pos.y = (int)index.y * src->height / dst->height;
			src_pixel = src->addr + ((int)src_pos.y * src->line_length
					+ (int)src_pos.x * (src->bits_per_pixel / 8));
			dst_pixel = dst->addr + ((int)index.y * dst->line_length
					+ (int)index.x * (dst->bits_per_pixel / 8));
			b = -1;
			while (++b < dst->bits_per_pixel / 8)
				dst_pixel[b] = src_pixel[b];
		}
	}
}

static void	resize_all_images(t_image *source, t_image *dest)
{
	resize_tex(&source->north, &dest->north);
	resize_tex(&source->south, &dest->south);
	resize_tex(&source->east, &dest->east);
	resize_tex(&source->west, &dest->west);
}

void	ft_game(int flag)
{
	t_game	*game;

	game = ft_get_game();
	game->player->velocity = 1.0f;
	game->correction = flag;
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!game->mlx)
		ft_print_error_and_exit("Error\nAllocation failed\n");
	game->mlx->mlx = mlx_init();
	mlx_get_screen_size(game->mlx->mlx, &game->width_w, &game->height_w);
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->width_w,
			game->height_w, "cub3D");
	game->mlx->img = mlx_new_image(game->mlx->mlx, game->width_w,
			game->height_w);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img,
			&game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);
	ft_image_generator(game);
	resize_all_images(game->image, game->image_resized);
	ft_display(game, flag);
	mlx_hook(game->mlx->win, 17, 1L << 19, ft_close_window, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, ft_key_handle, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, ft_key_release, game);
	mlx_loop_hook(game->mlx->mlx, ft_game_loop, game);
	mlx_loop(game->mlx->mlx);
}

int	main(int argc, char **argv)
{
	ft_game_initialisation(argc, argv);
	ft_game(0);
	return (0);
}
