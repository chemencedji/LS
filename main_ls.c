/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:44:49 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:26:35 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int	g_l;
int	g_r_up;
int	g_a;
int	g_r;
int	g_t;
int	g_z;
int	g_x;
int	g_u;
int	g_argc_num;
int	g_errno;
int	g_er_ck;
int	g_is_link;
int	g_cont;
int	g_suka;
int	g_size1;
int	g_size2;
int	g_size3;
int	g_size4;

int				main(int argc, char **argv)
{
	int			j;

	j = 0;
	g_argc_num = argc - 1;
	if (argc > 1)
	{
		ft_set_char();
		while (argv[++j])
			if (argv[j][0] == '-' && (ft_strlen(argv[j]) != 1) &&
					(ft_strcmp(argv[j], "--") != 0) && ft_access(argv[j]) == 0)
			{
				if (ft_check(argv[j]) == 1)
					return (1);
				g_argc_num--;
			}
		if (g_argc_num > 0)
			ft_argv_list_main(argv);
		else
			ft_execute(".");
	}
	else
		ft_execute(".");
	if (g_er_ck == 1)
		return (1);
	return (0);
}

void			ft_set_char(void)
{
	g_l = 0;
	g_a = 0;
	g_r = 0;
	g_t = 0;
	g_r_up = 0;
	g_er_ck = 0;
}

void			ft_argv_list_main(char **ar)
{
	t_ls		*argv_list;
	int			j;
	int			c;

	j = 0;
	c = 0;
	argv_list = NULL;
	while (ar[++j] && g_argc_num != 0)
		if (ar[j][0] != '-' || (ar[j][0] == '-' && (ft_strlen(ar[j]) == 1)) ||
				(ar[j][0] == '-' && ar[j][1] == '-') || (ft_access(ar[j]) != 0))
		{
			if (ft_strcmp(ar[j], "--") == 0 && c == 0 && argv_list == NULL)
			{
				c++;
				g_argc_num--;
			}
			else if (argv_list == NULL)
				argv_list = ft_cr_argv(ar[j], ".");
			else
				argv_list = list_argv(&argv_list, ar[j]);
		}
	if (g_argc_num > 0 && g_er_ck == 0)
		ft_check_argv(&argv_list);
	else if (g_er_ck == 0)
		ft_execute(".");
}

t_ls			*ft_cr_argv(char *str, char *path)
{
	t_ls		*elem;

	elem = (t_ls*)malloc(sizeof(t_ls));
	if (elem == NULL)
		return (NULL);
	elem->name = ft_strdup(str);
	elem->path = ft_strdup(path);
	elem->sub = NULL;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void			ft_execute(char *str)
{
	t_ls		*all_list;

	all_list = ft_just_ls(str);
	if (g_r == 1)
		ft_emthy_ls_with_r(&all_list);
	else
		ft_emthy_ls(&all_list);
}
