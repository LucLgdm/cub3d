/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:43:30 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/28 12:33:38 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef union u_color
{
	unsigned int		value;
	struct
	{
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
	} s_channel;
}						t_color;

typedef struct s_tex
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
	char				*path;
}						t_tex;

typedef struct s_image
{
	t_tex				north;
	t_tex				south;
	t_tex				east;
	t_tex				west;
	t_color				floor;
	t_color				ceiling;
}						t_image;

#endif
