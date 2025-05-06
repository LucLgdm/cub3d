/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:20:26 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/06 11:48:54 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_transpose_tab(char **tab)
{
	char	**transposed_tab;
	int		tab_length;
	int		tab_width;
	int		i;
	int		j;

	tab_length = (int)ft_arraylen(tab);
	if (tab_length == 0)
		return (NULL);
	tab_width = 0;
	i = -1;
	while (++i < tab_length)
		if ((int)ft_strlen(tab[i]) > tab_width)
			tab_width = (int)ft_strlen(tab[i]);
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
	i = -1;
	while (++i < tab_length)
	{
		j = -1;
		while (++j < (int)ft_strlen(tab[i]))
			transposed_tab[j][i] = tab[i][j];
	}
	return (transposed_tab);
}

// int main(){
// 	char *tab[] = { "123456789",
// 					"12345678",
// 					"1234567",
// 					"123456",
// 					"12345",
// 					"1234",
// 					"123",
// 					"12",
// 					"1",
// 					NULL};

// 	char **transposed = ft_transpose_tab(tab);

// 	for(int i = 0; transposed[i]; i++)
// 		printf("%s\n", transposed[i]);
// 	ft_free_array(transposed);
// 	return (0);
// }