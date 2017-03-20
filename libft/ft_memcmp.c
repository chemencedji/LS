/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 12:46:30 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/23 11:08:04 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char		*ptr1;
	const unsigned char		*ptr2;

	ptr1 = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	if (str1 == str2 || n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
