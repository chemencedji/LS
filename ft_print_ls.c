/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:31:07 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:03:48 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void		ft_total(t_ls **all)
{
	ft_putstr("total ");
	ft_putnbr(ft_block_size(all));
	ft_putstr("\n");
	ft_size_ls(all);
}

void		ft_go_sub_list(t_ls **elem)
{
	t_ls	*ptr;
	DIR		*dir;

	ptr = *elem;
	if ((dir = opendir(ptr->name)) == NULL && ptr->sub == NULL)
		ft_open_dir_error(&ptr);
	else if (ptr->sub != NULL)
	{
		ft_putstr("\n");
		if (g_r == 1)
			ft_emthy_ls_with_r(&ptr->sub);
		else
			ft_emthy_ls(&ptr->sub);
	}
}

void		ft_emthy_ls(t_ls **list)
{
	t_ls *ptr;

	ptr = *list;
	ft_name(list);
	ft_list_scrol(list);
	while (ptr && g_r_up == 1)
	{
		if (ptr->type == 0)
		{
			if (*((char*)ptr->name) == '.' && g_a == 0)
				ptr = ptr->next;
			else if (!(ft_strcmp(ptr->name, ".") == 0 ||
						ft_strcmp(ptr->name, "..") == 0))
			{
				ft_go_sub_list(&ptr);
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		else
			ptr = ptr->next;
	}
}

void		ft_emthy_ls_with_r(t_ls **list)
{
	t_ls *ptr;

	ptr = *list;
	ft_name(list);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ft_list_scrol(&ptr);
	while (ptr && g_r_up == 1)
	{
		if (ptr->type == 0)
		{
			if (*((char*)ptr->name) == '.' && g_a == 0)
				ptr = ptr->prev;
			else if (!(ft_strcmp(ptr->name, ".") == 0 ||
						ft_strcmp(ptr->name, "..") == 0))
			{
				ft_go_sub_list(&ptr);
				ptr = ptr->prev;
			}
			else
				ptr = ptr->next;
		}
		else
			ptr = ptr->prev;
	}
}

void		ft_name(t_ls **elem)
{
	t_ls	*all_list;

	all_list = *elem;
	if (g_r_up == 1)
	{
		if (g_z == 1)
			ft_putstr(ft_strjoin(all_list->path, ":\n"));
		g_z = 1;
	}
	if (g_l == 1)
		ft_total(elem);
}
