/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:49:50 by lde-merc          #+#    #+#             */
/*   Updated: 2025/06/23 15:46:29 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_clean(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i + 1];
		i++;
		j++;
	}
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	return (i);
}

char	*ft_strcdup(char *str, char c)
{
	int		length;
	char	*duplicated;
	int		i;

	length = ft_strclen(str, c);
	duplicated = malloc((length + 1) * sizeof(char));
	if (!duplicated)
		return (NULL);
	i = -1;
	while (++i < length)
		duplicated[i] = str[i];
	duplicated[length] = 0;
	return (duplicated);
}

char	*ft_strcjoin(char *line, char *buffer, char c)
{
	char	*new_line;
	int		i;

	if (!line)
		return (ft_strcdup(buffer, c));
	new_line = malloc((ft_strclen(line, c) + ft_strclen(buffer, c) + 1)
			* sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	while (*buffer && *buffer != c)
	{
		new_line[i] = *buffer;
		i++;
		buffer++;
	}
	if (*buffer == c)
		new_line[i++] = c;
	new_line[i] = 0;
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		if (*buffer)
		{
			line = ft_strcjoin(line, buffer, '\n');
			if (!line)
				return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
		{
			ft_clean(buffer);
			break ;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
	}
	return (line);
}
