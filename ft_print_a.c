/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:53:29 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 15:59:21 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void            ft_go_sub_argv(tl_list **elem, int x)
{
    DIR         *dir;
    tl_list     *ptr;
    
    ptr = *elem;
    if(ft_strcmp(ptr->name, ".") == 0)
    {
        if(cont > 1 || r_up == 1)
        {
            if(suka > 0)
                ft_putstr("\n");
            else
                suka++;
            ft_putstr(ft_strjoin(ptr->sub->path + 2,":\n"));
        }
        if(ptr->sub != NULL)
        {
            if (r == 1)
            ft_emthy_ls_with_r(&ptr->sub);
            else
            ft_emthy_ls(&ptr->sub);
        }
    }
    else if((dir = opendir(ptr->name)) == NULL)
        ft_open_dir_error(&ptr);
    else
    {
    if((cont > 1 || r_up == 1 || argc_num > 1) && ptr->sub != NULL)
    {
        if(suka > 0)
            ft_putstr("\n");
        else
            suka++;
        if(*((char*)ptr->name) == '/')
            ft_putstr(ft_strjoin(ptr->sub->path,":\n"));
        else
        {
            if(l == 0 && ft_is_dir(ft_linkname(&ptr)) == 0 &&
            (ft_is_link(ft_strjoin_ls(ptr->path, ptr->name)) == 1 ||
            ft_is_link(ptr->name) == 1))
                ft_putstr(ft_strjoin(ptr->name,":\n"));
            else if(ft_lslen(&ptr->sub) > 0 || (cont != x || x > 1 || argc_num > 1))
                ft_putstr(ft_strjoin(ptr->sub->path + 2,":\n"));
        }
    }
    if(ptr->sub != NULL)
        {
            if (r == 1)
            ft_emthy_ls_with_r(&ptr->sub);
            else
            ft_emthy_ls(&ptr->sub);
        }
    }
}

void            ft_emthy_argv(tl_list **list)
{
    tl_list     *ptr;

    ptr = *list;
    x = 0;
    y = 0;
    if (l == 1)
		ft_size_ls(&ptr);
	x = ft_argv_scrol(&ptr);
	if(x > 0)
    {
        while(ptr)
        {
            if(ptr->type == 0)
                ft_go_sub_argv(&ptr, x);
            ptr= ptr->next;
        }
    }
}

void			ft_first_part(tl_list **elem)
{
	tl_list *all_list;

	all_list = *elem;
	is_link = 0;
	if (l == 1)
	{
		if(*((char*)all_list->name) == '/')
			ft_print_l(all_list->name);
		else
			ft_print_l(ft_strjoin_ls(all_list->path, all_list->name));
	}
	ft_putstr(all_list->name);
	if(is_link == 1)
	{
		ft_putstr(" -> ");
		ft_putendl(ft_linkname(&all_list));
	}
	else
		ft_putstr("\n");
}

void            ft_emthy_argv_with_r(tl_list **list)
{
    tl_list     *all_list;
    tl_list     *ptr;

    all_list = *list;
    y = 0;
    if (l == 1)
		ft_size_ls(&all_list);
    while(all_list->next != NULL)
        all_list= all_list->next;
    ptr = *list;
	x = ft_argv_scrol(&all_list);
    if(x > 0)
    {
        while(ptr)
        {
            if(ptr->type == 0)
                ft_go_sub_argv(&ptr, x);
            ptr= ptr->prev;
        }
    }
}
