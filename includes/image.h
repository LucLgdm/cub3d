/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:43:30 by luclgdm           #+#    #+#             */
/*   Updated: 2025/04/29 11:08:46 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef union u_color {
	unsigned int value;
	struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	} s_channel;
} t_color;


typedef struct s_image
{
	void	*wall_N;
	void	*wall_S;
	void	*wall_E;
	void	*wall_W;
	t_color	floor;
	t_color	ceiling;
	int		img_height;
	int		img_width;
} t_image;


#endif
