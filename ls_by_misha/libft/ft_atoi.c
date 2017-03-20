/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:18:45 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/27 12:35:49 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int n;
	int s;

	n = 0;
	s = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
			|| *nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		s = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + *nptr - 48;
		nptr++;
	}
	return (n * s);
}
