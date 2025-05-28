/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:20:26 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/27 12:21:16 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_tab_width(char **tab, int tab_length)
{
	int	tab_width;
	int	i;
	int	len;

	tab_width = 0;
	i = -1;
	while (++i < tab_length)
	{
		len = (int)ft_strlen(tab[i]);
		if (len > tab_width)
			tab_width = len;
	}
	return (tab_width);
}

static char	**ft_alloc_transposed_tab(int tab_width, int tab_length)
{
	char	**transposed_tab;
	int		i;
	int		j;

	transposed_tab = ft_calloc(tab_width + 1, sizeof(char *));
	if (!transposed_tab)
		return (NULL);
	i = -1;
	while (++i < tab_width)
	{
		transposed_tab[i] = ft_calloc(tab_length + 1, sizeof(char));
		if (!transposed_tab[i])
		{
			ft_free_array(transposed_tab);
			return (NULL);
		}
		j = -1;
		while (++j < tab_length)
			transposed_tab[i][j] = ' ';
	}
	return (transposed_tab);
}

static void	ft_fill_transposed_tab(char **tab, char **transposed_tab,
		int tab_length)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tab_length)
	{
		j = -1;
		while (++j < (int)ft_strlen(tab[i]))
			transposed_tab[j][i] = tab[i][j];
	}
}

char	**ft_transpose_tab(char **tab)
{
	int		tab_length;
	int		tab_width;
	char	**transposed_tab;

	tab_length = (int)ft_arraylen(tab);
	if (tab_length == 0)
		return (NULL);
	tab_width = ft_get_tab_width(tab, tab_length);
	transposed_tab = ft_alloc_transposed_tab(tab_width, tab_length);
	if (!transposed_tab)
		return (NULL);
	ft_fill_transposed_tab(tab, transposed_tab, tab_length);
	return (transposed_tab);
}
