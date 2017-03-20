/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:25:57 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 21:38:43 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valide_argv(t_list **list, int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	init_opt();
	check_ls_opts(&i, argc, argv);
	while (i < argc)
	{
		n++;
		ft_push(list, argv[i], ft_strlen(argv[i]) + 1);
		i++;
	}
	if (g_opt.r)
	{
		g_opt.r = 0;
		sortlist(list, &lexsort);
		g_opt.r = 1;
	}
	else
		sortlist(list, &lexsort);
	checkarg(list);
	return (n);
}

void	check_ls_opts(int *i, int argc, char **argv)
{
	struct stat	buf;
	t_bool		flag;

	flag = 1;
	while (*i < argc && *argv[*i] == '-' && *(argv[*i] + 1))
	{
		if (flag && ft_strcmp(argv[*i], "--") == 0)
		{
			flag = 0;
			(*i)++;
			continue;
		}
		if (lstat(argv[*i], &buf) == -1)
			check_option(++argv[(*i)++]);
		else
			break ;
	}
}
