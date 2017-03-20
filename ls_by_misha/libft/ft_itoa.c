/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:35:18 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/26 15:58:41 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_len_nbr(int nbr)
{
	int len;

	len = 1;
	if (nbr < 0)
		len = 2;
	while (nbr /= 10)
		len++;
	return (len);
}

char					*ft_itoa(int nbr)
{
	char			*str;
	int				i;
	int				s;
	unsigned int	n;

	s = 1;
	if (nbr < 0)
		s = -1;
	i = ft_len_nbr(nbr);
	if (!(str = ft_strnew(i)))
		return (str);
	n = s * nbr;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = n % 10 + 48;
		n = n / 10;
	}
	if (i && nbr < 0)
		str[--i] = '-';
	return (str);
}
