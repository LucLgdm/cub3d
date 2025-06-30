/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:01:16 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/30 16:30:31 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

static void	init_los_vars(t_los *vars, float ex, float ey, t_position player)
{
	vars->dx = player.x - ex;
	vars->dy = player.y - ey;
	vars->dist = sqrt(vars->dx * vars->dx + vars->dy * vars->dy);
	vars->steps = (int)vars->dist;
	vars->step_x = vars->dx / vars->steps;
	vars->step_y = vars->dy / vars->steps;
	vars->x = ex;
	vars->y = ey;
	vars->i = 0;
}

static int	has_line_of_sight(float ex, float ey, t_position player)
{
	t_los	vars;
	t_game	*game;

	game = ft_get_game();
	init_los_vars(&vars, ex, ey, player);
	while (vars.i < vars.steps)
	{
		vars.mx = (int)vars.x / T_SIZE;
		vars.my = (int)vars.y / T_SIZE;
		if (game->map->map[vars.my][vars.mx] != '0')
			return (0);
		vars.x += vars.step_x;
		vars.y += vars.step_y;
		vars.i++;
	}
	return (1);
}

void	ft_move_enemy(t_game *game, t_enemy *enemy)
{
	t_position	player;
	t_position	delta;
	double		dist;
	static int	count;

	player = game->player->pos;
	delta.x = player.x - enemy->pos.x;
	delta.y = player.y - enemy->pos.y;
	dist = sqrt(delta.x * delta.x + delta.y * delta.y);
	if (dist > ENEMY_VIEW_RADIUS)
		return ;
	if (!has_line_of_sight(enemy->pos.x, enemy->pos.y, player))
		return ;
	ft_move_enemy_step(game, enemy, delta, dist);
	count++;
	if (count < 8)
		game->map->one_or_two = true;
	else
		game->map->one_or_two = false;
	if (count > 16)
		count = 0;
}

void	ft_move_enemy_step(t_game *game, t_enemy *enemy, t_position delta,
		double dist)
{
	t_position	next;
	double		speed;
	int			mx;
	int			my;

	speed = 1.0f;
	if (dist != 0)
	{
		delta.x /= dist;
		delta.y /= dist;
	}
	next.x = enemy->pos.x + delta.x * speed;
	mx = (int)next.x / T_SIZE;
	my = (int)enemy->pos.y / T_SIZE;
	if (game->map->map[my][mx] == '0')
		enemy->pos.x = next.x;
	ft_move_enemy_y(game, enemy, delta, speed);
}

void	ft_move_enemy_y(t_game *game, t_enemy *enemy, t_position delta,
		double speed)
{
	t_position	next;
	int			mx;
	int			my;

	next.y = enemy->pos.y + delta.y * speed;
	next.x = enemy->pos.x;
	mx = (int)next.x / T_SIZE;
	my = (int)next.y / T_SIZE;
	if (game->map->map[my][mx] == '0')
		enemy->pos.y = next.y;
}
