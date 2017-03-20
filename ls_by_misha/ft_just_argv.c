/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:45:19 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 14:23:54 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

tl_list				*ft_just_argv(tl_list **list)
{
	tl_list			*ptr;
	tl_list			*all_list;

	ptr = *list;
	all_list = NULL;
	while (ptr)
	{
		if (all_list == NULL)
			all_list = ft_cr_argvlist(ptr->name, ".");
		else
			all_list = list_create_ar(&all_list, ptr->name, ".");
		ptr = ptr->next;
	}
	return (all_list);
}

tl_list				*ft_cr_argvlist(char *name, char *str)
{
	tl_list			*elem;
	struct timespec	pt;

	elem = ft_cr_argv(name, str);
	if (elem == NULL)
		return (NULL);
	elem->type = ft_is_dir(ft_strjoin_ls(elem->path, elem->name));
	if (elem->type == 0 && (r_up == 1 || u == 0))
	{
		if (l == 0 && ft_link_dir(elem) == 0 &&
				(ft_is_link(ft_strjoin_ls(elem->path, elem->name)) == 1 ||
				ft_is_link(elem->name) == 1))
			elem->sub = ft_just_ls(ft_linkname(&elem));
		else if (*((char*)elem->name) == '/')
			elem->sub = ft_just_ls(elem->name);
		else
			elem->sub = ft_just_ls(ft_strjoin_ls(elem->path, elem->name));
		if (r_up != 1)
			u = 1;
	}
	if (t == 1)
	{
		pt = get_stat(ft_strjoin_ls(elem->path, elem->name)).st_mtimespec;
		elem->tv_sec = pt.tv_sec;
		elem->tv_nsec = pt.tv_nsec;
	}
	return (elem);
}

char				*ft_linkname(tl_list **elem)
{
	tl_list			*p;
	char			*name;
	ssize_t			r;
	struct stat		buf;

	p = *elem;
	if (*((char*)p->name) == '/')
		buf = get_stat(p->name);
	else
		buf = get_stat(ft_strjoin_ls(p->path, p->name));
	name = malloc(buf.st_size + 1);
	if (*((char*)p->name) == '/')
		r = readlink(p->name, name, buf.st_size + 1);
	else
		r = readlink(ft_strjoin_ls(p->path, p->name), name, buf.st_size + 1);
	name[r] = '\0';
	return (name);
}

tl_list				*list_create_ar(tl_list **begin_list, char *n, char *str)
{
	tl_list			*ret;
	tl_list			*ptr;

	ptr = *begin_list;
	ret = ft_cr_argvlist(n, str);
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

tl_list				*return_tlist(tl_list **p, tl_list **b, tl_list **r)
{
	tl_list			*ptr;
	tl_list			*ret;

	ptr = *p;
	ret = *r;
	if (ptr == *b)
	{
		if (ret->next == NULL && ptr->prev == NULL)
			return (ptr);
		return (ret);
	}
	return (*b);
}
