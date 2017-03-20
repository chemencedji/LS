/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_a_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:32:43 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 15:52:59 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int			ft_argv_scrol(tl_list **list)
{
	int		x;
	tl_list *a;
	DIR		*dir;

	x = 0;
	cont = 0;
	suka = 0;
	a = *list;
	while(a)
	{
		if(l == 0 && ft_is_dir(ft_linkname(&a)) == 0 &&
			(ft_is_link(ft_strjoin_ls(a->path, a->name)) == 1 ||
			 ft_is_link(a->name) == 1))
			x++;
		else if(a->type == 0 && (a->sub != NULL ||
				(dir = opendir(a->name)) == NULL) &&
				(!(ft_is_link(ft_strjoin_ls(a->path, a->name)) == 1 ||
				   ft_is_link(a->name) == 1)))
			x++;
		else if(*((char*)a->name) == '.' && a == 0)
		{
			if(r == 1)
				a = a->prev;
			else
				a = a->next;
		}
		else
		{
			ft_first_part(&a);
			suka++;
		}
		if (r == 1)
			a = a->prev;
		else
			a = a->next;
		cont++;
	}
	return (x);
}

void		ft_list_scrol(tl_list **list)
{
	tl_list	*all_list;

	all_list = *list;
	while(all_list)
	{
		if(*((char*)all_list->name) == '.' && a == 0)
		{
			if(r == 1)
				all_list = all_list->prev;
			else
				all_list = all_list->next;
		}
		else
		{
			ft_first_part(&all_list);
			if(r == 1)
				all_list = all_list->prev;
			else
				all_list = all_list->next;
		}
	}
}

void		ft_print_gr_name(char *str)
{
		int i;
			int f;
				
				i = ft_strlen(str);
					f = size3;
						while(f > i)
								{
											ft_putstr(" ");
													f--;
														}
							ft_putstr(str);
}

void		ft_print_st_size(int nbr)
{
	int i;
	int f;
	
	i = ndigits(nbr);
	f = size4;
	while(f > i)
	{
		ft_putstr(" ");
		f--;
	}
	ft_putnbr(nbr);
}

void	ft_printtime(time_t mtime)
{
	char	*stime;
	char	*year;

	stime = ft_strchr(ctime(&mtime), ' ');
	if (time(NULL) < mtime || (time(NULL) - mtime) > SIXMONTH)
	{
		year = ft_strrchr(stime, ' ');
		*(ft_strchr(stime, '\n')) = '\0';
		stime[8] = '\0';
		ft_putstr(stime);
		ft_putstr(year);
	}
	else
	{
		*(ft_strrchr(stime, ':')) = '\0';
		ft_putstr(stime);
	}
	write(1, " ", 1);
}