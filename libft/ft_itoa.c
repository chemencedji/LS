/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 18:47:06 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/24 21:10:43 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*ft_num(int nbr, char *ret, int y, int z)
{
	int	i;

	i = 0;
	if (nbr < 0)
		ret[i++] = '-';
	if (nbr == 0)
		ret[i++] = '0';
	while (nbr != 0)
	{
		ret[i++] = (nbr / z) + 48;
		nbr %= z;
		z /= 10;
	}
	while (y > i)
		ret[i++] = 48;
	ret[i] = '\0';
	return (ret);
}

char			*ft_itoa(int nbr)
{
	int		i;
	int		j;
	int		z;
	char	*ret;

	i = 1;
	z = 1;
	j = nbr;
	if (nbr < 0)
	{
		i++;
		z = -1;
	}
	while (j > 9 || j < -9)
	{
		j /= 10;
		i++;
		z *= 10;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret == NULL)
		return (NULL);
	ret = ft_num(nbr, ret, i, z);
	return (ret);
}
