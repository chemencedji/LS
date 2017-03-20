/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:08:35 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/22 13:10:02 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while (*src != '\0' && n-- > 0)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
