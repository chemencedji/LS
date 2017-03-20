/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:06:57 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/24 19:09:16 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int nb)
{
	int m[10];
	int i;
	int sgn;

	sgn = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		sgn = (-1);
	}
	if (nb == 0)
		ft_putchar('0');
	i = 0;
	while (nb != 0)
	{
		m[i] = sgn * (nb % 10);
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(m[i] + 48);
		i--;
	}
}
