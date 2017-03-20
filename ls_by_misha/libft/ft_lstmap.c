/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:13:32 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/26 20:11:20 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *temp;
	t_list *last;
	t_list *head;

	last = NULL;
	while (lst)
	{
		new_lst = ft_lstnew(NULL, 0);
		temp = (*f)(lst);
		new_lst->content = temp->content;
		new_lst->content_size = temp->content_size;
		if (!last)
			head = new_lst;
		else
			last->next = new_lst;
		last = new_lst;
		new_lst->next = NULL;
		lst = lst->next;
	}
	return (head);
}
