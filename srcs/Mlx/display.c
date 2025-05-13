/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/13 11:07:22 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color){
	char	*dst;


	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	create_color(int t, int r, int g, int b){
	return (t << 24) | (r << 16) | (g << 8) | b;
}


static void	ft_draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 63)
	{
		j = 0;
		while (++j < 63)
			my_mlx_pixel_put(game->mlx, x + j, y + i, color);
	}
}

static void	ft_draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2, int color)
{
    int	dx;
    int	dy;
    int	steps;
    float	x_inc;
    float	y_inc;
    float	x;
    float	y;

    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / (float)steps;
    y_inc = dy / (float)steps;
    x = x1;
    y = y1;
    for (int i = 0; i <= steps; i++){
	    my_mlx_pixel_put(mlx, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}

static void	ft_draw_rectangle(t_mlx *mlx, int x, int y_start, int y_end, int width, int color)
{
    for (int i = 0; i < width; i++) {
        ft_draw_line(mlx, x + i, y_start, x + i, y_end, color);
    }
}

void	ft_display(t_game *game)
{
	int color = create_color(255, 255 / 3, 255 / 3, 255 / 3);
	// Background
	for(int x = 0; x <= game->width_w; x++){
		for(int y = 0; y <= game->height_w; y++){
			my_mlx_pixel_put(game->mlx, x, y, color);
		}
	}
	
	// Map
	int i, j;
	i = -1;
	while(++i < game->map->height){
		j = -1;
		while(++j < game->map->width){
			if (game->map->map[i][j] == '1')
				ft_draw_square(game, j * 64, i * 64, create_color(255, 255, 255, 255));
			if (game->map->map[i][j] == '0')
				ft_draw_square(game, j * 64, i * 64, create_color(255, 0, 0, 0));
		}
	}
	
	
	// Player
	for(int i = -5; i < 6; i++){
		for(int j = -5; j < 6; j++){
			my_mlx_pixel_put(game->mlx, game->player->pos.x + i, game->player->pos.y + j, create_color(255, 255, 255, 0));
		}
	}
	
	// Player direction line
	// int line_color = create_color(255, 255, 255, 0); // Vert
	// int x1 = game->player->pos.x;
	// int y1 = game->player->pos.y;
	// int x2 = x1 + 5 * game->player->dx;
	// int y2 = y1 + 5 * game->player->dy;
	// ft_draw_line(game->mlx, x1, y1, x2, y2, line_color);

	// Raycasting
	// int ray_color_h = create_color(255, 0, 255, 0); // horizontal
	// int ray_color_v = create_color(255, 0, 255, 255); // vertical
	int ray_color; // = create_color(255, 0, 255, 0); // ray color
	int dof, dist, px, py;
	int map_x, map_y;
	float rx, ry, x0, y0, ray_angle, dist3d;
	
	ray_angle = game->player->angle - 30 * PI / 180;
	if (ray_angle < 0)
		ray_angle += 2 * PI;
	if (ray_angle > 2 * PI)
		ray_angle -= 2 * PI;
	
	for (int r = 0; r < 60; r++){
	/************************
	 * Horizontal raycasting
	 ************************/
		dof = 0;
		float atan = -1 / tan(ray_angle);
		if (ray_angle > PI){
			ry = (((int)game->player->pos.y >> 6) << 6) - 0.0001;
			rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
			y0 = -64;
			x0 = -y0*atan;
		}
		if (ray_angle < PI){
			ry = (((int)game->player->pos.y >> 6) << 6) + 64;
			rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
			y0 = 64;
			x0 = -y0*atan;
		}
		if (ray_angle == 0 || ray_angle == PI){
			rx = game->player->pos.x;
			ry = game->player->pos.y;
			dof = 8;
		}
		while( dof < 8) {
			map_x = (int)rx >> 6;
			map_y = (int)ry >> 6;
			if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
				break;
			if (game->map->map[map_y][map_x] == '1')
				dof = 8;
			else{
				rx += x0;
				ry += y0;
				dof++;
			}
		}
		dist = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
		px = rx;
		py = ry;
		// ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, rx, ry, ray_color_h);
	
	/************************
	 * Vertical raycasting
	 ************************/
		dof = 0;
		float ntan = -tan(ray_angle);
		
		if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2){
			rx = (((int)game->player->pos.x >> 6) << 6) - 0.0001;
			ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
			x0 = -64;
			y0 = -x0 * ntan;
		} else if (ray_angle < PI / 2 || ray_angle > 3 * PI / 2){
			rx = (((int)game->player->pos.x >> 6) << 6) + 64;
			ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
			x0 = 64;
			y0 = -x0 * ntan;
		}else{
			rx = game->player->pos.x;
			ry = game->player->pos.y;
			dof = 8;
		}
		
		while(dof < 8) {
			map_x = (int)rx >> 6;
			map_y = (int)ry >> 6;
			if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
				break;
			if (game->map->map[map_y][map_x] == '1')
				dof = 8;
			else{
				rx += x0;
				ry += y0;
				dof++;
			}
		}
		if (ry > game->height_w)
			ry = game->height_w;
		if (ry < 0)
			ry = 0;
		if (dist < sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2)))
		{
			ray_color = create_color(255, 0.9 * 140, 0.9 * 30, 0.9 * 250);
			dist3d = dist;
			ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, px, py, ray_color);
		}else{
			ray_color = create_color(255, 0.7 * 140, 0.7 * 30, 0.7 * 250);
			dist3d = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
			ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, rx, ry, ray_color);
		}
		
		/*********************
		 * Drawing the wall
		 *********************/
		float ca = game->player->angle - ray_angle;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		dist3d = dist3d * cos(ca);	
		float wall_height = (game->height_w * 64) / dist3d;
		if (wall_height > game->height_w)
			wall_height = game->height_w;
		float wall_start = (game->height_w / 2) - (wall_height / 2);
		float wall_offset = game->width_w / 2;

		int thickness = 10; // Épaisseur des rayons
		ft_draw_rectangle(game->mlx, r * 10 + wall_offset, wall_start,
                  wall_start + wall_height, thickness, ray_color);
		
		ray_angle += PI / 180;
		if (ray_angle < 0)
			ray_angle += 2 * PI;
		if (ray_angle > 2 * PI)
			ray_angle -= 2 * PI;	
	}
	
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
}

