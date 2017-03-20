/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:28:15 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 21:27:44 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*dircontets(DIR *dirp)
{
	t_list			*list;
	struct dirent	*dp;

	list = NULL;
	while ((dp = readdir(dirp)))
	{
		if (!g_opt.a && dp->d_name[0] == '.')
		{
			if (g_opt.a_up)
			{
				if (ft_strcmp(dp->d_name, ".") == 0 ||
						ft_strcmp(dp->d_name, "..") == 0)
					continue;
			}
			else
				continue;
		}
		ft_push(&list, dp->d_name, dp->d_reclen + 1);
	}
	return (list);
}

void	checkarg(t_list **entries)
{
	t_list		*temp;
	t_list		*prev;
	struct stat	buf;

	temp = *entries;
	while (temp)
	{
		if (lstat((char *)temp->content, &buf) == -1)
		{
			print_arg_err(temp);
			ft_del_node(entries, &temp, &prev);
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}

void	print_arg_err(t_list *list)
{
	g_errflag = 1;
	ft_putstr_fd("ls: ", 2);
	if ((char *)list->content == NULL ||
			ft_strcmp("''", (char *)list->content) == 0 ||
			ft_strcmp("""", (char *)list->content) == 0)
		errexit("fts_open");
	else
		perror((char *)list->content);
}

void	ft_del_node(t_list **head, t_list **curr, t_list **prev)
{
	if (*curr == *head)
	{
		*curr = (*curr)->next;
		*head = *curr;
	}
	else
	{
		(*prev)->next = (*curr)->next;
		free(*curr);
		*curr = (*prev)->next;
	}
}
