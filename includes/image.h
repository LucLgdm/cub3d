/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:43:30 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/23 13:53:19 by lde-merc         ###   ########.fr       */
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
	char	*add_N;
	char	*add_S;
	char	*add_E;
	char	*add_W;
} t_image;


#endif
