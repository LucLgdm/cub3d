/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:01 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/23 18:54:51 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3d_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

#include "image.h"

typedef struct s_mlx{
	void	*mlx;
	void	*win;
} t_mlx;

typedef struct s_game{
	t_mlx	mlx;
	char	**map;
	void	*image;
	int		height_w;
	int		width_w;
} t_game;

/********************
 * 		Guetter
 ********************/

 t_game	*ft_get_game(void);

/********************
 * 		Memory
 ********************/

void	ft_malloc_game(t_game *game);
void	ft_malloc_mlx(t_game *game);
void	ft_malloc_image(t_game *game);
void	ft_malloc_map(t_game *game);

#endif