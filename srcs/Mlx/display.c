/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:49 by lde-merc          #+#    #+#             */
/*   Updated: 2025/05/13 16:40:38 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_correction(t_game * game){
	t_raycasting	ray;
	
	ft_display_all(game);
	ft_ray_casting(&ray, game);


	
	// // Raycasting
	// int ray_color =ft_create_color(255, 0, 255, 0);
	// int dof, dist, px, py;
	// int map_x, map_y;
	// float rx, ry, x0, y0, ray_angle;
	// float dist3d;
	
	// ray_angle = game->player->angle - 30 * PI / 180;
	// if (ray_angle < 0)
	// 	ray_angle += 2 * PI;
	// if (ray_angle > 2 * PI)
	// 	ray_angle -= 2 * PI;
	
	// int num_rays = 66;
	
	// for (int r = 0; r < num_rays; r++){
	// /************************
	//  * Horizontal raycasting
	//  ************************/
	// 	dof = 0;
	// 	float atan = -1 / tan(ray_angle);
	// 	if (ray_angle > PI){
	// 		ry = (((int)game->player->pos.y >> 6) << 6) - 0.0001;
	// 		rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
	// 		y0 = -64;
	// 		x0 = -y0*atan;
	// 	}
	// 	if (ray_angle < PI){
	// 		ry = (((int)game->player->pos.y >> 6) << 6) + 64;
	// 		rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
	// 		y0 = 64;
	// 		x0 = -y0*atan;
	// 	}
	// 	if (ray_angle == 0 || ray_angle == PI){
	// 		rx = game->player->pos.x;
	// 		ry = game->player->pos.y;
	// 		dof = 8;
	// 	}
	// 	while( dof < 8) {
	// 		map_x = (int)rx >> 6;
	// 		map_y = (int)ry >> 6;
	// 		if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
	// 			break;
	// 		if (game->map->map[map_y][map_x] == '1')
	// 			dof = 8;
	// 		else{
	// 			rx += x0;
	// 			ry += y0;
	// 			dof++;
	// 		}
	// 	}
	// 	dist = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
	// 	px = rx;
	// 	py = ry;
	
	// /************************
	//  * Vertical raycasting
	//  ************************/
	// 	dof = 0;
	// 	float ntan = -tan(ray_angle);
		
	// 	if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2){
	// 		rx = (((int)game->player->pos.x >> 6) << 6) - 0.0001;
	// 		ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
	// 		x0 = -64;
	// 		y0 = -x0 * ntan;
	// 	} else if (ray_angle < PI / 2 || ray_angle > 3 * PI / 2){
	// 		rx = (((int)game->player->pos.x >> 6) << 6) + 64;
	// 		ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
	// 		x0 = 64;
	// 		y0 = -x0 * ntan;
	// 	}else{
	// 		rx = game->player->pos.x;
	// 		ry = game->player->pos.y;
	// 		dof = 8;
	// 	}
		
	// 	while(dof < 8) {
	// 		map_x = (int)rx >> 6;
	// 		map_y = (int)ry >> 6;
	// 		if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
	// 			break;
	// 		if (game->map->map[map_y][map_x] == '1')
	// 			dof = 8;
	// 		else{
	// 			rx += x0;
	// 			ry += y0;
	// 			dof++;
	// 		}
	// 	}
	// if (ry > game->height_w)
	// 	ry = game->height_w;
	// if (ry < 0)
	// 	ry = 0;

	// 	if (dist < sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2)))
	// 	{
	// 		dist3d = dist;
	// 		ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, px, py, ray_color);
	// 	}else{
	// 		dist3d = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
	// 		ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, rx, ry, ray_color);
	// 	}
	// 	ray_angle += PI / 180;
	// 	if (ray_angle < 0)
	// 		ray_angle += 2 * PI;
	// 	if (ray_angle > 2 * PI)
	// 		ray_angle -= 2 * PI;	
	// }

	// Player direction line
	int line_color = ft_create_color(255, 255, 255, 0);
	int x1 = game->player->pos.x;
	int y1 = game->player->pos.y;
	int x2 = x1 + 5 * game->player->dx;
	int y2 = y1 + 5 * game->player->dy;
	ft_draw_line(game->mlx, x1, y1, x2, y2, line_color);

	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 10, 10);
}





// void	ft_display(t_game *game)
// {
// 	int color =ft_create_color(255, 255 / 3, 255 / 3, 255 / 3);
// 	// Background
// 	for(int x = 0; x <= game->width_w; x++){
// 		for(int y = 0; y <= game->height_w; y++){
// 			my_mlx_pixel_put(game->mlx, x, y, color);
// 		}
// 	}
	
// 	// // Map
// 	// int i, j;
// 	// i = -1;
// 	// while(++i < game->map->height){
// 	// 	j = -1;
// 	// 	while(++j < game->map->width){
// 	// 		if (game->map->map[i][j] == '1')
// 	// 			ft_draw_square(game, j * 64, i * 64,ft_create_color(255, 255, 255, 255));
// 	// 		if (game->map->map[i][j] == '0')
// 	// 			ft_draw_square(game, j * 64, i * 64,ft_create_color(255, 0, 0, 0));
// 	// 	}
// 	// }
	
	
// 	// // Player
// 	// for(int i = -5; i < 6; i++){
// 	// 	for(int j = -5; j < 6; j++){
// 	// 		my_mlx_pixel_put(game->mlx, game->player->pos.x + i, game->player->pos.y + j,ft_create_color(255, 255, 255, 0));
// 	// 	}
// 	// }
	
// 	// Player direction line
// 	// int line_color =ft_create_color(255, 255, 255, 0); // Vert
// 	// int x1 = game->player->pos.x;
// 	// int y1 = game->player->pos.y;
// 	// int x2 = x1 + 5 * game->player->dx;
// 	// int y2 = y1 + 5 * game->player->dy;
// 	// ft_draw_line(game->mlx, x1, y1, x2, y2, line_color);

// 	// Raycasting
// 	// int ray_color_h =ft_create_color(255, 0, 255, 0); // horizontal
// 	// int ray_color_v =ft_create_color(255, 0, 255, 255); // vertical
// 	int ray_color; // =ft_create_color(255, 0, 255, 0); // ray color
// 	int dof, dist, px, py;
// 	int map_x, map_y;
// 	float rx, ry, x0, y0, ray_angle, dist3d;
	
// 	ray_angle = game->player->angle - 30 * PI / 180;
// 	if (ray_angle < 0)
// 		ray_angle += 2 * PI;
// 	if (ray_angle > 2 * PI)
// 		ray_angle -= 2 * PI;
	
// 	int num_rays = 66;
// 	float ray_width = (float)game->width_w / num_rays;
	
// 	for (int r = 0; r < num_rays; r++){
// 	/************************
// 	 * Horizontal raycasting
// 	 ************************/
// 		dof = 0;
// 		float atan = -1 / tan(ray_angle);
// 		if (ray_angle > PI){
// 			ry = (((int)game->player->pos.y >> 6) << 6) - 0.0001;
// 			rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
// 			y0 = -64;
// 			x0 = -y0*atan;
// 		}
// 		if (ray_angle < PI){
// 			ry = (((int)game->player->pos.y >> 6) << 6) + 64;
// 			rx = (game->player->pos.y - ry)*atan + game->player->pos.x;
// 			y0 = 64;
// 			x0 = -y0*atan;
// 		}
// 		if (ray_angle == 0 || ray_angle == PI){
// 			rx = game->player->pos.x;
// 			ry = game->player->pos.y;
// 			dof = 15;
// 		}
// 		while( dof < 15) {
// 			map_x = (int)rx >> 6;
// 			map_y = (int)ry >> 6;
// 			if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
// 				break;
// 			if (game->map->map[map_y][map_x] == '1')
// 				dof = 15;
// 			else{
// 				rx += x0;
// 				ry += y0;
// 				dof++;
// 			}
// 		}
// 		dist = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
// 		px = rx;
// 		py = ry;
// 		// ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, rx, ry, ray_color_h);
	
// 	/************************
// 	 * Vertical raycasting
// 	 ************************/
// 		dof = 0;
// 		float ntan = -tan(ray_angle);
		
// 		if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2){
// 			rx = (((int)game->player->pos.x >> 6) << 6) - 0.0001;
// 			ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
// 			x0 = -64;
// 			y0 = -x0 * ntan;
// 		} else if (ray_angle < PI / 2 || ray_angle > 3 * PI / 2){
// 			rx = (((int)game->player->pos.x >> 6) << 6) + 64;
// 			ry = (game->player->pos.x - rx) * ntan + game->player->pos.y;
// 			x0 = 64;
// 			y0 = -x0 * ntan;
// 		}else{
// 			rx = game->player->pos.x;
// 			ry = game->player->pos.y;
// 			dof = 15;
// 		}
		
// 		while(dof < 15) {
// 			map_x = (int)rx >> 6;
// 			map_y = (int)ry >> 6;
// 			if (map_x < 0 || map_x >= game->map->width || map_y < 0 || map_y >= game->map->height)
// 				break;
// 			if (game->map->map[map_y][map_x] == '1')
// 				dof = 15;
// 			else{
// 				rx += x0;
// 				ry += y0;
// 				dof++;
// 			}
// 		}
// 		if (ry > game->height_w)
// 			ry = game->height_w;
// 		if (ry < 0)
// 			ry = 0;
// 		if (dist < sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2)))
// 		{
// 			ray_color =ft_create_color(255, 0.9 * 20, 0.9 * 30, 0.9 * 150);
// 			dist3d = dist;
// 			// ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, px, py, ray_color);
// 		}else{
// 			ray_color =ft_create_color(255, 0.7 * 20, 0.7 * 30, 0.7 * 150);
// 			dist3d = sqrt(pow((game->player->pos.x - rx), 2) + pow((game->player->pos.y - ry), 2));
// 			// ft_draw_line(game->mlx, game->player->pos.x, game->player->pos.y, rx, ry, ray_color);
// 		}
		
// 		/*********************
// 		 * Drawing the wall
// 		 *********************/
// 		float ca = game->player->angle - ray_angle;
// 		if (ca < 0)
// 			ca += 2 * PI;
// 		if (ca > 2 * PI)
// 			ca -= 2 * PI;
// 		dist3d = dist3d * cos(ca);	
// 		float wall_height = (game->height_w * 64) / dist3d;
// 		if (wall_height > game->height_w)
// 			wall_height = game->height_w;
// 		float wall_start = (game->height_w / 2) - (wall_height / 2);
// 		// float wall_offset = game->width_w / 2;

// 		int thickness = ray_width + 1; // Épaisseur des rayons
// 		// ft_draw_rectangle(game->mlx, r * 10 + wall_offset, wall_start,
//         //           wall_start + wall_height, thickness, ray_color);
// 		ft_draw_rectangle(game->mlx, r * ray_width, wall_start,
//                   wall_start + wall_height, thickness, ray_color);
		
// 		ray_angle += PI / 180;
// 		if (ray_angle < 0)
// 			ray_angle += 2 * PI;
// 		if (ray_angle > 2 * PI)
// 			ray_angle -= 2 * PI;	
// 	}
	
// 	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
// }

