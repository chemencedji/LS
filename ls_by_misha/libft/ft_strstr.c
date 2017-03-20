/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 10:58:30 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/24 00:53:43 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;

	if (*to_find == 0)
		return ((char *)str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (to_find[i])
			{
				if (str[i] == to_find[i])
					i++;
				else
				{
					i = 0;
					break ;
				}
			}
			if (i > 0)
				return ((char *)str);
		}
		str++;
	}
	return (0);
}
