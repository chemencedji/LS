/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:17:20 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/24 14:28:39 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	l;
	char			*p;

	l = 0;
	while (src[l])
		l++;
	p = (char *)malloc(sizeof(char) * (l + 1));
	if (p != 0)
	{
		l = 0;
		while (src[l])
		{
			p[l] = src[l];
			l++;
		}
		p[l] = '\0';
	}
	return (p);
}
