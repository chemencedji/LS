/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 12:36:13 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/25 20:30:17 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			cur;

	if (dest == src || n == 0)
		return (NULL);
	cur = 0;
	c1 = (unsigned char *)dest;
	c2 = (unsigned char *)src;
	while (cur < n)
	{
		c1[cur] = c2[cur];
		if (c1[cur] == (unsigned char)c)
			return (c1 + cur + 1);
		cur++;
	}
	return (NULL);
}
