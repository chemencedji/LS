/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:49:06 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 19:58:16 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	func_sort(t_list *a, t_list *b)
{
	if (g_opt.t)
		return (timesort(a, b));
	if (g_opt.s_up)
		return (sizesort(a, b));
	return (lexsort(a, b));
}

int	timesort(t_list *a, t_list *b)
{
	struct timespec time1;
	struct timespec time2;

	/*time1 = get_stat(ft_pathjoin(g_dir, (char *)a->content)).st_mtimespec;
	time2 = get_stat(ft_pathjoin(g_dir, (char *)b->content)).st_mtimespec;*/
	if (time1.tv_sec > time2.tv_sec ||
	(time1.tv_sec == time2.tv_sec && time1.tv_nsec > time2.tv_nsec) ||
	(time1.tv_sec == time2.tv_sec && time1.tv_nsec == time2.tv_nsec &&
	(ft_strcmp((char *)a->content, (char *)b->content) < 0)))
		return (!g_opt.r);
	return (g_opt.r);
}

int	lexsort(t_list *a, t_list *b)
{
	if (ft_strcmp((char *)a->content, (char *)b->content) < 0)
		return (!g_opt.r);
	return (g_opt.r);
}

int	sizesort(t_list *a, t_list *b)
{
	off_t size1;
	off_t size2;

	size1 = get_stat(ft_pathjoin(g_dir, (char *)a->content)).st_size;
	size2 = get_stat(ft_pathjoin(g_dir, (char *)b->content)).st_size;
	if ((size1 > size2) || (size1 == size2 &&
	(ft_strcmp((char *)a->content, (char *)b->content) < 0)))
		return (!g_opt.r);
	return (g_opt.r);
}
