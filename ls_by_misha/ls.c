/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:30:51 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 19:49:33 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *dir)
{
	static t_list	*stack;
	static int		f;
	DIR				*dirp;

	g_dir = dir;
	if (g_opt.r_up && f)
	{
		ft_putstr(g_dir);
		ft_putendl(":");
	}
	f = 1;
	dirp = opendir(g_dir);
	if (dirp == NULL)
		print_opendir_err();
	else
	{
		display_file(&stack, dircontets(dirp));
		closedir(dirp);
	}
	if (g_opt.r_up == 1 && stack != NULL)
	{
		write(1, "\n", 1);
		ft_ls((char *)ft_pop(&stack));
	}
	f = 0;
}

void	print_opendir_err(void)
{
	ft_putstr("ls: ");
	if (ft_strrchr(g_dir, '/') == NULL)
		perror(g_dir);
	else
		perror(ft_strrchr(g_dir, '/') + 1);
}

void	display_file(t_list **stack, t_list *list)
{
	t_list *entries;
	t_list *temp;

	entries = NULL;
	if ((g_opt.l || g_opt.g) && (list != NULL) && !g_opt.l1)
	{
		ft_putstr("total ");
		ft_putnbr(ft_offset(g_dir, list));
		write(1, "\n", 1);
	}
	sortlist(&list, &func_sort);
	print_file(&entries, list);
	while (entries)
	{
		temp = entries->next;
		ft_lstadd(stack, entries);
		entries = temp;
	}
}

void	print_file(t_list **entries, t_list *list)
{
	char	*path;
	t_list	*tofree;
	size_t	len;

	len = ft_strlen(g_dir);
	while (list)
	{
		path = ft_pathjoin(g_dir, (char *)list->content);
		if ((g_opt.l || g_opt.g) && !g_opt.l1)
			print_stat(path);
		printname((char *)list->content, path);
		if (g_opt.r_up == 1 && is_dir(path)
				&& ft_strcmp((char *)list->content, ".")
				&& ft_strcmp((char *)list->content, ".."))
			ft_push(entries, path, len + list->content_size + 1);
		free(path);
		tofree = list;
		list = list->next;
		free(tofree->content);
		free(tofree);
	}
}
