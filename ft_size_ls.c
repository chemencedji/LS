/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:17:36 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 20:59:22 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void			ft_size_ls_s1(int nbr)
{
	int			d;

	d = 1;
	while (nbr /= 10)
		d++;
	if (d > g_size1)
		g_size1 = d;
}

void			ft_size_ls_s2(char *str)
{
	int			i;

	i = ft_strlen(str);
	if (i > g_size2)
		g_size2 = i;
}

void			ft_size_ls_s3(char *str)
{
	int			i;

	i = ft_strlen(str);
	if (i > g_size3)
		g_size3 = i;
}

void			ft_size_ls_s4(int nbr)
{
	int			d;

	d = 1;
	while (nbr /= 10)
		d++;
	if (d > g_size4)
		g_size4 = d;
}

void			ft_size_ls(tl_list **list)
{
	struct stat	pt;
	tl_list		*ptr;

	ptr = *list;
	g_size1 = 0;
	g_size2 = 0;
	g_size3 = 0;
	g_size4 = 0;
	while (ptr)
	{
		if (*((char*)ptr->name) == '.' && g_a == 0)
			ptr = ptr->next;
		else
		{
			if (*((char*)ptr->name) == '/')
				pt = get_stat(ptr->name);
			else
				pt = get_stat(ft_strjoin_ls(ptr->path, ptr->name));
			ft_size_ls_s1(pt.st_nlink);
			ft_size_ls_s2((getpwuid(pt.st_uid))->pw_name);
			ft_size_ls_s3((getgrgid(pt.st_gid))->gr_name);
			ft_size_ls_s4(pt.st_size);
			ptr = ptr->next;
		}
	}
}
