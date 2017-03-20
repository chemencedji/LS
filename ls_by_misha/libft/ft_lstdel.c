/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:12:53 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/26 17:25:57 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *to_free;

	while (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		to_free = (*alst);
		*alst = (*alst)->next;
		free(to_free);
		to_free = NULL;
	}
}
