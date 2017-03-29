/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:48:27 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:08:07 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void				ft_add_help(t_ls **ptr_r, t_ls **ret_r)
{
	t_ls			*p;
	t_ls			*ret;
	t_ls			*ck;

	p = *ptr_r;
	ret = *ret_r;
	ret->next = p->next;
	ret->prev = p;
	p->next = ret;
	ck = ret->next;
	if (ret->next != NULL)
		ck->prev = ret;
}

void				ft_go_sub_print(t_ls **elem)
{
	t_ls			*ptr;

	ptr = *elem;
	if (g_r == 1)
		ft_emthy_ls_with_r(&ptr->sub);
	else
		ft_emthy_ls(&ptr->sub);
}

void				ft_argv_else(t_ls **elem, int x)
{
	t_ls			*ptr;

	ptr = *elem;
	if ((g_cont > 1 || g_r_up == 1 || g_argc_num > 1) && ptr->sub != NULL)
	{
		if (g_suka > 0)
			ft_putstr("\n");
		else
			g_suka++;
		if (*((char*)ptr->name) == '/')
			ft_putstr(ft_strjoin(ptr->sub->path, ":\n"));
		else
		{
			if (g_l == 0 && ft_is_dir(ft_linkname(&ptr)) == 0 &&
				(ft_is_link(ft_strjoin_ls(ptr->path, ptr->name)) == 1 ||
				ft_is_link(ptr->name) == 1))
				ft_putstr(ft_strjoin(ptr->name, ":\n"));
			else if (ft_lslen(&ptr->sub) > 0 || (g_cont != x || x > 1 ||
						g_argc_num > 1))
				ft_putstr(ft_strjoin(ptr->sub->path + 2, ":\n"));
		}
	}
	if (ptr->sub != NULL)
		ft_go_sub_print(&ptr);
}

int					ft_argv_scrol_r(t_ls **list)
{
	int				x;
	t_ls			*a;
	DIR				*dir;

	x = 0;
	a = *list;
	while (a)
	{
		if (g_l == 0 && ft_is_dir(ft_linkname(&a)) == 0 &&
				(ft_is_link(ft_strjoin_ls(a->path, a->name)) == 1 ||
				ft_is_link(a->name) == 1))
			x++;
		else if (a->type == 0 && (a->sub != NULL ||
				(dir = opendir(a->name)) == NULL) &&
				(!(ft_is_link(ft_strjoin_ls(a->path, a->name)) == 1 ||
				ft_is_link(a->name) == 1)))
			x++;
		else if (*((char*)a->name) == '.' && a == 0)
			a = a->prev;
		else
			ft_first_part(&a);
		a = a->prev;
		g_cont++;
	}
	return (x);
}

int					ft_lslen(t_ls **list)
{
	int				i;
	t_ls			*ptr;

	ptr = *list;
	i = 0;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, ".") == 0 || ft_strcmp(ptr->name, "..") == 0)
			ptr = ptr->next;
		else
		{
			if (ptr->type == 0)
				i++;
			ptr = ptr->next;
		}
	}
	return (i);
}
