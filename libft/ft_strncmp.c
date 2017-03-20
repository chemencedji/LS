/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:35:45 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/25 21:24:34 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (n--)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		if (*t1 == '\0' && *t2 == '\0')
			return (0);
		t1++;
		t2++;
	}
	return (0);
}
