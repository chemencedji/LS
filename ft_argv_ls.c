/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:24:37 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:24:20 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int			ft_check(char *s)
{
	int		i;

	i = 0;
	while (s[++i] != '\0')
	{
		if (ft_strchr("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", s[i]) == 0)
		{
			ft_putstr_fd(LS_INV, 2);
			ft_putchar_fd(s[i], 2);
			ft_putstr_fd(US, 2);
			g_argc_num++;
			return (1);
		}
		if (s[i] == 'l')
			g_l = 1;
		if (s[i] == 'R')
			g_r_up = 1;
		if (s[i] == 'a')
			g_a = 1;
		if (s[i] == 'r')
			g_r = 1;
		if (s[i] == 't')
			g_t = 1;
	}
	return (0);
}

tl_list		*list_argv(tl_list **begin_list, char *n)
{
	tl_list	*ret;
	tl_list	*ptr;

	ptr = *begin_list;
	ret = ft_cr_argv(n, ".");
	if (ret == NULL)
		return (NULL);
	while (ptr->next != NULL && (ft_strcmp(ptr->name, ret->name) <= 0))
		ptr = ptr->next;
	ft_add_elem(&ptr, &ret);
	return (return_tlist(&ptr, begin_list, &ret));
}

void		ft_check_argv(tl_list **list)
{
	tl_list	*ptr;

	ptr = *list;
	while (ptr)
	{
		if (ft_access(ptr->name) == 0)
		{
			ft_putstr_fd(ft_strjoin(ft_strjoin("ls: ", ptr->name), ": "), 2);
			ft_putstr_fd(ft_strjoin(strerror(errno), "\n"), 2);
			if (ptr->prev == NULL && ptr->next == NULL)
			{
				free(ptr);
				return ;
			}
			else
				ft_sort_for_ck_ar(&ptr, list);
		}
		if (ptr->next == NULL)
			break ;
		ptr = ptr->next;
	}
	if (ptr && g_er_ck == 0)
		ft_execute_argv(list);
}

void		ft_execute_argv(tl_list **list)
{
	tl_list	*ptr;

	ptr = ft_just_argv(list);
	if (g_l == 1)
		ft_size_ls(&ptr);
	if (g_r == 1)
		ft_emthy_argv_with_r(&ptr);
	else
		ft_emthy_argv(&ptr);
}

void		ft_sort_for_ck_ar(tl_list **elem, tl_list **list)
{
	tl_list *ptr;
	tl_list *su;
	tl_list *ck;

	ptr = *elem;
	if (ptr->prev == NULL)
	{
		ck = ptr->next;
		ck->prev = NULL;
		*list = ck;
		ptr = *list;
	}
	else if (ptr->prev != NULL)
	{
		ck = ptr->prev;
		su = ptr->next;
		if (ptr->next != NULL)
		{
			ck->next = su;
			su->prev = ck;
		}
		else
			ck->next = NULL;
	}
}
