/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:53:29 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:05:16 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void			ft_go_sub_argv(tl_list **elem, int x)
{
	DIR			*dir;
	tl_list		*ptr;

	ptr = *elem;
	if (ft_strcmp(ptr->name, ".") == 0)
	{
		if ((g_cont > 1 || g_r_up == 1 || g_argc_num > 1) && ptr->sub != NULL)
		{
			if (g_suka > 0)
				ft_putstr("\n");
			else
				g_suka++;
			ft_putstr(ft_strjoin(ptr->sub->path + 2, ":\n"));
		}
		if (ptr->sub != NULL)
			ft_go_sub_print(&ptr);
	}
	else if ((dir = opendir(ptr->name)) == NULL)
		ft_open_dir_error(&ptr);
	else
		ft_argv_else(&ptr, x);
}

void			ft_emthy_argv(tl_list **list)
{
	tl_list		*ptr;

	ptr = *list;
	g_x = 0;
	g_y = 0;
	g_cont = 0;
	g_suka = 0;
	if (g_l == 1)
		ft_size_ls(&ptr);
	g_x = ft_argv_scrol(&ptr);
	if (g_x > 0)
	{
		while (ptr)
		{
			if (ptr->type == 0)
				ft_go_sub_argv(&ptr, g_x);
			ptr = ptr->next;
		}
	}
}

void			ft_first_part(tl_list **elem)
{
	tl_list *all_list;

	all_list = *elem;
	g_is_link = 0;
	if (g_l == 1)
	{
		if (*((char*)all_list->name) == '/')
			ft_print_l(all_list->name);
		else
			ft_print_l(ft_strjoin_ls(all_list->path, all_list->name));
	}
	ft_putstr(all_list->name);
	if (g_is_link == 1)
	{
		ft_putstr(" -> ");
		ft_putendl(ft_linkname(&all_list));
	}
	else
		ft_putstr("\n");
	g_suka++;
}

void			ft_emthy_argv_with_r(tl_list **list)
{
	tl_list		*all_list;
	tl_list		*ptr;

	all_list = *list;
	g_x = 0;
	g_y = 0;
	g_cont = 0;
	g_suka = 0;
	if (g_l == 1)
		ft_size_ls(&all_list);
	while (all_list->next != NULL)
		all_list = all_list->next;
	ptr = *list;
	g_x = ft_argv_scrol_r(&all_list);
	if (g_x > 0)
	{
		while (ptr)
		{
			if (ptr->type == 0)
				ft_go_sub_argv(&ptr, g_x);
			ptr = ptr->prev;
		}
	}
}
