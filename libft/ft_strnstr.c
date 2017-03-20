/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:25:25 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/25 21:44:36 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*src;
	size_t	i;
	size_t	len;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	src = (char*)s1;
	len = ft_strlen((char*)s2);
	while (s1[i] != '\0' && (i + len <= n))
	{
		if (ft_strncmp(src + i, s2, len) == 0)
			return (src + i);
		i++;
	}
	return (NULL);
}
