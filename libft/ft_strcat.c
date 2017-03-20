/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:06:09 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/22 13:07:14 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while (*src != '\0')
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
