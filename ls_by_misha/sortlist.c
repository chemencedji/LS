/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:22:42 by mihail            #+#    #+#             */
/*   Updated: 2017/01/25 12:12:41 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortlist(t_list **list, int (*f)(t_list *, t_list *))
{
	t_list *head;
	t_list *middle;
	t_list *shalf;

	head = *list;
	if (!head || head->next == NULL)
		return ;
	middle = get_middle(head);
	shalf = middle->next;
	middle->next = NULL;
	sortlist(&head, f);
	sortlist(&shalf, f);
	*list = merge(head, shalf, f);
}

t_list	*merge(t_list *a, t_list *b, int (*f)(t_list *, t_list *))
{
	t_list *curr;
	t_list *c;

	curr = ft_lstnew(NULL, 0);
	c = curr;
	while (a && b)
	{
		if ((*f)(a, b))
		{
			curr->next = a;
			a = a->next;
		}
		else
		{
			curr->next = b;
			b = b->next;
		}
		curr = curr->next;
	}
	curr->next = (a == NULL) ? b : a;
	curr = c->next;
	free(c);
	return (curr);
}

t_list	*get_middle(t_list *head)
{
	t_list	*middle;
	int		n;

	middle = head;
	n = ft_list_size(head) / 2;
	while (--n)
		middle = middle->next;
	return (middle);
}
