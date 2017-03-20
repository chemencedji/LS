/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 11:13:24 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/26 20:18:10 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_bits(unsigned int nbr)
{
	int				i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

static void	cond1(unsigned int ch, int *i, char *buff)
{
	buff[(*i)++] = ((ch >> 18) & 7) | 240;
	buff[(*i)++] = ((ch >> 12) & 63) | 128;
}

static void	putwchart(int wchar, int *len, char *buff)
{
	unsigned int	ch;
	int				n;
	int				i;

	i = 0;
	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7 && ((*len += 1)))
	{
		if (n > 11 && ((*len += 1)))
		{
			if (n > 16 && ((*len += 2)))
				cond1(ch, &i, buff);
			else if ((*len += 1))
				buff[i++] = ((ch >> 12) & 15) | 224;
			buff[i++] = (ch & 63) | 128;
		}
		else if ((*len += 1))
			buff[i++] = ((ch >> 6) & 31) | 192;
		buff[i++] = (ch & 63) | 128;
	}
	else if ((*len += 1))
		buff[i++] = ch;
}

void		ft_putchar_fd(int c, int fd)
{
	int				len;
	char			buff2[10];

	len = 0;
	putwchart(c, &len, buff2);
	write(fd, buff2, len);
}
