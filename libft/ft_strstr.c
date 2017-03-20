/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:20:45 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/22 14:16:13 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (*to_find == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			i = 0;
			while (to_find[i] != '\0')
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
				return (str);
		}
		str++;
	}
	return (0);
}
