/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:40:30 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/22 14:41:31 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, int n)
{
	char	*der;

	der = str;
	if (n < 0)
		return (0);
	while (n > 0)
	{
		*der++ = c;
		n--;
	}
	return (str);
}
