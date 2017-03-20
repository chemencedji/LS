/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 16:18:42 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/23 16:53:55 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	tmp = (char*)s;
	tmp = ft_memalloc(sizeof(char) * (ft_strlen((char*)s)) + 1);
	if (tmp == NULL)
		return (NULL);
	if (tmp)
	{
		i = 0;
		while (s[i])
		{
			tmp[i] = (*f)(s[i]);
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
