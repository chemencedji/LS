/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:24:31 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 22:38:13 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pop(t_list **stack)
{
	t_list	*temp;
	void	*data;

	data = (void *)malloc((*stack)->content_size);
	if (data == NULL)
		return (NULL);
	ft_memcpy(data, (*stack)->content, (*stack)->content_size);
	temp = (*stack)->next;
	free((*stack)->content);
	free(*stack);
	(*stack) = temp;
	return (data);
}
