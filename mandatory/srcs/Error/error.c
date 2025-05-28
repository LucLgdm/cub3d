/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:41:22 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 12:24:50 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_error_and_exit(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	ft_free_game(ft_get_game());
	exit(EXIT_FAILURE);
}

void	ft_exit_parsing(int fd, char *line, char *error_message)
{
	if (line)
		free(line);
	if (fd != -1)
		close(fd);
	ft_print_error_and_exit(error_message);
}
