/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:41:22 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/24 14:48:12 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error_and_exit(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	ft_free_game(ft_get_game());
	exit(EXIT_FAILURE);
}
