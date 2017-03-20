/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:44:49 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 11:37:37 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int			main(int argc, char **argv)
{
	/*clock_t begin = clock();*/
	int		j;

	j = 0;
	argc_num = argc - 1;
	if (argc > 1)
	{
		ft_set_char();
		while (argv[++j])
		{
			if (argv[j][0] == '-' && (ft_strlen(argv[j]) != 1) &&
					(ft_strcmp(argv[j], "--") != 0) && ft_access(argv[j]) == 0)
			{
				if (ft_check(argv[j]) == 1)
					return (1);
				argc_num--;
			}
		}
		if(argc_num > 0)
			ft_argv_list_main(argv);
		else
			ft_execute(".");
	}
	else
		ft_execute(".");
	/*clock_t end = clock();
	printf("Elapsed: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);*/
	if (er_ck == 1)
		return (1);
	return (0);
}

void			ft_set_char()
{
	l = 0;
	a = 0;
	r = 0;
	t = 0;
	r_up = 0;
	er_ck = 0;
}

void		ft_argv_list_main(char **ar)
{
	tl_list *argv_list;
	int		j;
	int		c;

	j = 0;
	c = 0;
	argv_list = NULL;
	while (ar[++j] && argc_num != 0)
		if (ar[j][0] != '-' || (ar[j][0] == '-' && (ft_strlen(ar[j]) == 1)) ||
				(ar[j][0] == '-' && ar[j][1] == '-') || (ft_access(ar[j]) != 0))
		{
			if (ft_strcmp(ar[j], "--") == 0 && c == 0 && argv_list == NULL)
			{
				c++;
				argc_num--;
			}
			else if (argv_list == NULL)
				argv_list = ft_cr_argv(ar[j], ".");
			else
				argv_list = list_argv(&argv_list, ar[j]);
		}
	if (argc_num > 0 && er_ck == 0)
		ft_check_argv(&argv_list);
	else if (er_ck == 0)
		ft_execute(".");
}

tl_list		*ft_cr_argv(char *str, char *path)
{
	tl_list	*elem;

	elem = (tl_list*)malloc(sizeof(tl_list));
	if (elem == NULL)
		return (NULL);
	elem->name = ft_strdup(str);
	elem->path = ft_strdup(path);
	elem->sub = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void		ft_execute(char *str)
{
	tl_list	*all_list;

	all_list = ft_just_ls(str);
	if (r == 1)
		ft_emthy_ls_with_r(&all_list);
	else
		ft_emthy_ls(&all_list);
}
