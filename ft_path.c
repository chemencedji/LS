/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:32:24 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 20:53:37 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

char		*ft_strjoin_ls(char const *s1, char const *s2)
{
	char	*ret;
	char	*temp_ret;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	ret = (char *)malloc(sizeof(char) * (i + j) + 2);
	if (ret == NULL)
		return (NULL);
	temp_ret = ret;
	while (*s1 != '\0')
		*temp_ret++ = *s1++;
	*temp_ret = '/';
	temp_ret++;
	while (*s2 != '\0')
		*temp_ret++ = *s2++;
	*temp_ret = '\0';
	return (ret);
}

int			ndigits(int n)
{
	int		d;

	d = 1;
	while (n /= 10)
		d++;
	return (d);
}

void		ft_printlink(int nbr)
{
	int		i;
	int		f;

	i = ndigits(nbr);
	f = g_size1;
	while (f > i)
	{
		ft_putstr(" ");
		f--;
	}
	ft_putnbr(nbr);
}

void		ft_print_pw_name(char *str)
{
	int		i;
	int		f;

	i = ft_strlen(str);
	f = g_size2;
	while (f > i)
	{
		ft_putstr(" ");
		f--;
	}
	ft_putstr(str);
}

void		ft_open_dir_error(t_ls **elem)
{
	t_ls	*ptr;

	ptr = *elem;
	if (ptr->next != NULL || ptr->prev != NULL)
	{
		ft_putstr_fd(ft_strjoin("\n", ft_strjoin("./", ptr->name)), 2);
		ft_putstr_fd(":\n", 2);
	}
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd((ft_strjoin(ptr->name, ": ")), 2);
	ft_putstr_fd(ft_strjoin(strerror(errno), "\n"), 2);
}
