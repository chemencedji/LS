/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:44:02 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 14:32:13 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void				ft_add_elem(tl_list **ptr_r, tl_list **ret_r)
{
	tl_list			*p;
	tl_list			*ret;
	tl_list			*ck;

	p = *ptr_r;
	ret = *ret_r;
	if ((t == 0 && ft_strcmp(p->name, ret->name) >= 0) || (t == 1 &&
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
	{
		ret->next = p->next;
		ret->prev = p;
		p->next = ret;
		ck = ret->next;
		if (ret->next != NULL)
			ck->prev = ret;
	}
}

tl_list				*list_create(tl_list **begin_list, char *n, char *str)
{
	tl_list			*ret;
	tl_list			*no;
	tl_list			*ptr;

	ptr = *begin_list;
	no = *begin_list;
	u = 0;
	ret = ft_cr_alist(n, str);
	if (ret == NULL)
		return (NULL);
	if (t == 1)
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

tl_list				*ft_just_ls(char *str)
{
	tl_list			*all_list;
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(str);
	if (dir == NULL)
		return (NULL);
	all_list = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		u = 0;
		if (all_list == NULL)
			all_list = ft_cr_alist(sd->d_name, str);
		else
			all_list = list_create(&all_list, sd->d_name, str);
	}
	closedir(dir);
	return (all_list);
}

tl_list				*ft_just_ls_ar(char *str)
{
	tl_list			*all_list;
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(str);
	all_list = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		u = 0;
		if (all_list == NULL)
			all_list = ft_cr_alist(sd->d_name, str);
		else
			all_list = list_create_ar(&all_list, sd->d_name, str);
	}
	closedir(dir);
	return (all_list);
}

tl_list				*ft_cr_alist(char *name, char *str)
{
	tl_list			*e;
	int				i;
	struct timespec	pt;

	i = 0;
	e = ft_cr_argv(name, str);
	if (e == NULL)
		return (NULL);
	e->type = ft_is_dir(ft_strjoin_ls(e->path, e->name));
	if (e->type == 0 && (r_up == 1 || u == 0) &&
		ft_is_link(ft_strjoin_ls(e->path, e->name)) != 1 &&
		(!(ft_strcmp(e->name, ".") == 0 || ft_strcmp(e->name, "..") == 0)))
	{
		if (*((char*)(e->path + (i - 1))) == '/')
		{
			i = ft_strlen(e->path);
			*((char*)(e->path + (i - 1))) = '\0';
		}
		e->sub = ft_just_ls(ft_strjoin_ls(e->path, e->name));
		if (r_up != 1)
			u = 1;
	}
	if (t == 1)
	{
		pt = get_stat(ft_strjoin_ls(e->path, e->name)).st_mtimespec;
		e->tv_sec = pt.tv_sec;
		e->tv_nsec = pt.tv_nsec;
	}
	return (e);
}
