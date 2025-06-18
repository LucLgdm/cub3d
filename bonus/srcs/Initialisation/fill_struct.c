/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:24:54 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/18 10:18:15 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_player(char c, int i, int j, t_game *game)
{
	if (!game->player)
	{
		game->player = ft_calloc(1, sizeof(t_player));
		if (!game->player)
			ft_print_error_and_exit("Error: Memory allocation player failed\n");
	}
	game->player->pos.x = (double)j;
	game->player->pos.y = (double)i;
	game->player->pos.x = T_SIZE * game->player->pos.x + T_SIZE / 2;
	game->player->pos.y = T_SIZE * game->player->pos.y + T_SIZE / 2;
	game->player->direction = c;
}

void	ft_fill_teleporter(int i, int j, t_game *game)
{
	t_position	*tmp;

	if (!game->map->teleporters)
	{
		game->map->teleporters = ft_calloc(1, sizeof(t_position));
		if (!game->map->teleporters)
			ft_print_error_and_exit("Error: malloc teleporter failed\n");
		game->map->num_teleporters = 1;
	}
	else
	{
		tmp = game->map->teleporters;
		game->map->teleporters = ft_calloc(game->map->num_teleporters + 1,
				sizeof(t_position));
		if (!game->map->teleporters)
			ft_print_error_and_exit("Error: malloc teleporter failed\n");
		ft_memcpy(game->map->teleporters, tmp, game->map->num_teleporters
			* sizeof(t_position));
		free(tmp);
		game->map->num_teleporters++;
	}
	game->map->teleporters[game->map->num_teleporters - 1].x = (double)j;
	game->map->teleporters[game->map->num_teleporters - 1].y = (double)i;
}

void	ft_fill_door(int i, int j, t_game *game)
{
	t_door	*tmp;

	if (!game->map->doors)
	{
		game->map->doors = ft_calloc(1, sizeof(t_door));
		if (!game->map->doors)
			ft_print_error_and_exit("Error: Memory allocation door failed\n");
		game->map->num_doors = 1;
	}
	else
	{
		tmp = game->map->doors;
		game->map->doors = ft_calloc(game->map->num_doors + 1, sizeof(t_door));
		if (!game->map->doors)
			ft_print_error_and_exit("Error: Memory allocation door failed\n");
		ft_memcpy(game->map->doors, tmp, game->map->num_doors * sizeof(t_door));
		free(tmp);
		game->map->num_doors++;
	}
	game->map->doors[game->map->num_doors - 1].x = j;
	game->map->doors[game->map->num_doors - 1].y = i;
	game->map->doors[game->map->num_doors - 1].is_open = false;
}

void	ft_fill_enemy(int i, int j, t_game *game)
{
	t_enemy	*tmp;
	
	if (!game->map->enemy)
	{
		game->map->enemy = ft_calloc(1, sizeof(t_enemy));
		if (!game->map->enemy)
			ft_print_error_and_exit("Error: Memory allocation enemy failed\n");
		game->map->num_enemy = 1;
	}
	else
	{
		tmp = game->map->enemy;
		game->map->enemy = ft_calloc(game->map->num_enemy + 1, sizeof(t_enemy));
		if (!game->map->enemy)
			ft_print_error_and_exit("Error: Memory allocation enemy failed\n");
		ft_memcpy(game->map->enemy, tmp, game->map->num_enemy * sizeof(t_enemy));
		free(tmp);
		game->map->num_enemy++;
	}
	game->map->enemy[game->map->num_enemy - 1].pos.x = j * T_SIZE;
	game->map->enemy[game->map->num_enemy - 1].pos.y = i * T_SIZE;
	game->map->enemy[game->map->num_enemy - 1].dxdy.x = 1.0;
	game->map->enemy[game->map->num_enemy - 1].dxdy.y = 0.0;
	game->map->enemy[game->map->num_enemy - 1].speed = 0.5;
}
