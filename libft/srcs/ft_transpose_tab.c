/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luclgdm <luclgdm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:20:26 by luclgdm           #+#    #+#             */
/*   Updated: 2025/05/02 16:42:20 by luclgdm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_transpose_tab(char **tab)
{
    char	**transposed_tab;
    size_t		tab_length;
    size_t		tab_width;
    size_t		i;
    size_t		j;

    tab_length = ft_arraylen(tab);
    if (tab_length == 0)
        return (NULL);
    tab_width = 0;
	i = -1;
    while(++i < tab_length)
    {
        if (ft_strlen(tab[i]) > tab_width)
            tab_width = ft_strlen(tab[i]);
    }
    i = -1;
    transposed_tab = ft_calloc(tab_width + 1, sizeof(char **));
    if (!transposed_tab)
        return (NULL);
    while(++i < tab_width)
    {
        transposed_tab[i] = ft_calloc(tab_length + 1, sizeof(char *));
        if (!transposed_tab[i])
        {
            ft_free_array(transposed_tab);
            return (NULL);
        }
    }
	i = -1;
    while(++i < tab_length)
    {
		j = -1;
        while(++j < ft_strlen(tab[i]))
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
// 	return 0;
// }