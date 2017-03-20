/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 20:41:30 by ichemenc          #+#    #+#             */
/*   Updated: 2016/10/24 20:59:54 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_new_map;
	t_list	*new_map;

	new_map = NULL;
	tmp_new_map = NULL;
	if (lst != NULL)
	{
		new_map = (*f)(ft_lstnew(lst->content, lst->content_size));
		tmp_new_map = new_map;
		lst = lst->next;
		while (lst)
		{
			tmp_new_map->next = f(ft_lstnew(lst->content, lst->content_size));
			tmp_new_map = tmp_new_map->next;
			lst = lst->next;
		}
	}
	return (new_map);
}
