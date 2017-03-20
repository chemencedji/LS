/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 12:03:03 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/24 14:25:28 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	int				delta;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
		delta = 1;
	else if (d > s)
	{
		d = d + len - 1;
		s = s + len - 1;
		delta = -1;
	}
	else
		return (dst);
	while (len--)
	{
		*d = *s;
		d += delta;
		s += delta;
	}
	return (dst);
}
