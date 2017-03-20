/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:55:04 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/25 20:26:18 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int			i;
	int			j;
	char		*tmp1;
	char		*tmp2;

	if (n == 0 || str1 == str2)
		return (str1);
	tmp1 = str1;
	tmp2 = (char*)str2;
	i = ft_strlen(tmp1);
	j = ft_strlen(tmp2);
	if (n > 0)
	{
		while (n-- > 0)
			*tmp1++ = *tmp2++;
		if (j >= i && i == 1)
			*tmp1 = '\0';
	}
	return (str1);
}
