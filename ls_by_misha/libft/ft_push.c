/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:20:49 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 22:37:05 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(t_list **stack, void *data, size_t data_size)
{
	t_list *new_elem;

	new_elem = ft_lstnew(data, data_size);
	new_elem->next = (*stack);
	(*stack) = new_elem;
}
