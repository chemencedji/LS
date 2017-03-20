/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:38:06 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/15 23:53:26 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (tab);
	i = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			tab[++i] = ft_strnew(ft_strlen_word(s, c));
			j = 0;
			while (*s != c && *s)
				tab[i][j++] = *s++;
			tab[i][j] = '\0';
		}
	}
	tab[i + 1] = NULL;
	return (tab);
}
