/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:18:21 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 22:34:37 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsopt	g_opt;
char	*g_dir;
t_bool	g_errflag = 0;
int		g_off1;
int		g_off2;
int		g_off3;
int		g_off4;

int		main(int argc, char **argv)
{
	t_list	*arg;
	int		n;

	arg = NULL;
	g_dir = ".";
	n = is_valide_argv(&arg, argc, argv);
	if (argc == 1 || !n)
		ft_ls(g_dir);
	ft_printdirs(&arg, ft_printfiles(&arg));
	return (0);
}

t_bool	ft_printfiles(t_list **arg)
{
	t_list *head;
	t_list *list;
	t_bool flag;

	head = *arg;
	list = NULL;
	flag = 0;
	while (head)
	{
		if (!is_dir((char *)head->content) &&
				!is_dir_link((char *)head->content))
		{
			ft_push(&list, head->content, head->content_size);
			flag = 1;
		}
		head = head->next;
	}
	sortlist(&list, &func_sort);
	if (g_opt.l)
		ft_offset(".", list);
	printfiles(list);
	return (flag);
}

void	printfiles(t_list *list)
{
	while (list)
	{
		if (g_opt.l)
			print_stat((char *)list->content);
		printname((char *)list->content, (char *)list->content);
		list = list->next;
	}
}

void	ft_printdirs(t_list **arg, t_bool flag)
{
	int n;

	n = ft_nrdirs(*arg);
	if (g_opt.t)
		sortlist(arg, &func_sort);
	while (*arg)
	{
		if (is_dir((char *)(*arg)->content) ||
				is_dir_link((char *)(*arg)->content))
		{
			if (flag == 1 || n > 1 || g_errflag)
			{
				if (flag == 1)
					write(1, "\n", 1);
				else
					flag = 1;
				ft_putstr((char *)(*arg)->content);
				ft_putendl(":");
			}
			ft_ls((char *)(*arg)->content);
		}
		*arg = (*arg)->next;
	}
}

int		ft_nrdirs(t_list *list)
{
	int n;

	n = 0;
	while (list)
	{
		if (is_dir((char *)list->content) || is_dir_link((char *)list->content))
			n++;
		if (n > 1)
			return (n);
		list = list->next;
	}
	return (0);
}
