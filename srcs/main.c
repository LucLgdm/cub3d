/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:50:45 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/23 18:49:52 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((constructor)) static void init_resources(void)
{
	t_game *game;

	game = ft_get_game();
	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("Error malloc game");
		exit(EXIT_FAILURE);
	}
	ft_malloc_game(game);
	printf("Ressources initialisées automatiquement\n");
}

__attribute__((destructor)) static void cleanup_resources(void)
{
	printf("Nettoyage automatique à la fin\n");
}

t_game	*ft_get_game(void)
{
	static t_game	game;

	return (&game);
}

int main(int argc, char **argv){
	(void)argc;
	(void)argv;
	
	printf("\033[34mHello World\n\033[0m");
	return (0);	
}