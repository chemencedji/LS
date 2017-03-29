/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:44:02 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 20:53:01 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void				ft_add_elem(t_ls **ptr_r, t_ls **ret_r)
{
	t_ls			*p;
	t_ls			*ret;
	t_ls			*ck;

	p = *ptr_r;
	ret = *ret_r;
	if ((g_t == 0 && ft_strcmp(p->name, ret->name) >= 0) || (g_t == 1 &&
		(((ret->tv_sec) > (p->tv_sec)) || ((ret->tv_sec) == (p->tv_sec) &&
		(ret->tv_nsec) > (p->tv_nsec)) || ((ret->tv_sec) == (p->tv_sec) &&
		(ret->tv_nsec) == (p->tv_nsec) && ft_strcmp(p->name, ret->name) >= 0))))
	{
		ret->prev = p->prev;
		ret->next = p;
		p->prev = ret;
		ck = ret->prev;
		if (ret->prev != NULL)
			ck->next = ret;
	}
	else
		ft_add_help(ptr_r, ret_r);
}

t_ls				*list_create(t_ls **begin_list, char *n, char *str)
{
	t_ls			*ret;
	t_ls			*ptr;

	ptr = *begin_list;
	g_u = 0;
	ret = ft_cr_alist(n, str);
	if (ret == NULL)
		return (NULL);
	if (g_t == 1)
	{
		while (ptr->next != NULL && ((ret->tv_sec < ptr->tv_sec) ||
				(ret->tv_sec == ptr->tv_sec && ret->tv_nsec < ptr->tv_nsec) ||
				(ret->tv_sec == ptr->tv_sec && ret->tv_nsec == ptr->tv_nsec &&
				(ft_strcmp(ptr->name, ret->name) <= 0))))
			ptr = ptr->next;
	}
	else
	{
		while (ptr->next != NULL && (ft_strcmp(ptr->name, ret->name) <= 0))
			ptr = ptr->next;
	}
	ft_add_elem(&ptr, &ret);
	return (return_tlist(&ptr, begin_list, &ret));
}

t_ls				*ft_just_ls(char *str)
{
	t_ls			*all_list;
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(str);
	if (dir == NULL)
		return (NULL);
	all_list = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		if (all_list == NULL)
			all_list = ft_cr_alist(sd->d_name, str);
		else
			all_list = list_create(&all_list, sd->d_name, str);
	}
	closedir(dir);
	return (all_list);
}

t_ls				*ft_just_ls_ar(char *str)
{
	t_ls			*all_list;
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(str);
	all_list = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		if (all_list == NULL)
			all_list = ft_cr_alist(sd->d_name, str);
		else
			all_list = list_create_ar(&all_list, sd->d_name, str);
	}
	closedir(dir);
	return (all_list);
}

t_ls				*ft_cr_alist(char *name, char *str)
{
	t_ls			*e;
	int				i;

	i = 0;
	e = ft_cr_argv(name, str);
	if (e == NULL)
		return (NULL);
	e->type = ft_is_dir(ft_strjoin_ls(e->path, e->name));
	if (e->type == 0 && (g_r_up == 1 || g_u == 0) &&
		ft_is_link(ft_strjoin_ls(e->path, e->name)) != 1 &&
		(!(ft_strcmp(e->name, ".") == 0 || ft_strcmp(e->name, "..") == 0)))
	{
		if (g_r_up != 1)
			g_u = 1;
		if (*((char*)(e->path + (i - 1))) == '/')
		{
			i = ft_strlen(e->path);
			*((char*)(e->path + (i - 1))) = '\0';
		}
		e->sub = ft_just_ls(ft_strjoin_ls(e->path, e->name));
	}
	if (g_t == 1)
		ft_set_time(&e);
	return (e);
}
