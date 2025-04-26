/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:43:30 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/25 15:46:54 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H


typedef struct s_image
{
	void	*wall_N;
	void	*wall_S;
	void	*wall_E;
	void	*wall_W;
	void	*floor;
	void	*ceiling;
	int		img_height;
	int		img_width;
}			t_image;


#endif
